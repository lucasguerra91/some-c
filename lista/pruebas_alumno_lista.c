#include "lista.h"
#include "testing.h"
#include <stddef.h>
#include "stdio.h"
#include <stdbool.h>
#include <stdlib.h>


/* ******************************************************************
 *                   FUNCIONES DE CARGA Y BORRADO
 * *****************************************************************/


void agregar_array_enteros(lista_t* lista,  int cant){

    printf("\n\t--- Agregando %d elementos ---\n", cant);

    int vector[cant];

    for (int j = 0; j < cant ; j++) {
        vector[j] = j + 1;
    }

    for (int i = 0; i < cant ; i++) {
        lista_insertar_ultimo(lista, &vector[i]);
    }

}

void iter_agregar_array_enteros(lista_iter_t* iter,  int cant){

    printf("\n\t--- Agregando %d elementos ---\n", cant);

    int vector[cant];

    for (int j = 0; j < cant ; j++) {
        vector[j] = j + 1;
    }

    for (int i = 0; i < cant ; i++) {
        lista_iter_insertar(iter, &vector[i]);
    }

}


void iter_borrar_array_enteros(lista_iter_t* iter,  int cant){

    printf("\n\t--- Borrando %d elementos ---\n", cant);

    for (int i = 0; i < cant ; i++) {
        void* dato;
        dato = lista_iter_borrar(iter);
        free(dato);
    }

}


/* ******************************************************************
 *                   PRUEBAS DE FUNCIONAMIENTO
 * *****************************************************************/


void prueba_funcionamiento(){
    printf("\n# Creación y carga de nodos.\n");
    lista_t* lista_ej = lista_crear();
    printf("\n\tSe creó una nueva lista.\n");
    print_test("\tLista esta vacia == true", lista_esta_vacia(lista_ej) == true);
    print_test("\tLargo de la lista == 0", lista_largo(lista_ej) == 0);

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

    free(lista_ej);
}


void prueba_iterador_externo(){
    printf("\n# Pruebas con iterador externo.\n");

    lista_t* lista = lista_crear();
    lista_iter_t* iterador = lista_iter_crear(lista);

    // Prueba ver actual
    print_test("\n\tEl nuevo actual es NULL", lista_iter_ver_actual(iterador) == NULL);

    // Prueba iter_al_final con recien creado
    print_test("\tEl iterador está al final", lista_iter_al_final(iterador) == true);

    int a = 1;
    // Prueba de insertar
    print_test("\tAgregar 1 con iter_insertar", lista_iter_insertar(iterador, &a) == true);
    print_test("\tEl nuevo actual es 1", *(int *)lista_iter_ver_actual(iterador) == 1);

    // Prueba de borrar
    print_test("\tBorrar 1 con iter_borrar", *(int *)lista_iter_borrar(iterador) == 1);
    print_test("\tEl nuevo actual es NULL", lista_iter_ver_actual(iterador) == NULL);



    lista_iter_destruir(iterador);
    lista_destruir(lista, NULL);
}

// Imprimir una lista con iterador externo

void imprimir_iter_externo(lista_t *lista)
{
    lista_iter_t *iter = lista_iter_crear(lista);
    int num_items = 0;

    while (!lista_iter_al_final(iter))
    {
        char *elemento = lista_iter_ver_actual(iter);
        printf("%d. %s\n", ++num_items, elemento);

        lista_iter_avanzar(iter);
    }
    printf("Tengo que comprar %d ítems\n", num_items);
    lista_iter_destruir(iter);
}



// Imprimir una lista con iterador interno


bool imprimir_un_item(void *elemento, void *extra)
{
    // Sabemos que ‘extra’ es un entero, por tanto le podemos hacer un cast.
    int *contador = extra;
    printf("%d. %s\n", ++(*contador), (char*) elemento);

    return true; // seguir iterando
}

void imprimir_iter_interno(lista_t *lista)
{
    int num_items = 0;
    lista_iterar(lista, imprimir_un_item, &num_items);
    printf("Tengo que comprar %d ítems\n", num_items);
}


// Ejemplo de uso



void ejemplo_iteradores() {
    lista_t *super = lista_crear();

    lista_insertar_ultimo(super, "leche");
    lista_insertar_ultimo(super, "huevos");
    lista_insertar_ultimo(super, "pan");
    lista_insertar_ultimo(super, "mermelada");

    imprimir_iter_externo(super);
    imprimir_iter_interno(super);

    lista_destruir(super, NULL);
}

/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/


void pruebas_lista_alumno() {
    prueba_funcionamiento();
    prueba_iterador_externo();
    ejemplo_iteradores();
}
