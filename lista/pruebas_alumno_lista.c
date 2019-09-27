#include "lista.h"
#include "testing.h"
#include <stddef.h>
#include "stdio.h"
#include <stdbool.h>
#include <stdlib.h>


/* ******************************************************************
 *                   FUNCIONES DE CARGA Y BORRADO
 * *****************************************************************/


void lista_agregar_array_enteros(lista_t* lista,  int cant){

    printf("\n\t--- Agregando %d elementos ---\n", cant);

    int vector[cant];

    for (int j = 0; j < cant ; j++) {
        vector[j] = j + 1;
        lista_insertar_ultimo(lista, &vector[j]);
    }
}


void lista_borrar_array_enteros(lista_t* lista,  int cant){

    printf("\n\t--- Borrando %d elementos ---\n", cant);

    for (int j = 0; j < cant ; j++) {
        lista_borrar_primero(lista);
    }
}

void iter_agregar_array_enteros(lista_iter_t* iter,  int cant){

    printf("\n\t--- Agregando %d elementos ---\n", cant);

    int vector[cant];

    for (int j = 0; j < cant ; j++) {
        vector[j] = j + 1;
        lista_iter_insertar(iter, &vector[j]);
    }

}


void iter_borrar_array_enteros(lista_iter_t* iter,  int cant){

    printf("\n\t--- Borrando %d elementos ---\n", cant);

    for (int i = 0; i < cant ; i++) {
        lista_iter_borrar(iter);

    }

}


/* ******************************************************************
 *                   PRUEBAS DE FUNCIONAMIENTO
 * *****************************************************************/


void lista_prueba_funcionamiento(){

    printf("\n# Creación y carga de nodos.\n");
    lista_t* lista_ej = lista_crear();
    printf("\n\tSe creó una nueva lista.\n");
    print_test("\tLista esta vacia == true", lista_esta_vacia(lista_ej) == true);
    print_test("\tLargo de la lista == 0", lista_largo(lista_ej) == 0);
    print_test("\t No se puede borrar primero en lista vacía.", lista_borrar_primero(lista_ej) == false);

    int valor = 10;
    print_test("\n\tInsertar 10 al inicio", lista_insertar_primero(lista_ej, &valor) == true);
    print_test("\tEL primer elemento es 10", *(int *)lista_ver_primero(lista_ej) == 10);
    print_test("\tEL último elemento es 10", *(int *)lista_ver_ultimo(lista_ej) == 10);
    print_test("\tLargo de la lista == 1", lista_largo(lista_ej) == 1);

    int valor2 = 25;
    print_test("\n\tInsertar 25 al final", lista_insertar_ultimo(lista_ej, &valor2) == true);
    print_test("\tEL primer elemento es 10", *(int *)lista_ver_primero(lista_ej) == 10);
    print_test("\tEL último elemento es 25", *(int *)lista_ver_ultimo(lista_ej) == 25);
    print_test("\tLargo de la lista == 2", lista_largo(lista_ej) == 2);


    print_test("\n\tBorrar el primer elemento", *(int *)lista_borrar_primero(lista_ej) == 10);
    print_test("\tEL primer elemento ahora es 25", *(int *)lista_ver_primero(lista_ej) == 25);
    print_test("\tEL último elemento es 25", *(int *)lista_ver_ultimo(lista_ej) == 25);
    print_test("\tLargo de la lista == 1", lista_largo(lista_ej) == 1);

    print_test("\n\tBorrar el primer elemento con largo = 1", *(int *)lista_borrar_primero(lista_ej) == 25);
    print_test("\tEL primer elemento ahora es NULL", lista_ver_primero(lista_ej) == NULL);
    print_test("\tEL último elemento es NULL", lista_ver_ultimo(lista_ej) == NULL);
    print_test("\tLargo de la lista == 0", lista_largo(lista_ej) == 0);

    print_test("\n\tIntenta borrar el primer elemento con lista vacía = NULL", lista_borrar_primero(lista_ej) == NULL);

    lista_destruir(lista_ej, NULL);
    printf("\n\tDestruyendo lista..\n");
}


