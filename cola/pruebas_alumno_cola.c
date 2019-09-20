#include "cola.h"
#include "pila.h"
#include "testing.h"

#include <stddef.h>
#include <stdio.h>


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


void pila_destruir_wrapper(void* elemento){
    void pila_destruir(pila_t* elemento );
}


void cargar_pila(pila_t* pila, int n){
    int vector[n];

    for (int j = 0; j < n ; j++) {
        vector[j] = j;
    }

    for (int i = 0; i < n ; i++) {
        pila_apilar(pila, &vector[i]);
    }
}


void encolar_pilas(cola_t* cola, pila_t* pila, int cant){
    for (int i = 0; i < cant; i++) {
        print_test("Encolar pila ", cola_encolar(cola, pila) == true);
    }
}

void mi_free(void* elemento){
    free(elemento);
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
        print_test("Encolar en cola vacía ", cola_encolar(cola_ej, &numero) == true);

        encolar_array_enteros(cola_ej, 10); // Encolar n enteros
        desencolar_elementos(cola_ej, 5); // Desencolar hasta lo ultimo
        encolar_array_enteros(cola_ej, 1); // Encolar n enteros
        desencolar_elementos(cola_ej, 15); // Desencolar hasta lo ultimo
        //Se destruye la cola actual
        cola_destruir(cola_ej, free);


        cola_t* cola_ej2 = cola_crear(); // Creación de la cola

        verificar_vacia(cola_ej2);

        int numero2 = 10;    // Encolar con cola vacía
        print_test("Encolar en cola vacía ", cola_encolar(cola_ej2, &numero2) == true);
        print_test("Verificar que primero sea 10 ", *((int *)cola_ver_primero(cola_ej2)) == 10);

        encolar_array_enteros(cola_ej2, 10); // Encolar n enteros
        print_test("\nVerificar que primero sea 10 ", *((int *)cola_ver_primero(cola_ej2)) == 10);

        print_test("Desencolar el primero ", *((int *)cola_desencolar(cola_ej2)) == 10);

        desencolar_elementos(cola_ej2, 10); // Desencolar hasta lo ultimo
        print_test("\nCola esta vacía? ", cola_esta_vacia(cola_ej2)== true); // Estado = vacia
        print_test("Desencolar vacía = NULL", cola_desencolar(cola_ej2) == NULL); // No se puede
        print_test("Encolar en cola vacía ", cola_encolar(cola_ej2, &numero2) == true);

        encolar_array_enteros(cola_ej2, 10); // Encolar n enteros
        desencolar_elementos(cola_ej2, 5); // Desencolar hasta lo ultimo
        encolar_array_enteros(cola_ej2, 1); // Encolar n enteros
        desencolar_elementos(cola_ej2, 15); // Desencolar hasta lo ultimo
        //Se destruye la cola actual
        cola_destruir(cola_ej2, mi_free);


/* ******************************************************************
 *                   CARGA DE PILA
 * *****************************************************************/

        pila_t* pila = pila_crear();
        cargar_pila(pila, 5);

        cola_t* cola_ej3 = cola_crear();
        print_test("\nEncolar pila en cola vacía ", cola_encolar(cola_ej3, pila) == true);

        print_test("Encolar pila ", cola_encolar(cola_ej3, pila) == true);
        print_test("Encolar pila ", cola_encolar(cola_ej3, pila) == true);
        print_test("Encolar pila ", cola_encolar(cola_ej3, pila) == true);
        encolar_pilas(cola_ej3, pila, 10);
//        print_test("\nVerificar que primero sea una pila ", cola_ver_primero(cola_ej3) == pila);
        print_test("Desencolar ", cola_ver_primero(cola_ej3) == cola_desencolar(cola_ej3));
        print_test("Desencolar ", cola_ver_primero(cola_ej3) == cola_desencolar(cola_ej3));
        print_test("Desencolar ", cola_ver_primero(cola_ej3) == cola_desencolar(cola_ej3));

        //Se destruye la cola de pilas con el wrapper
        cola_destruir(cola_ej3, pila_destruir_wrapper);

        // libero la pila
        pila_destruir(pila);




    }
