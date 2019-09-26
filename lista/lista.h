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

struct lista_iter;
typedef struct lista_iter lista_iter_t;


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
 *                    PRIMITIVAS DEL ITERADOR EXTERNO
 * *****************************************************************/

// Crea un nuevo iterador a partir de una lista.
// Pre: La lista existe(aunque esté vacía), de lo contrario devuelve NULL
// Post: Devuelve un iterador que apunta al primer nodo de la lista.
lista_iter_t* lista_iter_crear (lista_t* lista);

// Verifica si el iterador se encuentra al final de la lista (no en el último nodo).
// Pre: Recibe un iterador previamente creado.
// Post: Devuelve true o false dependiendo si esta o no al final de la lista el iterador.
bool lista_iter_al_final (const lista_iter_t* iter);

// Avanza una posición dentro de la lista.
// Pre: El iterador existe, y se encuentra en una posición válida para desplazarse.
// Post: Devuelve true si logró avanzar, de lo contrario false.
bool lista_iter_avanzar (lista_iter_t* iter);

void* lista_iter_ver_actual (const lista_iter_t* iter);

bool lista_iter_insertar (lista_iter_t* iter, void* dato);

void* lista_iter_borrar (lista_iter_t* iter);

void lista_iter_destruir (lista_iter_t* iter);


/* *****************************************************************
 *                    En desarrollo
 * *****************************************************************/
void lista_imprimir_enteros(lista_t *lista);
void lista_borrar_pos_pares(lista_t* lista);


#endif //SOME_C_LISTA_H
