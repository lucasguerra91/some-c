#ifndef SOME_C_LISTA_H
#define SOME_C_LISTA_H


#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>



/* *****************************************************************
 *                DEFINICIÓN DE LOS TIPOS DE DATOS
 * *****************************************************************/

struct lista;
typedef struct lista lista_t;

struct nodo;
typedef struct nodo nodo_t;


/* *****************************************************************
 *                    PRIMITIVAS DE LA PILA
 * *****************************************************************/

struct lista_t* lista_crear(void);

size_t lista_largo(lista_t* lista);


void pruebas_lista(void);

#endif //SOME_C_LISTA_H
