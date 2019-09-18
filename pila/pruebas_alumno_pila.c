#include "pila.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>

/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void pruebas_pila_alumno() {

    pila_t* ejemplo = NULL;
    print_test("\nPuntero inicializado a NULL ", ejemplo == NULL);

    printf("\n--- Manipulando la pila ---\n");

    ejemplo = pila_crear();
    print_test("\nCreando una pila ", ejemplo != NULL);
    print_test("Consulta si esta vacia == TRUE ",  pila_esta_vacia(ejemplo) == true);


    int valor = 10;
    print_test("\nApila 10 en pila vacía ", pila_apilar(ejemplo, &valor) == true);
    print_test("Esta vacía == FALSE ", pila_esta_vacia(ejemplo) == false);
    print_test("Tope == 10 ", *((int *)pila_ver_tope(ejemplo)) == 10);
    //print_test("Cantidad de elementos en la pila == 1 ", (int)pila_ver_cantidad(ejemplo) == 1);
    //print_test("Capacidad de la pila = 1 ", (int)pila_ver_capacidad(ejemplo) == 1);


    int valor2 = 100;
    print_test("\nApila 100 en pila no vacía ", pila_apilar(ejemplo, &valor2) == true);
    print_test("Esta vacía = FALSE ", pila_esta_vacia(ejemplo) == false);
    print_test("Tope == 100 ", *((int *)pila_ver_tope(ejemplo)) == 100);
    //print_test("Cantidad de elementos en la pila == 2 ", (int)pila_ver_cantidad(ejemplo) == 2);
    //print_test("Capacidad de la pila = 2 ", (int)pila_ver_capacidad(ejemplo) == 2);


    int valor3 = 1000;
    print_test("\nApila 1000 en pila no vacía ", pila_apilar(ejemplo, &valor3) == true);
    print_test("Está vacía = FALSE ", pila_esta_vacia(ejemplo) == false);
    print_test("Tope == 1000 ", *((int *)pila_ver_tope(ejemplo)) == 1000);
    //print_test("Cantidad de elementos en la pila == 3 ", (int)pila_ver_cantidad(ejemplo) == 3);
    //print_test("Capacidad de la pila = 4 ", (int)pila_ver_capacidad(ejemplo) == 4);



    print_test("\nDesapila 1000 ", *((int *)pila_desapilar(ejemplo)) == 1000);
    print_test("Tope == 100 ", *((int *)pila_ver_tope(ejemplo)) == 100);
    //print_test("Cantidad de elementos en la pila == 2 ", (int)pila_ver_cantidad(ejemplo) == 2);
    //print_test("Capacidad de la pila = 4 ", (int)pila_ver_capacidad(ejemplo) == 4);

    print_test("\nDesapila 100 ", *((int *)pila_desapilar(ejemplo)) == 100);
    print_test("Tope == 10 ", *((int *)pila_ver_tope(ejemplo)) == 10);
    //print_test("Cantidad de elementos en la pila == 1 ", (int)pila_ver_cantidad(ejemplo) == 1);
    //print_test("Capacidad de la pila = 4 ", (int)pila_ver_capacidad(ejemplo) == 4);

    print_test("\nDesapila 10 ", *((int *)pila_desapilar(ejemplo)) == 10);
    //print_test("Cantidad de elementos en la pila == 0 ", (int)pila_ver_cantidad(ejemplo) == 0);
    //print_test("Capacidad de la pila = 1 (Como recien creada) ", (int)pila_ver_capacidad(ejemplo) == 1);
    print_test("Tope == NULL / No se permite ver tope. ", pila_ver_tope(ejemplo) == NULL);
    print_test("Está vacia = TRUE ", pila_esta_vacia(ejemplo) == true);


    printf("\n\n--- Agregando 1000 elementos ---\n");

    int vector[1000];

    for (int j = 0; j < 1000 ; j++) {
        vector[j] = j;
    }

    for (int i = 0; i < 1000 ; i++) {
        pila_apilar(ejemplo, &vector[i]);
    }


    //print_test("\nCantidad de elementos en la pila == 1000 ", (int)pila_ver_cantidad(ejemplo) == 1000);
    print_test("El nuevo tope de la pila es 999 (pila[0]=0)", *((int *)pila_ver_tope(ejemplo)) == 999);

    //pila_imprimir(ejemplo);

    printf("\n\n--- Borrando 1000 elementos ---\n");
    for (int i = 0; i < 1000; i++) {
        pila_desapilar(ejemplo);
        //printf("Se desapiló %u", *(int *)aux);
    }

    print_test("\nEl nuevo tope de la pila es NULL / No se permite ", pila_ver_tope(ejemplo) == NULL);
    print_test("Consulta si esta vacia = TRUE ", pila_esta_vacia(ejemplo) == true);


    printf("\n\n--- Agregando Null ---\n");
    print_test("\nAgregar elemento NULL a pila vacía ", pila_apilar(ejemplo, NULL) == true);
    print_test("El nuevo tope de la pila es NULL ", pila_ver_tope(ejemplo) == NULL);

    print_test("\nDesapilar el elemento NULL ", pila_desapilar(ejemplo) == 0);
    print_test("Consulta si esta vacia = TRUE ", pila_esta_vacia(ejemplo) == true);

    //print_test("\nCantidad de elementos en la pila == 0 ", (int)pila_ver_cantidad(ejemplo) == 0);
    //print_test("Capacidad de la pila = 1 (Como recién creada) ", (int)pila_ver_capacidad(ejemplo) == 1);



    // ojo con no liberar la pila, ja
    printf("\n\nBorrando pila y liberando memoria..\n");
    pila_destruir(ejemplo);
    printf("Fin\n");

}
