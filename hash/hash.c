#include "hash.h"
#include "lista.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


#define CAP_MIN 47

/* *****************************************************************
 *               Estructuras de la tabla y sus elementos
 * *****************************************************************/

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


/* *****************************************************************
 *               Funciones adicionales
 * *****************************************************************/

char *strdup(const char *src) {
    char *dst = malloc(strlen (src) + 1);  // Space for length plus nul
    if (dst == NULL) return NULL;          // No memory
    strcpy(dst, src);                      // Copy the characters
    return dst;                            // Return the new string
}



/* *****************************************************************
 *                    Función de Hashing
 * *****************************************************************/
size_t hashing(const char *clave, size_t tam){

    size_t hash = 5381;
    size_t c;

    while ((c = *(size_t*)clave++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % tam;

}


/* *****************************************************************
 *                    Primitiva del elemento
 * *****************************************************************/

elemento_hash_t* elemento_crear(char *clave, void* dato){

    elemento_hash_t* elemento = malloc(sizeof(elemento_hash_t));
    if (elemento == NULL) return  NULL;

    elemento->clave = clave;
    elemento->dato = dato;

    return elemento;

}


void* borrar_elemento(hash_t* hash, const char* clave){

    size_t indice = hashing(clave, hash->capacidad);

    lista_iter_t* iterador = lista_iter_crear(hash->listas[indice]);
    if (!iterador) return false;

    elemento_hash_t* aux;
    void * dato = NULL;
    //printf("\nDEBUGG - clave de iter_actual es %s\n", aux->clave);

    while (!lista_iter_al_final(iterador)){
        aux = lista_iter_ver_actual(iterador);

        if (strcmp(aux->clave, clave) == 0){
            lista_iter_borrar(iterador);
            hash->cantidad--;
            dato = aux->dato;
            break;
        }
        lista_iter_avanzar(iterador);

    }

    lista_iter_destruir(iterador);
    return dato;
}


void* elemento_en_lista(const hash_t *hash,const char *clave){

    size_t indice = hashing(clave, hash->capacidad);

    if (!hash->listas[indice] || lista_esta_vacia(hash->listas[indice])) return NULL;

    lista_iter_t* iterador = lista_iter_crear(hash->listas[indice]);
    if (!iterador) return NULL;

    void* dato;

    printf("indice es %lu", indice);
    elemento_hash_t* aux;


    while (!lista_iter_al_final(iterador)){

        aux = lista_iter_ver_actual(iterador);

        if (strcmp(aux->clave, clave) == 0){
            dato = aux->dato;
            break;
        }
        lista_iter_avanzar(iterador);

    }

    lista_iter_destruir(iterador);

    printf("\nDEBUGG - Saliendo de elemento en lista. El dato es: %s\n", (char *)dato);
    return dato;
}


/* *****************************************************************
 *                    Primitivas de la tabla de Hash
 * *****************************************************************/

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
    if (!hash) return 0;
    return hash->cantidad;
}


bool hash_guardar(hash_t *hash, const char *clave, void *dato){

    size_t indice = hashing(clave, hash->capacidad);

    if (!hash->listas[indice]) hash->listas[indice] = lista_crear();

    if (!lista_esta_vacia(hash->listas[indice])){
        borrar_elemento(hash, clave);
    }

    char* clave_cp =  strdup(clave);

    elemento_hash_t* elemento = elemento_crear(clave_cp, dato);
    if (elemento == NULL) return false;

    lista_insertar_primero(hash->listas[indice], elemento);
    hash->cantidad++;

    return true;
}


void *hash_obtener(const hash_t *hash, const char *clave){
    void* dato = elemento_en_lista(hash, clave);
    return dato;
}


bool hash_pertenece(const hash_t *hash, const char *clave){
    return elemento_en_lista(hash, clave);
}


void *hash_borrar(hash_t *hash, const char *clave){
    return borrar_elemento(hash, clave);
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