void lista_prueba_volumen(){

    printf("\n# Prueba de funcionamiento de lista con volumen.\n");
    lista_t* lista = lista_crear();
    printf("\n\tSe creó una nueva lista.\n");
    print_test("\tLista esta vacia == true", lista_esta_vacia(lista) == true);
    print_test("\tLargo de la lista == 0", lista_largo(lista) == 0);

    lista_agregar_array_enteros(lista, 150000);
    print_test("\tLargo de la lista == 150000", lista_largo(lista) == 150000);
    print_test("\tLista esta vacia == false", lista_esta_vacia(lista) == false);

    lista_borrar_array_enteros(lista, 75000);
    print_test("\tLargo de la lista == 75000", lista_largo(lista) == 75000);
    print_test("\tLista esta vacia == false", lista_esta_vacia(lista) == false);

    lista_borrar_array_enteros(lista, 75000);
    print_test("\tLargo de la lista == 0", lista_largo(lista) == 0);
    print_test("\tLista esta vacia == false", lista_esta_vacia(lista) == true);

    lista_destruir(lista, NULL);
    printf("\n\tDestruyendolista..\n");
}




void iterador_externo_funcionamiento(){
    printf("\n# Pruebas con iterador externo.\n");

    lista_t* lista = lista_crear();
    lista_iter_t* iterador = lista_iter_crear(lista);

    // Prueba ver actual
    print_test("\n\tEl nuevo actual es NULL", lista_iter_ver_actual(iterador) == NULL);

    // Prueba iter_al_final con recien creado
    print_test("\tEl iterador está al final", lista_iter_al_final(iterador) == true);

    int a = 1;
    // Prueba de insertar
    print_test("\n\tAgregar 1 con iter_insertar", lista_iter_insertar(iterador, &a) == true);
    print_test("\tEl nuevo actual es 1", *(int *)lista_iter_ver_actual(iterador) == 1);

    // Prueba de borrar
    print_test("\n\tBorrar 1 con iter_borrar", *(int *)lista_iter_borrar(iterador) == 1);
    print_test("\tEl nuevo actual es NULL", lista_iter_ver_actual(iterador) == NULL);

    // Vuelvo a agregar
    print_test("\n\tAgregar 1 con iterador1", lista_iter_insertar(iterador, &a) == true);
    print_test("\tEl nuevo actual es 1", *(int *)lista_iter_ver_actual(iterador) == 1);
    print_test("\tLargo de la lista == 1", lista_largo(lista) == 1);

    int b = 2;
    print_test("\n\tAgregar 2 con iterador1", lista_iter_insertar(iterador, &b) == true);
    print_test("\tEl nuevo actual es 2", *(int *)lista_iter_ver_actual(iterador) == 2);
    print_test("\tLargo de la lista == 2", lista_largo(lista) == 2);

    // Creo segundo iterador
    lista_iter_t* iterador2 = lista_iter_crear(lista);
    printf("\n\tCreación de un segundo iterador\n");
    print_test("\tEl actual del iterador2 es 2", *(int *)lista_iter_ver_actual(iterador2) == 2);
    print_test("\tLargo de la lista == 2", lista_largo(lista) == 2);

    // Avanzar en el iterador 2
    print_test("\tAvanzar en iter 2", lista_iter_avanzar(iterador2) == true);
    print_test("\tEl actual de iter 2 es 1", *(int *)lista_iter_ver_actual(iterador2) == 1);

    // No modifica actual de iter 1
    print_test("\tEl actual de iter 1 es 2", *(int *)lista_iter_ver_actual(iterador) == 2);

    int c = 3;
    // Inserto 3 desde iterador 2
    print_test("\n\tAgregar 3 a la lista desde iterador2", lista_iter_insertar(iterador2, &c) == true);
    print_test("\tEl nuevo actual de iterador2 es 3", *(int *)lista_iter_ver_actual(iterador2) == 3);
    print_test("\tLargo de la lista == 3", lista_largo(lista) == 3);


    lista_iter_destruir(iterador);
    lista_iter_destruir(iterador2);
    lista_destruir(lista, NULL);
    printf("\n\tDestruyendo iteradores y lista..\n");
}

