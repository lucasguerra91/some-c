#include "lista.h"
#include "testing.h"
#include <stddef.h>
#include "stdio.h"

/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void agregar_array_enteros(lista_t* lista,  int cant){

    printf("\n\n--- Agregando %d elementos ---\n", cant);

    int vector[cant];

    for (int j = 0; j < cant ; j++) {
        vector[j] = j;
    }

    for (int i = 0; i < cant ; i++) {
        print_test("Agregando elemento a la lista", lista_insertar_ultimo(lista, &vector[i]) == true);
    }
}


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



    agregar_array_enteros(lista_ej,  10);
    lista_imprimir_enteros(lista_ej);

    printf("\n");
    lista_borrar_pos_pares(lista_ej);
    lista_imprimir_enteros(lista_ej);
    printf("\n");


    free(lista_ej);
}







void pruebas_lista_alumno() {
    prueba_funcionamiento();
}
