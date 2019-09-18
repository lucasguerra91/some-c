#include "lista.h"
#include "testing.h"
#include <stddef.h>
#include "stdio.h"

/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void pruebas_lista_alumno() {
//    lista_t prueba = lista_crear();
//    print_test("Verifica si la lista esta vacia", lista_esta_vacia(prueba) == true);
//
//    free(prueba);
        //int numero = 2;
//        nodo_t* nodo = crear_nodo(&numero);
//        mostrar_nodo(nodo);
//        free(nodo);

        lista_t* lista_ej = lista_crear();
        print_test("Lista esta vacia? ", lista_esta_vacia(lista_ej) == true);

        free(lista_ej);
}
