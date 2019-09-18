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

// Crea la lista inicializando el nodo primero a NULL
lista_t* lista_crear(void);

// Devuelve el largo de la lista
size_t lista_largo(lista_t* lista);

// Consulta si la lista esta vacia, devuelve false si no lo està o si no fue creada
bool lista_esta_vacia(lista_t* lista);

void pruebas_lista_alumno(void);

// Solo para pruebas internas
nodo_t* crear_nodo(void* valor);
void mostrar_nodo(nodo_t* nodo);

#endif //SOME_C_LISTA_H
