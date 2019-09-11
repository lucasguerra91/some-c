#include "pila.h"
#include "testing.h"
#include <stddef.h>
#include "stdio.h"

/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void pruebas_pila_alumno() {
    pila_t* ejemplo = NULL;
    print_test("\nPuntero inicializado a NULL", ejemplo == NULL);

    ejemplo = pila_crear();
    print_test("\nCreando una pila", ejemplo != NULL);

    print_test("\nConsulta si esta vacia == TRUE", pila_esta_vacia(ejemplo) == true);

    int valor = 10;
    print_test("\nAgregar elemento a pila vacía", pila_apilar(ejemplo, &valor) == true);
    print_test("\nConsulta si esta vacia = FALSE", pila_esta_vacia(ejemplo) == false);

    int valor2 = 100;
    print_test("\nAgregar elemento 100 a pila no vacía", pila_apilar(ejemplo, &valor2) == true);
    print_test("\nConsulta si esta vacía = FALSE", pila_esta_vacia(ejemplo) == false);

    void* tope = pila_ver_tope(ejemplo);
    printf("%p", tope);
    // print_test("\nVer elemento en tope (100)", *tope == valor2);

    pila_destruir(ejemplo);
    //print_test("Destruye una pila", pila1 != *void);
}
