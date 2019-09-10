#include "pila.h"
#include <stdlib.h>

/* Definición del struct pila proporcionado por la cátedra.
 */
typedef struct pila {
    void** datos;
    size_t cantidad;  // Cantidad de elementos almacenados.
    size_t capacidad;  // Capacidad del arreglo 'datos'.
} pila_t;



/* *****************************************************************
 *                    PRIMITIVAS DE LA PILA
 * *****************************************************************/

pila_t* pila_crear(void){
    pila_t *p_pila = malloc(sizeof(pila_t));

    if (!p_pila) return NULL;

    p_pila->datos = malloc(sizeof(void *));


    p_pila->cantidad = 0;
    p_pila->capacidad = 1;

    return p_pila;
}
