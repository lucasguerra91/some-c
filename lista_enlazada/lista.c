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





//bool lista_iter_insertar (lista_iter_t* iter, void* dato){
//
//    if (!iter) return false;
//
//    nodo_t* nuevo = nodo_crear(dato);
//
//    if (nuevo == NULL) return  false;
//
//    if (lista_esta_vacia(iter->lista) || iter->actual == iter->lista->primero){
//        iter->lista->primero = nuevo;
//        if (iter->actual == iter->lista->ultimo) iter->lista->ultimo = nuevo;
//    }else if (lista_iter_al_final(iter)){
//        iter->lista->ultimo = nuevo;
//    } else{
//        iter->anterior->prox = nuevo;
//    }
//
//    nuevo->prox = iter->actual;
//    iter->actual = nuevo;
//    iter->lista->largo++;
//    return true;
//}

//void* lista_iter_borrar (lista_iter_t* iter){
//
//    if (!iter) return NULL;
//
//    if (lista_esta_vacia(iter->lista) || lista_iter_al_final(iter)) return NULL;
//
//    nodo_t* temp =  iter->actual;
//    void* dato = temp->dato;
//
//    if (iter->actual == iter->lista->primero){
//        iter->lista->primero = iter->actual->prox;
//        if (iter->actual == iter->lista->ultimo) iter->lista->ultimo = iter->actual->prox;
//
//    }else if (iter->actual == iter->lista->ultimo){
//        iter->lista->ultimo = iter->anterior;
//    } else{
//        iter->anterior->prox = iter->actual->prox;
//    }
//
//    iter->actual = iter->actual->prox;
//    free(temp);
//    iter->lista->largo--;
//    return dato;
//}


//bool lista_iter_al_final(const lista_iter_t* iter){
//
//    if (!iter) return false;
//
//    if ((iter->anterior == iter->lista->ultimo) && (iter->actual == NULL)){
//        return true;
//    }
//
//    return false;
//}


//bool lista_iter_avanzar (lista_iter_t* iter){
//
//    if (!iter || lista_esta_vacia(iter->lista)) return false;
//
//    if (lista_iter_al_final(iter)) return false;
//
//    if (iter->actual == iter->lista->ultimo){
//        iter->anterior = iter->actual;
//        iter->actual = NULL;
//    }else{
//        iter->anterior = iter->actual;
//        iter->actual = iter->actual->prox;
//    }
//
//    return true;
//}
//
//bool lista_iter_avanzar (lista_iter_t* iter){
//
//    if (!iter || lista_esta_vacia(iter->lista)) return false;
//
//    if (lista_iter_al_final(iter)) return false;
//
//    iter->anterior = iter->actual;
//    if (iter->actual){
//        iter->actual = iter->actual->prox;
//    }else{
//        iter->actual = NULL;
//    }
//    return true;
//}