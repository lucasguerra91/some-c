#include "cola.h"

/* ******************************************************************
 *                DEFINICIÓN DE LOS TIPOS DE DATOS
 * *****************************************************************/

struct nodo{
    void* dato;
    struct nodo* siguiente;
};


struct cola{
    nodo_t* prim;
    nodo_t* ult;
};


/* ******************************************************************
 *                    PRIMITIVAS DEL NODO
 * *****************************************************************/

nodo_t* crear_nodo(void* valor){

    // Operación básica de malloc
    nodo_t nodo = malloc(sizeof(nodo_t));
    if (!nodo) return NULL;

    nodo.dato = valor;
    nodo.siguiente = NULL;

    return nodo;
}

/* ******************************************************************
 *                    PRIMITIVAS DE LA COLA
 * *****************************************************************/

cola_t* cola_crear(void){

}