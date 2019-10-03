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

struct lista_iter;
typedef struct lista_iter lista_iter_t;


/* *****************************************************************
 *                    PRIMITIVAS DE LA LISTA
 * *****************************************************************/

// Crea una nueva lista
// Pre:  Ninguna
// Post: Devuelve la lista recien creada, donde primero = ultimo = NULL y largo = 0
lista_t *lista_crear(void);     // ok

// Consulta si la lista está vacía
// Pre: Recibe una lista correctamente creada
// Post: Devuelve true si esta vacía, false si no lo esta o si no existe la lista
bool lista_esta_vacia(const lista_t *lista);    // ok

// Inserta un elemento al principio de la lista
// Pre: Recibe una lista válida y un void*
// Post: Lo inserta al comienzo de la lista, actualizando las referencias de la misma,
// confirma con true si la operación se realizó con éxito, false de lo contrario.
bool lista_insertar_primero(lista_t *lista, void *dato);       // ok

// Inserta un elemento al final de la lista
// Pre: Recibe una lista válida y un void*
// Post: Lo inserta al final de la lista, actualizando las referencias de la misma,
// confirma con true si la operación se realizó con éxito, false de lo contrario.
bool lista_insertar_ultimo(lista_t *lista, void *dato);     // ok

// Borra el primer elemento  de la lista
// Pre: Recibe una lista válida
// Post: Borra el primer elemento de la lista, actualizando las referencias de la misma,
// confirma con true si la operación se realizó con éxito, false de lo contrario.
void *lista_borrar_primero(lista_t *lista);     // ok

// Devuelve el valor del primer elemento de la lista
// Pre: Recibe una lista válida.
// Post: Si la lista existe devuelve el valor del primer elemento, de lo contrario NULL
void *lista_ver_primero(const lista_t *lista);  // ok

// Devuelve el valor del ultimo elemento de la lista
// Pre: Recibe una lista válida.
// Post: Si la lista existe devuelve el valor del ultimo elemento, de lo contrario NULL
void *lista_ver_ultimo(const lista_t* lista);   // ok

// Devuelve el largo de la lista
// Pre: Recibe una lista válida.
// Post: Devuelve el largo acual de la lista
size_t lista_largo(const lista_t *lista);       // ok

// Destruye la lista y su contenido
// Pre: Recibe una lista válida y NULL o una funciòn de eliminación de elementos que cumpla con la firma
// Post: Si la funciòn adicional es NULL borra todos los elementos , si es una funciòn válida, la aplica uno a uno
// a todos los nodos. Por último destruye la estructura
void lista_destruir(lista_t *lista, void destruir_dato(void *));    // ok

// Itera la lista aplicando la función recibida por parámetro
// Pre: Recibe una lista válida, una función que cumpla con la firma y un valor extra
// Post: APlica la funcion a cada uno de los nodos mientras la misma retorne verdadero
void lista_iterar(lista_t *lista, bool visitar(void*, void*), void *extra); // ok



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

// Devuelve el valor actual del iterador
// Pre: El iterador existe,fue creado a partir de una lista válida.
// Post: Devuelve el contenido del iterador actual
void* lista_iter_ver_actual (const lista_iter_t* iter);

// Inserta un dato entre anterior y actual mantiendo la consistencia de la lista
// Pre: El iterador existe
// Post Devuelve true o false confirmando si la operación se realizó correctamente.
// Iterador actual sera el nuevo nodo
bool lista_iter_insertar (lista_iter_t* iter, void* dato);

// Borra el iterador actual manteniendo la consistencia de la lista y los iteradores.
// Pre: El iterador existe y no se encuentra al final de la lista.
// Post Devuelve el dato contenido del nodo que se eliminó
void* lista_iter_borrar (lista_iter_t* iter);

// Destruye el iterador sin afectar la estructura de la lista
// Pre: El iterador existe, de lo contrario no hace nada
// Post: Se libera la memoria que ocupaba el iterador
void lista_iter_destruir (lista_iter_t* iter);


/* *****************************************************************
 *                    En desarrollo
 * *****************************************************************/

//void lista_borrar_pos_pares(lista_t* lista);


#endif //SOME_C_LISTA_H
