#include "pila.h"
#include <stdlib.h>

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

    pila->cantidad = 0;
    pila->capacidad = CAP_MIN;

    return pila;
}


void pila_destruir(pila_t *pila){

    if (pila){
       free(pila->datos);
       free(pila);
   }
}


bool pila_esta_vacia(const pila_t *pila){
    return pila->cantidad == 0 ? true : false;
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
    pila->cantidad ++;
    return true;
}


void* pila_ver_tope(const pila_t *pila){

    // Si no existe la pila, o esta vacía (recién creada o vaciada) retorno NULL
    if (!pila || pila->cantidad == 0) return NULL;

    void* valor = pila->datos[pila->cantidad];
    return valor;

}