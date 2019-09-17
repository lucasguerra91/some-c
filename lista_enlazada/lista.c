//
// Created by lguerra on 9/17/19.
//

#include "lista.h"


/* *****************************************************************
 *                DEFINICIÓN DE LOS TIPOS DE DATOS
 * *****************************************************************/

struct nodo{
    void* dato;
    struct nodo* siguiente;
};

struct lista{
    struct nodo* prim;
};

nodo_t* crear_nodo(void* valor){

    // Operación básica de malloc
    nodo_t nodo = malloc(sizeof(nodo_t));
    if (!nodo) return NULL;

    nodo->dato = valor;
    nodo->siguiente = NULL;

    return nodo;

}


/* *****************************************************************
 *                    PRIMITIVAS DE LA LISTA
 * *****************************************************************/

size_t lista_largo(lista_t* lista){
    size_t largo = 0;
    nodo_t* actual = lista->prim;
    while (actual) {
        actual = actual->siguiente;
        largo++;
    }
    return largo;
}