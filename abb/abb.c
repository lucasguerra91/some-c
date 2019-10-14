#include "abb.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define ANSI_COLOR_RED     "\x1b[1;31m"
#define ANSI_COLOR_GREEN   "\x1b[1,32m"
#define ANSI_COLOR_YELLOW  "\x1b[1;33m"
#define ANSI_COLOR_BLUE    "\x1b[1;34m"
#define ANSI_COLOR_MAGENTA "\x1b[1;35m"
#define ANSI_COLOR_CYAN    "\x1b[1;36m"
#define ANSI_COLOR_RESET   "\x1b[0m"



struct abb{
    abb_nodo_t* raiz;
    abb_comparar_clave_t* f_compara_clave;
    abb_destruir_dato_t* f_destruir_dato;
    size_t cantidad_nodos;
};


typedef struct abb_nodo{
    char* clave;
    void* dato;
    abb_nodo_t* izquierda;
    abb_nodo_t* derecha;

}abb_nodo_t;


/* -----------------------------------------------------------------
                Funciones adicionales
 * -----------------------------------------------------------------*/

char *copia_clave(const char *clave) {
    char *clave_copia = strcpy(malloc(strlen(clave) + 1), clave);
    return clave_copia;
}


/* -----------------------------------------------------------------
             Primitivas del nodo
 * -----------------------------------------------------------------*/

abb_nodo_t* abb_nodo_crear(char *clave, void* dato){
    
    abb_nodo_t* nodo = malloc(sizeof(abb_nodo_t));
    if (nodo == NULL) return  NULL;
    char* clave_cp = copia_clave(clave);
    nodo->clave = clave_cp;
    nodo->dato = dato;
    nodo->derecha = NULL;
    nodo->izquierda = NULL;

    return nodo;
}



/* -----------------------------------------------------------------
             Funciones adicionales del ABB
 * -----------------------------------------------------------------*/


bool abb_esta_vacio(abb_t* abb){
    if (!abb->raiz) return true;
    return false;
}


/* -----------------------------------------------------------------
             Primitivas del ABB
 * -----------------------------------------------------------------*/

abb_t* abb_crear(abb_comparar_clave_t cmp, abb_destruir_dato_t destruir_dato){

    abb_t* abb =  malloc(sizeof(abb_t));
    if (!abb){
        free(abb);
        return NULL;
    }

    abb->cantidad_nodos = 0;
    abb->f_compara_clave = cmp;
    abb->f_destruir_dato = destruir_dato;
    abb->raiz = NULL;

    return abb;
}


bool abb_guardar(abb_t *arbol, const char *clave, void *dato){
    
}