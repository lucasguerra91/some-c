#include "cola.h"
#include "testing.h"
#include <stddef.h>
#include "stdio.h"

/* ----------------- FUNCIONES AUXILIARES -----------*/

void encolar_array_enteros(cola_t* cola, int cant){
    printf("\n\n--- Encolando %d elementos ---\n", cant);

    int vector[cant];

    for (int j = 0; j < cant ; j++) {
        vector[j] = j;
    }

    for (int i = 0; i < cant ; i++) {
        print_test("Encolar ", cola_encolar(cola, &vector[i]) == true);
    }
}

void desencolar_elementos(cola_t* cola, int cant){

    printf("\n\n--- Desencolando %d elementos ---\n", cant);

    for (int i = 0; i < cant ; i++) {
        print_test("Desencolar ", cola_ver_primero(cola) == cola_desencolar(cola));
    }
}

void verificar_vacia(cola_t* cola){
    print_test("\nCola esta vacía? ", cola_esta_vacia(cola) == true);
}


/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/


void pruebas_cola_alumno() {

        cola_t* cola_ej = cola_crear(); // Creación de la cola

        verificar_vacia(cola_ej);

        int numero = 10;    // Encolar con cola vacía
        print_test("Encolar en cola vacía ", cola_encolar(cola_ej, &numero) == true);

        print_test("Verificar que primero sea 10 ", *((int *)cola_ver_primero(cola_ej)) == 10);

        encolar_array_enteros(cola_ej, 10); // Encolar n enteros
        print_test("\nVerificar que primero sea 10 ", *((int *)cola_ver_primero(cola_ej)) == 10);

        print_test("Desencolar el primero ", *((int *)cola_desencolar(cola_ej)) == 10);

        desencolar_elementos(cola_ej, 10); // Desencolar hasta lo ultimo
        print_test("\nCola esta vacía? ", cola_esta_vacia(cola_ej) == true); // Estado = vacia

        print_test("Desencolar vacía = NULL", cola_desencolar(cola_ej) == NULL); // No se puede

        //print_test("Destruir cola (NULL)", cola_destruir(cola_ej, &free) == true);
        cola_destruir(cola_ej, NULL);

        print_test("\nCola existe? ", (cola_ej == NULL) == true); // Estado = no existe
        //print_test("Desencolar vacía = NULL", cola_desencolar(cola_ej) == NULL); // No se puede
}
