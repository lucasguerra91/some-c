#include "hash.h"
#include "lista.h"
#include <string.h>


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


//bool hash_insertar_ordenado(lista_t* lista, elemento_hash_t* elemento){
//
//    lista_iter_t* iter = lista_iter_crear(lista);
//    if (iter == NULL) return false;
//
//    elemento_hash_t* tmp = (elemento_hash_t*)lista_iter_ver_actual(iter);
//
//    while (!lista_iter_al_final(iter) || (elemento->clave > tmp->clave)){
//        lista_iter_avanzar(iter);
//        tmp = (elemento_hash_t*)lista_iter_ver_actual(iter);
//    }
//    lista_iter_insertar(iter, elemento);
//    lista_iter_destruir(iter);
//    free(tmp);
//    return true;
//}

/* *****************************************************************
 *                    Función de Hashing
 * *****************************************************************/
size_t hashing(char *str){
    size_t hash = 5381;
    size_t c;

    while ((c = *(size_t*)str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % CAP_MIN;
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


/* *****************************************************************
 *                    Primitivas de la tabla de Hash
 * *****************************************************************/


hash_t *hash_crear(hash_destruir_dato_t destruir_dato){

    hash_t* hash = malloc(sizeof(hash_t));
    if (!hash) return NULL;

    hash->listas = malloc(CAP_MIN * sizeof(lista_t*));
    if (!hash->listas) return NULL;

    hash->cantidad = 0;
    hash->capacidad = CAP_MIN;

    for (size_t i = 0; i < CAP_MIN; i++) {
        hash->listas[i] = NULL;
    }

    return hash;
}


size_t hash_cantidad(const hash_t *hash){
    if (!hash) return 0;
    return hash->cantidad;
}


bool hash_guardar(hash_t *hash, const char *clave, void *dato){

    char* clave_cp =  strdup(clave);

    size_t indice = hashing(clave_cp);

    elemento_hash_t* elemento = elemento_crear(clave_cp, dato);
    if (elemento == NULL) return false;

    if (!hash->listas[indice]) hash->listas[indice] = lista_crear();

    if (!lista_esta_vacia(hash->listas[indice])){

        lista_iter_t* iterador = lista_iter_crear(hash->listas[indice]);
        if (!iterador) return false;

        elemento_hash_t* aux = (elemento_hash_t*)lista_iter_ver_actual(iterador);

        while (!lista_iter_al_final(iterador) || aux->clave == clave_cp){
            lista_iter_avanzar(iterador);
            aux = (elemento_hash_t*)lista_iter_ver_actual(iterador);
        }

        if (aux->clave == clave_cp) lista_iter_borrar(iterador);
        lista_iter_destruir(iterador);
    }
    //hash_insertar_ordenado(hash->listas[indice], elemento);
    lista_insertar_primero(hash->listas[indice], elemento);
    hash->cantidad++;
    free(clave_cp);
    return true;
}


void *hash_obtener(const hash_t *hash, const char *clave){
    char* clave_cp =  strdup(clave);
    size_t indice = hashing(clave_cp);

    lista_iter_t* iter = lista_iter_crear(hash->listas[indice]);
    if (iter == NULL) return NULL;

    elemento_hash_t* tmp = (elemento_hash_t*)lista_iter_ver_actual(iter);
    printf("%p", tmp->dato);
    while (!lista_iter_al_final(iter) || tmp->clave != clave_cp){
        lista_iter_avanzar(iter);
        tmp = (elemento_hash_t*)lista_iter_ver_actual(iter);
    }

    if (tmp->clave == clave_cp){
        printf("%p", tmp->dato);
        return tmp->dato;
    }
    free(tmp);
    return NULL;

}


bool hash_pertenece(const hash_t *hash, const char *clave){
    if (hash_obtener(hash, clave)) return true;
    return false;
}
