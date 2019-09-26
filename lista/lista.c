//
// Created by lguerra on 9/17/19.
//

#include "lista.h"


/* *****************************************************************
 *                DEFINICIÓN DE LOS TIPOS DE DATOS
 * *****************************************************************/

struct nodo{
    void* dato;
    struct nodo* prox;
};

struct lista{
    struct nodo* primero;
    struct nodo* ultimo;
    size_t largo;
};

struct lista_iter{
    struct nodo* anterior;
    struct nodo* actual;
};

/* *****************************************************************
 *                    PRIMITIVAS DEL NODO
 * *****************************************************************/

nodo_t* nodo_crear(void* valor){

    nodo_t *nodo = malloc(sizeof(nodo_t));

    if (nodo == NULL) return NULL;

    nodo->dato = valor;
    nodo->prox = NULL;

    return nodo;
}


void mostrar_nodo(nodo_t* nodo){
    printf("Valor %d", *(int *)nodo->dato);
    // printf("Apunta a: %p", nodo->prox);
}

/* *****************************************************************
 *              PRIMITIVAS DEL ITERADOR EXTERNO
 * *****************************************************************/







/* *****************************************************************
 *                    PRIMITIVAS DE LA LISTA
 * *****************************************************************/

size_t lista_largo(const lista_t* lista){
    return lista->largo  ;
}


lista_t* lista_crear(void){

    lista_t *lista = malloc(sizeof(lista_t));

    if (lista == NULL) return NULL;

    lista->primero = NULL;
    lista->ultimo = NULL;
    lista->largo = 0;

    return lista;

}


bool lista_esta_vacia(const lista_t* lista){

    if (!lista) return false;

    return lista->primero == NULL ;
}


bool lista_insertar_primero(lista_t *lista, void *dato){
    if (!lista) return false;

    nodo_t* nuevo = nodo_crear(dato);
    if (nuevo == NULL) return false;

    if (lista_esta_vacia(lista)){
        lista->ultimo = nuevo; // Primero y ultimo apuntan a lo mismo
    } else{
        nuevo->prox = lista->primero;  // Apunto nuevo al nuevo anterior
    }

    lista->primero = nuevo; // A esto lo hago esté o no vacía
    lista->largo++;

    return true;
}


void *lista_ver_primero(const lista_t *lista){
    if (!lista || lista_esta_vacia(lista)) return NULL;
    return lista->primero->dato;
}


void *lista_ver_ultimo(const lista_t* lista){
    if (!lista || lista_esta_vacia(lista)) return NULL;
    return lista->ultimo->dato;
}


bool lista_insertar_ultimo(lista_t *lista, void *dato){
    if (!lista) return false;


    nodo_t* nuevo = nodo_crear(dato);
    if (nuevo == NULL) return false;

    if(lista_esta_vacia(lista)){
        lista->primero = nuevo;
    } else{
        lista->ultimo->prox = nuevo;
    }

    lista->ultimo = nuevo;
    lista->largo++;
    return true;
}


void *lista_borrar_primero(lista_t *lista){

    if (!lista || lista_esta_vacia(lista)) return NULL;

    nodo_t* tmp = lista->primero;
    void* dato = lista->primero->dato; // recupero el dato del primero a eliminar

    if (lista->largo == 1){
        lista->ultimo = lista->primero = NULL;
    } else{
        lista->primero = lista->primero->prox;
    }

    free(tmp);
    lista->largo--;
    return dato;

}

// solo testing
void lista_imprimir_enteros(lista_t *lista){
    nodo_t* indice = lista->primero;


    //printf("[");  Si abro corchetes acá, la lista se imprime como 00000000
    while (indice != NULL){
        printf("%p - ", indice->dato);
        indice = indice->prox;
    }
    //printf("\n");

    free(indice);

}

void lista_borrar_pos_pares(lista_t* lista){
    if (!lista) return;

    size_t contador = 0;
    nodo_t* ant = NULL;
    nodo_t* act = lista->primero;

    while (act != NULL){
        contador++;
        if (contador % 2 == 0){
            ant->prox = act->prox;
            nodo_t* aux = act;
            act = ant->prox;
            free(aux);
        } else{
            ant = act;
            act = ant->prox;
        }
    }
}

