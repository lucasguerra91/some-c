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
 *                    PRIMITIVAS DE LA LISTA
 * *****************************************************************/


lista_t *lista_crear(void);     // ok

bool lista_esta_vacia(const lista_t *lista);    // ok

bool lista_insertar_primero(lista_t *lista, void *dato);       // ok

bool lista_insertar_ultimo(lista_t *lista, void *dato);     // ok

void *lista_borrar_primero(lista_t *lista);     // ok

void *lista_ver_primero(const lista_t *lista);  // ok

void *lista_ver_ultimo(const lista_t* lista);   // ok

size_t lista_largo(const lista_t *lista);       // ok

void lista_destruir(lista_t *lista, void destruir_dato(void *));




/* *****************************************************************
 *                    En desarrollo
 * *****************************************************************/
void lista_imprimir_enteros(lista_t *lista);
void lista_borrar_pos_pares(lista_t* lista);


#endif //SOME_C_LISTA_H