void iterador_externo_volumen(){
    printf("\n# Pruebas de volumen con iterador externo .\n");

    lista_t* lista = lista_crear();
    lista_iter_t* iterador = lista_iter_crear(lista);
    print_test("\n\tEl nuevo actual es NULL", lista_iter_ver_actual(iterador) == NULL);

    iter_agregar_array_enteros(iterador, 100000);
    print_test("\tLargo de la lista == 100000", lista_largo(lista) == 100000);


    iter_borrar_array_enteros(iterador, 70000);
    print_test("\tLargo de la lista == 30000", lista_largo(lista) == 30000);

    iter_borrar_array_enteros(iterador, 30000);
    print_test("\tLargo de la lista == 0", lista_largo(lista) == 0);
    print_test("\tEl nuevo actual es NULL", lista_iter_ver_actual(iterador) == NULL);
    print_test("\tNo se puede borrar en lista vacía", lista_iter_borrar(iterador) == NULL);

    printf("\n\tDestruyendo iterador y lista..\n");
    lista_destruir(lista, NULL);
    lista_iter_destruir(iterador);

}

void iterador_externo_sobre_lista_vacia(){
    printf("\n# Pruebas con iterador externo sobre una lista vacia.\n");

    lista_t* lista = lista_crear();
    lista_iter_t* iterador = lista_iter_crear(lista);

    // Prueba ver actual
    print_test("\n\tEl actual es NULL", lista_iter_ver_actual(iterador) == NULL);
    print_test("\tAvanzar sobre lista vacia = FALSE", lista_iter_avanzar(iterador) == false);
    print_test("\tBorrar sobre lista vacia = FALSE", lista_iter_borrar(iterador) == false);

    lista_iter_destruir(iterador);
    lista_destruir(lista, NULL);
    printf("\n\tDestruyendo iteradores y lista..\n");

}


void imprimir_iter_externo(lista_t *lista)
{
    lista_iter_t *iter = lista_iter_crear(lista);
    int num_items = 0;

    while (!lista_iter_al_final(iter))
    {
        char *elemento = lista_iter_ver_actual(iter);
        printf("\t%d. %s\n", ++num_items, elemento);

        lista_iter_avanzar(iter);
    }
    printf("\tTengo que comprar %d ítems\n", num_items);
    lista_iter_destruir(iter);
}


bool imprimir_un_item(void *elemento, void *extra)
{
    // Sabemos que ‘extra’ es un entero, por tanto le podemos hacer un cast.
    int *contador = extra;
    printf("\t%d. %s\n", ++(*contador), (char*) elemento);

    return true; // seguir iterando
}

void imprimir_iter_interno(lista_t *lista)
{
    int num_items = 0;
    lista_iterar(lista, imprimir_un_item, &num_items);
    printf("\tTengo que comprar %d ítems\n", num_items);
}


void ejemplo_iteradores() {
    printf("\n# Ejemplos de uso lista_iterar\n\n");
    lista_t *super = lista_crear();

    printf("\n\tSe creó la lista del super.\n");
    print_test("\tLista esta vacia == true", lista_esta_vacia(super) == true);

    print_test("\n\tCargar leche a la lista del super", lista_insertar_ultimo(super, "leche") == true);
    print_test("\tCargar huevos a la lista del super", lista_insertar_ultimo(super, "huevos") == true);
    print_test("\tCargar pan a la lista del super", lista_insertar_ultimo(super, "pan") == true);
    print_test("\tCargar mermelada a la lista del super", lista_insertar_ultimo(super, "mermelada") == true);
    print_test("\tCargar soga a la lista del super", lista_insertar_ultimo(super, "soga") == true);
    print_test("\tCargar pala a la lista del super", lista_insertar_ultimo(super, "pala") == true);
    print_test("\tCargar formol a la lista del super", lista_insertar_ultimo(super, "formol") == true);
    print_test("\tCargar chuchillo a la lista del super", lista_insertar_ultimo(super, "cuchillo") == true);

    printf("\n\t*Imprimiendo lista con iteradores externos.\n\n");
    imprimir_iter_externo(super);
    printf("\n\t*Imprimiendo lista con iteradores internos.\n\n");
    imprimir_iter_interno(super);

    lista_destruir(super, NULL);
    printf("\n\tDestruyendo lista..\n");
}

/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/


void pruebas_lista_alumno() {
    lista_prueba_funcionamiento();
    lista_prueba_volumen();
    iterador_externo_sobre_lista_vacia();
    iterador_externo_funcionamiento();
    iterador_externo_volumen();
    ejemplo_iteradores();

}
