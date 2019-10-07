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



/* *****************************************************************
 *                    Función de Hashing
 * *****************************************************************/
size_t hashing(const char *str){
    size_t hash = 5381;
    size_t c;

    while ((c = *(size_t*)str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % CAP_MIN;
}


/* *****************************************************************
 *                    Primitiva del elemento
 * *****************************************************************/

elemento_hash_t* elemento_crear(const char *clave, void* dato){

    elemento_hash_t* elemento = malloc(sizeof(elemento_hash_t));
    if (elemento == NULL) return  NULL;

    char* clave_cp =  strdup(clave);
    elemento->clave = clave_cp;
    elemento->dato = dato;

    free(clave_cp);
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

    size_t indice = hashing(clave);

    elemento_hash_t* elemento = elemento_crear(clave, dato);
    if (elemento == NULL) return false;

    if (!hash->listas[indice]) hash->listas[indice] = lista_crear();

    if (!lista_esta_vacia(hash->listas[indice])){

        lista_iter_t* iterador = lista_iter_crear(hash->listas[indice]);
        if (!iterador) return false;

        elemento_hash_t* aux = lista_iter_ver_actual(iterador);

        while (!lista_iter_al_final(iterador) || aux->clave == clave){
            lista_iter_avanzar(iterador);
            aux = lista_iter_ver_actual(iterador);
        }

        if (aux->clave == clave) lista_iter_borrar(iterador);
        lista_iter_destruir(iterador);
    }

    lista_insertar_primero(hash->listas[indice], elemento);
    hash->cantidad++;
    return true;
}






