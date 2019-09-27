//void lista_borrar_pos_pares(lista_t* lista){
//
//    if (!lista) return;
//
//    size_t contador = 0;
//    nodo_t* ant = NULL;
//    nodo_t* act = lista->primero;
//
//    while (act != NULL){
//
//        contador++;
//
//        if (contador % 2 == 0){
//            nodo_t* aux = act;
//
//            if (act == lista->primero) {
//                lista->primero = act->prox;
//            }
//
//            if (act == lista->ultimo){
//                lista->ultimo = ant;
//            }
//
//             ant->prox = act->prox;
//             act = act->prox->prox;
//
//            free(aux);
//        } else{
//            ant = act;
//            act = act->prox;
//        }
//    }
//}

//
// Created by lguerra on 9/17/19.
//

#include "lista.h"


/* *****************************************************************
 *                DEFINICIÓN DE LOS TIPOS DE DATOS
 * *****************************************************************/

struct nodo{
    void* dato;
    struct nodo* siguiente;
};

struct lista{
    struct nodo* prim;
};

/* *****************************************************************
 *                    PRIMITIVAS DEL NODO
 * *****************************************************************/

nodo_t* crear_nodo(void* valor){

    // Operación básica de malloc
    nodo_t* nodo = malloc(sizeof(nodo_t));
    if (!nodo) return NULL;

    nodo->dato = valor;
    nodo->siguiente = NULL;

    return nodo;

}

void mostrar_nodo(nodo_t* nodo){
    printf("Valor %d", *(int *)nodo->dato);
    // printf("Apunta a: %p", nodo->siguiente);
}


/* *****************************************************************
 *                    PRIMITIVAS DE LA LISTA
 * *****************************************************************/

size_t lista_largo(lista_t* lista){
    size_t largo = 0;
    nodo_t* actual = lista->prim;
    while (actual) {
        actual = actual->siguiente;
        largo++;
    }
    return largo;
}

lista_t* lista_crear(void){

    lista_t *lista = malloc(sizeof(lista_t));


    if (lista == NULL) return NULL;

    lista->prim = NULL;

    return lista;

}

bool lista_esta_vacia(lista_t* lista){

    if (!lista) return false;

    return lista->prim == NULL ;
}