#include "hash.h"
#include "lista.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


#define CAP_MIN 17


/* -----------------------------------------------------------------
                Estructuras del Hash y sus elementos
 * -----------------------------------------------------------------*/

struct hash
{
    lista_t** listas;
    hash_destruir_dato_t destruir_dato;
    size_t cantidad;
    size_t capacidad;
};


typedef struct elemento_hash{
    char* clave;
    void* dato;
} elemento_hash_t;


struct hash_iter{
    const hash_t* hash;
    size_t indice;
    lista_iter_t* iter_lista;
};


/* -----------------------------------------------------------------
                Funciones adicionales
 * -----------------------------------------------------------------*/

// char *strdup(const char *src) {
//     char *dst = malloc(strlen (src) + 1);  // Space for length plus nul
//     if (dst == NULL) return NULL;          // No memory
//     strcpy(dst, src);                      // Copy the characters
//     return dst;                            // Return the new string
// }

char *strdup(const char *clave) {
    char *clave_copia = strcpy(malloc(strlen(clave) + 1), clave);
    return clave_copia;
}




/* -----------------------------------------------------------------
             Funciones de Hashing
 * -----------------------------------------------------------------*/
size_t hashing(const char *clave, size_t tam){

    size_t hash = 5381;
    size_t c;

    while ((c = *(size_t*)clave++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % tam;

}


/* -----------------------------------------------------------------
             Primitivas del elemento
 * -----------------------------------------------------------------*/

elemento_hash_t* elemento_crear(char *clave, void* dato){
    //char* clave_cp =  strdup(clave);
    elemento_hash_t* elemento = malloc(sizeof(elemento_hash_t));
    if (elemento == NULL) return  NULL;

    elemento->clave = clave;
    elemento->dato = dato;
    // free(clave_cp); Esto rompe
    return elemento;

}


elemento_hash_t* elemento_en_lista(const hash_t *hash,const char *clave){

    size_t indice = hashing(clave, hash->capacidad);

    if (!hash->listas[indice] || lista_esta_vacia(hash->listas[indice])) return NULL;

    lista_iter_t* iterador = lista_iter_crear(hash->listas[indice]);
    if (!iterador) return NULL;

    elemento_hash_t* elemento = NULL;


    while (!lista_iter_al_final(iterador)){

        elemento = lista_iter_ver_actual(iterador);

        if (strcmp(elemento->clave, clave) == 0){
            break;
        }
        lista_iter_avanzar(iterador);
    }

    lista_iter_destruir(iterador);
    
    return elemento;
}


bool actualizar_elemento(hash_t* hash, const char* clave, void* dato_nuevo){
    elemento_hash_t* elemento = elemento_en_lista(hash, clave);
    if(!elemento) return false;
    
    if(hash->destruir_dato) hash->destruir_dato(elemento->dato);
    elemento->dato = dato_nuevo;
    return true;
    
}


/* -----------------------------------------------------------------
                Funciones adicionales de la tabla de HASH
 * -----------------------------------------------------------------*/

// Verifica si el hash está vacío
bool hash_esta_vacio(const hash_t* hash){
    if (hash->cantidad == 0) return true;
    return false;
}

bool hash_redimensionar(hash_t* hash){
    
    size_t tam_nuevo = hash->capacidad * CAP_MIN;


    hash_t* hash_nuevo = malloc(sizeof(hash_t));
    hash_nuevo->listas = malloc(tam_nuevo * sizeof(lista_t*));
    if (!hash_nuevo->listas)  return false;
    
    for (size_t i = 0; i < tam_nuevo; i++) hash_nuevo->listas[i] = NULL; 
    
    
    
    hash_nuevo->cantidad = hash->cantidad;
    hash_nuevo->capacidad = tam_nuevo;
    hash_nuevo->destruir_dato = hash->destruir_dato;

    for (size_t i = 0; i < hash->capacidad; i++){

        while (!lista_esta_vacia(hash->listas[i])){
            elemento_hash_t* elemento = lista_borrar_primero(hash->listas[i]);
            char* clave = elemento->clave;
            void* dato = elemento->dato;
            if (!hash_guardar(hash_nuevo, clave, dato)) return false;
        }
    }
    
    hash = hash_nuevo;
    
    return true;
}


/* -----------------------------------------------------------------
                Primitivas de la tabla de HASH
 * -----------------------------------------------------------------*/

hash_t *hash_crear(hash_destruir_dato_t destruir_dato){

    hash_t* hash = malloc(sizeof(hash_t));
    if (!hash) {
        free(hash);
        return NULL;
    }

    hash->listas = malloc(CAP_MIN * sizeof(lista_t*));
    if (!hash->listas) return NULL;

    for (size_t i = 0; i < CAP_MIN; i++) {
        hash->listas[i] = NULL;
    }

    hash->cantidad = 0;
    hash->capacidad = CAP_MIN;
    hash->destruir_dato = destruir_dato;

    return hash;
}


size_t hash_cantidad(const hash_t *hash){
    return hash->cantidad;
}


bool hash_guardar(hash_t *hash, const char *clave, void *dato){
    
    float carga = (float)hash->cantidad / (float)hash->capacidad;
    
    // NO TOCAR
    if (carga >= 1){
        if(!hash_redimensionar(hash)) return false;
    }
    
    size_t indice = hashing(clave, hash->capacidad);
    char* clave_cp =  strdup(clave);
    
    if (!hash->listas[indice]) hash->listas[indice] = lista_crear();
    
    if (!lista_esta_vacia(hash->listas[indice])){
        if(actualizar_elemento(hash, clave, dato)){
            free(clave_cp);
            return true;
        }
    }
    
    elemento_hash_t* elemento = elemento_crear(clave_cp, dato);
    if (elemento == NULL) return false;
    
    lista_insertar_primero(hash->listas[indice], elemento);
    hash->cantidad++;
   
    return true;
}


void *hash_obtener(const hash_t *hash, const char *clave){
    if (hash_esta_vacio(hash)) return NULL;
    elemento_hash_t* elemento = elemento_en_lista(hash, clave);
    if (!elemento) return NULL;
    void* dato = elemento->dato;
    return dato;
}



bool hash_pertenece(const hash_t *hash, const char *clave){
    if (hash_esta_vacio(hash)) return false;
    elemento_hash_t* elemento = elemento_en_lista(hash, clave);
    return (elemento);
}


void *hash_borrar(hash_t *hash, const char *clave){
    
    //if (hash_esta_vacio(hash)) return NULL; // Por si se vació

    size_t indice = hashing(clave, hash->capacidad);

    lista_iter_t* iterador = lista_iter_crear(hash->listas[indice]);
    if (!iterador) return NULL;

    elemento_hash_t* aux;
    void * dato = NULL;
    

    while (!lista_iter_al_final(iterador)){
        aux = lista_iter_ver_actual(iterador);

        if (strcmp(aux->clave, clave) == 0){
            lista_iter_borrar(iterador);
            hash->cantidad--;
            dato = aux->dato;
            free(aux->clave);
            free(aux);
            break;
        }
        lista_iter_avanzar(iterador);

    }

    lista_iter_destruir(iterador);

    if (lista_esta_vacia(hash->listas[indice])){
        lista_destruir(hash->listas[indice], NULL);
        hash->listas[indice] = NULL;
    } 

    return dato;
}


void hash_destruir(hash_t *hash){
    for (size_t i = 0; i < hash->capacidad; i++){
        if (hash->listas[i] != NULL){
            if(!hash->destruir_dato){
                lista_destruir(hash->listas[i], NULL);
            }else{
                while (!lista_esta_vacia(hash->listas[i])){
                    elemento_hash_t* elemento = lista_borrar_primero(hash->listas[i]);
                    hash->destruir_dato(elemento->dato);
                    free(elemento->clave);
                    free(elemento);
                }
                free(hash->listas[i]);
            }
        }
    }
    free(hash->listas);
    free(hash);
}

/* -----------------------------------------------------------------
                Funciones adicionales del iterador
 * -----------------------------------------------------------------*/

size_t iter_buscar_indice(const hash_t* hash, size_t indice_actual){
    
    for (size_t i = indice_actual; i < hash->capacidad; i++){
        if (hash->listas[i] != NULL){
            return i;
        }
    }
    return 0;
}


/* -----------------------------------------------------------------
                Primitidas del iterador
 * -----------------------------------------------------------------*/

hash_iter_t *hash_iter_crear(const hash_t *hash){
    
    if (!hash) return NULL;
    
    hash_iter_t* iter = malloc(sizeof(hash_iter_t));
    if (!iter) return NULL;

    iter->hash = hash;
    size_t inicial = 0;

    if (hash_esta_vacio(iter->hash)){
        iter->indice = inicial;
        iter->iter_lista = NULL;
    }else{
        iter->indice = iter_buscar_indice(hash, inicial);
        iter->iter_lista = lista_iter_crear(iter->hash->listas[iter->indice]);
        if(!iter->iter_lista) return NULL;
    }

    return iter;
}

bool hash_iter_avanzar(hash_iter_t *iter){
    if (!iter) return false;

    if (!hash_iter_al_final(iter)){
        lista_iter_avanzar(iter->iter_lista);

        if (!lista_iter_al_final(iter->iter_lista)) return true;

        lista_iter_destruir(iter->iter_lista);

        if (hash_iter_al_final(iter)){
            iter->iter_lista = NULL;
            return true;
        } 

        iter->indice = iter_buscar_indice(iter->hash, iter->indice);
        if (!iter->indice) return false;
        iter->iter_lista = lista_iter_crear(iter->hash->listas[iter->indice]);
        return true;
    }
    return false;
}



const char *hash_iter_ver_actual(const hash_iter_t *iter){
    
    if (hash_esta_vacio(iter->hash)) return NULL;

    elemento_hash_t* aux = lista_iter_ver_actual(iter->iter_lista);
    return aux->clave;
}


bool hash_iter_al_final(const hash_iter_t *iter){
    if (!iter || hash_esta_vacio(iter->hash)) return true;
    if(!iter->iter_lista) return true;
    return false;
}


void hash_iter_destruir(hash_iter_t* iter){
    if (iter && iter->iter_lista){
        lista_iter_destruir(iter->iter_lista);
    }
    free(iter);
}