#include "cola.h"
#include <stdio.h>


/* ******************************************************************
 *                DEFINICIÓN DE LOS TIPOS DE DATOS
 * *****************************************************************/


typedef struct nodo{
    void* dato;
    struct nodo* siguiente;
}nodo_t;


struct cola{
    nodo_t* prim;
    nodo_t* ult;
};


/* ******************************************************************
 *                    PRIMITIVAS DEL NODO
 * *****************************************************************/

nodo_t* nodo_crear(void* valor){

    nodo_t *nodo = malloc(sizeof(nodo_t));
    if (!nodo) return NULL;

    nodo->dato = valor;
    nodo->siguiente = NULL;

    return nodo;
}


/* ******************************************************************
 *                    PRIMITIVAS DE LA COLA
 * *****************************************************************/


cola_t* cola_crear(void){

    cola_t *cola = malloc(sizeof(cola_t));
    if (cola == NULL) return NULL;

    cola->prim = NULL;
    cola->ult = NULL;

    return cola;
}


bool cola_esta_vacia(const cola_t *cola){

    if (!cola) return false;
    return  cola->prim == NULL ;
}


bool cola_encolar(cola_t *cola, void* valor){

    if (!cola) return false;

    nodo_t *nodo = nodo_crear(valor);
    if (nodo == NULL) return false;

    if (cola_esta_vacia(cola)){
        cola->prim = nodo;
        cola->ult = nodo;
    } else{
        cola->ult->siguiente = nodo;
        cola->ult = nodo;
    }

    return true;
}


void* cola_ver_primero(const cola_t *cola){

    if (!cola || cola->prim == NULL) return NULL;
    void *primero = cola->prim->dato;

    return primero;

}


void* cola_desencolar(cola_t *cola){

    if (!cola || cola->prim == NULL) return NULL;

    void *primero = cola->prim->dato; // Capturo el valor del primero

    if (cola->prim == cola->ult){ // Si es el único, prim=ult=NULL
        cola->prim = cola->ult = NULL;
    } else{
        cola->prim = cola->prim->siguiente;
    }

    return primero;
}