#include "pila.h"
#include "testing.h"
#include <stddef.h>
#include "stdio.h"

/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void pruebas_pila_alumno() {
    pila_t* ejemplo = NULL;
    print_test("Puntero inicializado a NULL ", ejemplo == NULL);

    ejemplo = pila_crear();
    print_test("Creando una pila ", ejemplo != NULL);

    print_test("Consulta si esta vacia == TRUE ",  pila_esta_vacia(ejemplo) == true);

    int valor = 10;
    print_test("Agregar elemento 10 a pila vacía ", pila_apilar(ejemplo, &valor) == true);
    print_test("Consulta si esta vacia = FALSE ", pila_esta_vacia(ejemplo) == false);
    print_test("El tope de la pila es 10 ", *((int *)pila_ver_tope(ejemplo)) == 10);

    //imprimir_pila(ejemplo);
    //printf("\nTope = %u\n", *((int *)pila_ver_tope(ejemplo)));


    int valor2 = 100;
    print_test("Agregar elemento 100 a pila no vacía ", pila_apilar(ejemplo, &valor2) == true);
    print_test("Consulta si esta vacía = FALSE ", pila_esta_vacia(ejemplo) == false);
    print_test("El tope de la pila es 100 ", *((int *)pila_ver_tope(ejemplo)) == 100);


    print_test("Desapilar el elemento 100 ", *((int *)pila_desapilar(ejemplo)) == 100);
    print_test("El nuevo tope de la pila es 10 ", *((int *)pila_ver_tope(ejemplo)) == 10);

    print_test("Desapilar el elemento 10 ", *((int *)pila_desapilar(ejemplo)) == 10);
    print_test("El nuevo tope de la pila es NULL / No se permite ", pila_ver_tope(ejemplo) == NULL);

    print_test("Consulta si esta vacia = TRUE ", pila_esta_vacia(ejemplo) == true);

    //imprimir_pila(ejemplo);
    //printf("\nTope = %u\n", *((int *)pila_ver_tope(ejemplo)));

    printf("Agregando 1000 elementos.. \n");
    int vector[1000];

    for (int j = 0; j < 1001 ; j++) {
        vector[j] = j;
    }


    for (int i = 0; i < 1001 ; i++) {
        pila_apilar(ejemplo, &vector[i]);
    }

    size_t cantidad = pila_ver_cantidad(ejemplo);
    printf("Cantidad actual : %d", (int)cantidad);


    print_test("El nuevo tope de la pila es 1000 ", *((int *)pila_ver_tope(ejemplo)) == 1000);

    //pila_imprimir(ejemplo);

    printf("Borrando 1000 elementos.. \n");
    for (int i = 0; i < 1001; i++) {
        pila_desapilar(ejemplo);
        //printf("Se desapiló %u", *(int *)aux);
    }

    print_test("El nuevo tope de la pila es NULL / No se permite ", pila_ver_tope(ejemplo) == NULL);
    print_test("Consulta si esta vacia = TRUE ", pila_esta_vacia(ejemplo) == true);

    print_test("Agregar elemento NULL a pila vacía ", pila_apilar(ejemplo, NULL) == true);
    print_test("El nuevo tope de la pila es NULL ", pila_ver_tope(ejemplo) == NULL);

    print_test("Desapilar el elemento NULL ", pila_desapilar(ejemplo) == 0);
    print_test("Consulta si esta vacia = TRUE ", pila_esta_vacia(ejemplo) == true);


    size_t cantidad2 = pila_ver_cantidad(ejemplo);
    printf("Cantidad actual : %d", (int)cantidad2);


    // ojo con no liberar la pila, ja
    pila_destruir(ejemplo);

    
}
