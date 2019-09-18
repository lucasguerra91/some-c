#include "pila.h"
#include <stdlib.h>
#include <stdio.h>

#define CAP_MIN 1

/* Definición del struct pila proporcionado por la cátedra.
 */
struct pila {
    void** datos;
    size_t cantidad;  // Cantidad de elementos almacenados.
    size_t capacidad;  // Capacidad del arreglo 'datos'.
};



/* *****************************************************************
 *                    PRIMITIVAS DE LA PILA
 * *****************************************************************/

pila_t* pila_crear(void){

    pila_t *pila = malloc(sizeof(pila_t));
    pila->datos = malloc(CAP_MIN * sizeof(void *));

    if (pila == NULL || pila->datos == NULL) return NULL;

    pila->cantidad = 0;
    pila->capacidad = CAP_MIN;

    return pila;
}


void pila_destruir(pila_t *pila){

    if (pila){
       free(pila->datos); // libero primero la memoria del array
       free(pila);
   }
}


bool pila_esta_vacia(const pila_t *pila){
    return pila->cantidad == 0;
}


bool pila_apilar(pila_t *pila, void* valor){

    if (!pila) return false; // Si la pila no existe

    if (pila->cantidad == pila->capacidad){ // Redimensiono si estoy al límite.

        void* temporal = realloc(pila->datos, pila->capacidad * 2 * sizeof(void *));
        if (temporal == NULL) return false;

        pila->datos = temporal;
        pila->capacidad *= 2;

    }

    // Agrego el valor y actualizo la cantidad actual

    pila->datos[pila->cantidad] = valor;
    pila->cantidad++;

    //printf("\nSe apilo %p\n", valor);
    return true;
}


void* pila_ver_tope(const pila_t *pila){

    // Si no existe la pila, o esta vacía (recién creada o vaciada) retorno NULL
    if (!pila || pila->cantidad == 0) return NULL;

    void *tope = pila->datos[pila->cantidad - 1];
    return tope;

}


void* pila_desapilar(pila_t *pila){

    if (!pila || pila->cantidad == 0) return NULL;

    // Si la cantidad de elementos es menor a la mitad de la capacidad, realloc a 3/4 de la capacidad
    if (pila->cantidad < (pila->capacidad / 4)){

        pila->capacidad =  (pila->capacidad /2) ;

        void* temporal = realloc(pila->datos, pila->capacidad * sizeof(void *));
        if (temporal == NULL) return false;

        pila->datos = temporal;

    }

    pila->cantidad--;

    if (pila->cantidad == 0){
        pila->capacidad = CAP_MIN;
    }

    void* valor = pila->datos[pila->cantidad];
    return valor ;

}



/* *****************************************************************
 *                    FUNCIONES ADICIONALES
 * *****************************************************************/
// Devuelve la cantidad actual de elementos en la pila
size_t pila_ver_cantidad(pila_t *pila){
    return pila->cantidad;
}

// Devuelve la capacidad actual de la pila
size_t pila_ver_capacidad(pila_t *pila){
    //printf("\nCantidad actual : %zu \n Pila actual:", pila->cantidad);
    return pila->capacidad;
}

// Imprime todos los elementos de la pila
void pila_imprimir(pila_t *pila){
    for (int i = 0; i < pila->cantidad ; ++i) {
        printf("\t\n %u", *(int *)pila->datos[i]);
    }
}

