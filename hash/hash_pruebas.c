/*
 * prueba_hash.c
 * Pruebas para el tipo de dato abstracto Tabla de Hash
 * Copyright: (2011) Margarita Manterola, Maximiliano Curia
 * Licencia: CC-BY-SA 2.5 (ar) ó CC-BY-SA 3.0
 */

#include "hash.h"
#include "testing.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // For ssize_t in Linux.



#define ANSI_COLOR_RED     "\x1b[1;31m"
#define ANSI_COLOR_GREEN   "\x1b[1,32m"
#define ANSI_COLOR_YELLOW  "\x1b[1;33m"
#define ANSI_COLOR_BLUE    "\x1b[1;34m"
#define ANSI_COLOR_MAGENTA "\x1b[1;35m"
#define ANSI_COLOR_CYAN    "\x1b[1;36m"
#define ANSI_COLOR_RESET   "\x1b[0m"



/* ******************************************************************
 *                        PRUEBAS UNITARIAS
 * *****************************************************************/

static void prueba_crear_hash_vacio()
{
    hash_t* hash = hash_crear(NULL);
    printf("\n\n#PRUEBAS HASH CREAR VACIO \n\n");
    print_test("\n\tPrueba hash crear hash vacio", hash);
    print_test("\tPrueba hash la cantidad de elementos es 0", hash_cantidad(hash) == 0);
    print_test("\tPrueba hash obtener clave A, es NULL, no existe", !hash_obtener(hash, "A"));
    print_test("\tPrueba hash pertenece clave A, es false, no existe", !hash_pertenece(hash, "A"));
    print_test("\tPrueba hash borrar clave A, es NULL, no existe", !hash_borrar(hash, "A"));

    hash_destruir(hash);
}

static void prueba_iterar_hash_vacio()
{
    hash_t* hash = hash_crear(NULL);
    hash_iter_t* iter = hash_iter_crear(hash);
    printf("\n\n#PRUEBAS HASH ITERAR VACÍO\n\n");
    print_test("\n\tPrueba hash iter crear iterador hash vacio", iter);
    print_test("\tPrueba hash iter esta al final", hash_iter_al_final(iter));
    print_test("\tPrueba hash iter avanzar es false", !hash_iter_avanzar(iter));
    print_test("\tPrueba hash iter ver actual es NULL", !hash_iter_ver_actual(iter));

    hash_iter_destruir(iter);
    hash_destruir(hash);
}

static void prueba_hash_insertar()
{
    hash_t* hash = hash_crear(NULL);

    char *clave1 = "perro", *valor1 = "guau";
    char *clave2 = "gato", *valor2 = "miau";
    char *clave3 = "vaca", *valor3 = "mu";

    printf("\n\n#PRUEBAS HASH INSERTAR\n\n");

    /* Inserta 1 valor y luego lo borra */
    print_test("\n\tPrueba hash insertar clave1", hash_guardar(hash, clave1, valor1));
    print_test("\tPrueba hash la cantidad de elementos es 1", hash_cantidad(hash) == 1);
    print_test("\tPrueba hash obtener clave1 es valor1", hash_obtener(hash, clave1) == valor1);
    print_test("\tPrueba hash obtener clave1 es valor1", hash_obtener(hash, clave1) == valor1);
    print_test("\tPrueba hash pertenece clave1, es true", hash_pertenece(hash, clave1));
    print_test("\tPrueba hash borrar clave1, es valor1", hash_borrar(hash, clave1) == valor1);
    print_test("\tPrueba hash la cantidad de elementos es 0", hash_cantidad(hash) == 0);

    /* Inserta otros 2 valores y no los borra (se destruyen con el hash) */
    print_test("\n\tPrueba hash insertar clave2", hash_guardar(hash, clave2, valor2));
    print_test("\tPrueba hash la cantidad de elementos es 1", hash_cantidad(hash) == 1);
    print_test("\tPrueba hash obtener clave2 es valor2", hash_obtener(hash, clave2) == valor2);
    print_test("\tPrueba hash obtener clave2 es valor2", hash_obtener(hash, clave2) == valor2);
    print_test("\tPrueba hash pertenece clave2, es true", hash_pertenece(hash, clave2));

    print_test("\n\tPrueba hash insertar clave3", hash_guardar(hash, clave3, valor3));
    print_test("\tPrueba hash la cantidad de elementos es 2", hash_cantidad(hash) == 2);
    print_test("\tPrueba hash obtener clave3 es valor3", hash_obtener(hash, clave3) == valor3);
    print_test("\tPrueba hash obtener clave3 es valor3", hash_obtener(hash, clave3) == valor3);
    print_test("\tPrueba hash pertenece clave3, es true", hash_pertenece(hash, clave3));

    hash_destruir(hash);
}

static void prueba_hash_reemplazar()
{
    hash_t* hash = hash_crear(NULL);

    char *clave1 = "perro", *valor1a = "guau", *valor1b = "warf";
    char *clave2 = "gato", *valor2a = "miau", *valor2b = "meaow";

    printf("\n\n#PRUEBAS HASH REEMPLAZAR\n\n");
    /* Inserta 2 valores y luego los reemplaza */
    print_test("\n\tPrueba hash insertar clave1", hash_guardar(hash, clave1, valor1a));
    print_test("\tPrueba hash obtener clave1 es valor1a", hash_obtener(hash, clave1) == valor1a);
    print_test("\tPrueba hash obtener clave1 es valor1a", hash_obtener(hash, clave1) == valor1a);
    print_test("\tPrueba hash insertar clave2", hash_guardar(hash, clave2, valor2a));
    print_test("\tPrueba hash obtener clave2 es valor2a", hash_obtener(hash, clave2) == valor2a);
    print_test("\tPrueba hash obtener clave2 es valor2a", hash_obtener(hash, clave2) == valor2a);
    print_test("\tPrueba hash la cantidad de elementos es 2", hash_cantidad(hash) == 2);

    print_test("\n\tPrueba hash insertar clave1 con otro valor", hash_guardar(hash, clave1, valor1b));
    print_test("\tPrueba hash obtener clave1 es valor1b", hash_obtener(hash, clave1) == valor1b);
    print_test("\tPrueba hash obtener clave1 es valor1b", hash_obtener(hash, clave1) == valor1b);
    print_test("\tPrueba hash insertar clave2 con otro valor", hash_guardar(hash, clave2, valor2b));
    print_test("\tPrueba hash obtener clave2 es valor2b", hash_obtener(hash, clave2) == valor2b);
    print_test("\tPrueba hash obtener clave2 es valor2b", hash_obtener(hash, clave2) == valor2b);
    print_test("\tPrueba hash la cantidad de elementos es 2", hash_cantidad(hash) == 2);

    hash_destruir(hash);
}

static void prueba_hash_reemplazar_con_destruir()
{
    hash_t* hash = hash_crear(free);

    char *clave1 = "perro", *valor1a, *valor1b;
    char *clave2 = "gato", *valor2a, *valor2b;

    /* Pide memoria para 4 valores */
    valor1a = malloc(10 * sizeof(char));
    valor1b = malloc(10 * sizeof(char));
    valor2a = malloc(10 * sizeof(char));
    valor2b = malloc(10 * sizeof(char));

    printf("\n\n#PRUEBAS HASH REEMPLAZAR CON DESTRUIR \n\n");
    /* Inserta 2 valores y luego los reemplaza (debe liberar lo que reemplaza) */
    print_test("\n\tPrueba hash insertar clave1", hash_guardar(hash, clave1, valor1a));
    print_test("\tPrueba hash obtener clave1 es valor1a", hash_obtener(hash, clave1) == valor1a);
    print_test("\tPrueba hash obtener clave1 es valor1a", hash_obtener(hash, clave1) == valor1a);
    print_test("\tPrueba hash insertar clave2", hash_guardar(hash, clave2, valor2a));
    print_test("\tPrueba hash obtener clave2 es valor2a", hash_obtener(hash, clave2) == valor2a);
    print_test("\tPrueba hash obtener clave2 es valor2a", hash_obtener(hash, clave2) == valor2a);
    print_test("\tPrueba hash la cantidad de elementos es 2", hash_cantidad(hash) == 2);

    print_test("\n\tPrueba hash insertar clave1 con otro valor", hash_guardar(hash, clave1, valor1b));
    print_test("\tPrueba hash obtener clave1 es valor1b", hash_obtener(hash, clave1) == valor1b);
    print_test("\tPrueba hash obtener clave1 es valor1b", hash_obtener(hash, clave1) == valor1b);
    print_test("\tPrueba hash insertar clave2 con otro valor", hash_guardar(hash, clave2, valor2b));
    print_test("\tPrueba hash obtener clave2 es valor2b", hash_obtener(hash, clave2) == valor2b);
    print_test("\tPrueba hash obtener clave2 es valor2b", hash_obtener(hash, clave2) == valor2b);
    print_test("\tPrueba hash la cantidad de elementos es 2", hash_cantidad(hash) == 2);

    /* Se destruye el hash (se debe liberar lo que quedó dentro) */
    hash_destruir(hash);
}

static void prueba_hash_borrar()
{
    hash_t* hash = hash_crear(NULL);

    char *clave1 = "perro", *valor1 = "guau";
    char *clave2 = "gato", *valor2 = "miau";
    char *clave3 = "vaca", *valor3 = "mu";

    printf("\n\n#PRUEBAS HASH BORRAR \n\n");
    /* Inserta 3 valores y luego los borra */
    print_test("\n\tPrueba hash insertar clave1", hash_guardar(hash, clave1, valor1));
    print_test("\tPrueba hash insertar clave2", hash_guardar(hash, clave2, valor2));
    print_test("\tPrueba hash insertar clave3", hash_guardar(hash, clave3, valor3));

    /* Al borrar cada elemento comprueba que ya no está pero los otros sí. */
    print_test("\n\tPrueba hash pertenece clave3, es verdadero", hash_pertenece(hash, clave3));
    print_test("\tPrueba hash borrar clave3, es valor3", hash_borrar(hash, clave3) == valor3);
    print_test("\tPrueba hash borrar clave3, es NULL", !hash_borrar(hash, clave3));
    print_test("\tPrueba hash pertenece clave3, es falso", !hash_pertenece(hash, clave3));
    print_test("\tPrueba hash obtener clave3, es NULL", !hash_obtener(hash, clave3));
    print_test("\tPrueba hash la cantidad de elementos es 2", hash_cantidad(hash) == 2);

    print_test("\n\tPrueba hash pertenece clave1, es verdadero", hash_pertenece(hash, clave1));
    print_test("\tPrueba hash borrar clave1, es valor1", hash_borrar(hash, clave1) == valor1);
    print_test("\tPrueba hash borrar clave1, es NULL", !hash_borrar(hash, clave1));
    print_test("\tPrueba hash pertenece clave1, es falso", !hash_pertenece(hash, clave1));
    print_test("\tPrueba hash obtener clave1, es NULL", !hash_obtener(hash, clave1));
    print_test("\tPrueba hash la cantidad de elementos es 1", hash_cantidad(hash) == 1);

    print_test("\n\tPrueba hash pertenece clave2, es verdadero", hash_pertenece(hash, clave2));
    print_test("\tPrueba hash borrar clave2, es valor2", hash_borrar(hash, clave2) == valor2);
    print_test("\tPrueba hash borrar clave2, es NULL", !hash_borrar(hash, clave2));
    print_test("\tPrueba hash pertenece clave2, es falso", !hash_pertenece(hash, clave2));
    print_test("\tPrueba hash obtener clave2, es NULL", !hash_obtener(hash, clave2));
    print_test("\tPrueba hash la cantidad de elementos es 0", hash_cantidad(hash) == 0);

    hash_destruir(hash);
}

static void prueba_hash_clave_vacia()
{
    hash_t* hash = hash_crear(NULL);

    char *clave = "", *valor = "";
    printf("\n\n#PRUEBAS HASH CLAVE VACIA\n\n");
    print_test("\n\tPrueba hash insertar clave vacia", hash_guardar(hash, clave, valor));
    print_test("\tPrueba hash la cantidad de elementos es 1", hash_cantidad(hash) == 1);
    print_test("\tPrueba hash obtener clave vacia es valor", hash_obtener(hash, clave) == valor);
    print_test("\tPrueba hash pertenece clave vacia, es true", hash_pertenece(hash, clave));
    print_test("\tPrueba hash borrar clave vacia, es valor", hash_borrar(hash, clave) == valor);
    print_test("\tPrueba hash la cantidad de elementos es 0", hash_cantidad(hash) == 0);

    hash_destruir(hash);
}

static void prueba_hash_valor_null()
{
    hash_t* hash = hash_crear(NULL);

    char *clave = "", *valor = NULL;
    printf("\n\n#PRUEBAS HASH VALOR NULL\n\n");
    /* Inserta 1 valor y luego lo borra */
    print_test("\n\tPrueba hash insertar clave vacia valor NULL", hash_guardar(hash, clave, valor));
    print_test("\tPrueba hash la cantidad de elementos es 1", hash_cantidad(hash) == 1);
    print_test("\tPrueba hash obtener clave vacia es valor NULL", hash_obtener(hash, clave) == valor);
    print_test("\tPrueba hash pertenece clave vacia, es true", hash_pertenece(hash, clave));
    print_test("\tPrueba hash borrar clave vacia, es valor NULL", hash_borrar(hash, clave) == valor);
    print_test("\tPrueba hash la cantidad de elementos es 0", hash_cantidad(hash) == 0);

    hash_destruir(hash);
}

static void prueba_hash_volumen(size_t largo, bool debug)
{
    printf("\n\n#PRUEBAS HASH VOLUMEN\n\n");
    hash_t* hash = hash_crear(NULL);

    const size_t largo_clave = 10;
    char (*claves)[largo_clave] = malloc(largo * largo_clave);

    unsigned* valores[largo];

    /* Inserta 'largo' parejas en el hash */
    bool ok = true;
    for (unsigned i = 0; i < largo; i++) {
        valores[i] = malloc(sizeof(int));
        sprintf(claves[i], "%08d", i);
        *valores[i] = i;
        printf("\n\tDEBUG - Mandó clave: %s  \n", claves[i]);
        ok = hash_guardar(hash, claves[i], valores[i]);
        if (!ok) break;
    }
    
    if (debug) print_test("\n\tPrueba hash almacenar muchos elementos", ok);
    if (debug) print_test("\tPrueba hash la cantidad de elementos es correcta", hash_cantidad(hash) == largo);
    printf("\nDEBUG - Cantidad es = %lu y el largo es = %lu", hash_cantidad(hash), largo);
    /* Verifica que devuelva los valores correctos */
    for (size_t i = 0; i < largo; i++) {
        ok = hash_pertenece(hash, claves[i]);
        if (!ok) break;
        ok = hash_obtener(hash, claves[i]) == valores[i];
        if (!ok) break;
    }

    if (debug) print_test("\n\tPrueba hash pertenece y obtener muchos elementos", ok);
    if (debug) print_test("\tPrueba hash la cantidad de elementos es correcta", hash_cantidad(hash) == largo);

    /* Verifica que borre y devuelva los valores correctos */
    for (size_t i = 0; i < largo; i++) {
        ok = hash_borrar(hash, claves[i]) == valores[i];
        if (!ok) break;
    }

    if (debug) print_test("\n\tPrueba hash borrar muchos elementos", ok);
    if (debug) print_test("\tPrueba hash la cantidad de elementos es 0", hash_cantidad(hash) == 0);
    printf("\nDEBUG - Cantidad es = %lu\n", hash_cantidad(hash));

    /* Destruye el hash y crea uno nuevo que sí libera */
    hash_destruir(hash);
    hash = hash_crear(free);

    /* Inserta 'largo' parejas en el hash */
    ok = true;
    for (size_t i = 0; i < largo; i++) {
        ok = hash_guardar(hash, claves[i], valores[i]);
        if (!ok) break;
    }

    free(claves);

    /* Destruye el hash - debería liberar los enteros */
    hash_destruir(hash);

}
static ssize_t buscar(const char* clave, char* claves[], size_t largo)
{
    for (size_t i = 0; i < largo; i++) {
        if (strcmp(clave, claves[i]) == 0) return (ssize_t) i;
    }
    return -1;
}

static void prueba_hash_iterar()
{
    hash_t* hash = hash_crear(NULL);

    char *claves[] = {"perro", "gato", "vaca"};
    char *valores[] = {"guau", "miau", "mu"};

    printf("\n\n#PRUEBAS HASH ITERAR\n\n");
    /* Inserta 3 valores */
    print_test("\n\tPrueba hash insertar clave1", hash_guardar(hash, claves[0], valores[0]));
    print_test("\tPrueba hash insertar clave2", hash_guardar(hash, claves[1], valores[1]));
    print_test("\tPrueba hash insertar clave3", hash_guardar(hash, claves[2], valores[2]));

    // Prueba de iteración sobre las claves almacenadas.
    hash_iter_t* iter = hash_iter_crear(hash);
    const char *clave;
    ssize_t indice;

    print_test("\n\tPrueba hash iterador esta al final, es false", !hash_iter_al_final(iter));

    /* Primer valor */
    clave = hash_iter_ver_actual(iter);
    indice = buscar(clave, claves, sizeof(claves) / sizeof(char *));
    print_test("\n\tPrueba hash iterador ver actual, es una clave valida", indice != -1);
    print_test("\tPrueba hash iterador ver actual, no es el mismo puntero", clave != claves[indice]);
    print_test("\tPrueba hash iterador avanzar es true", hash_iter_avanzar(iter));
    print_test("\tPrueba hash iterador esta al final, es false", !hash_iter_al_final(iter));

     /* Segundo valor */
    clave = hash_iter_ver_actual(iter);
    indice = buscar(clave, claves, sizeof(claves) / sizeof(char *));
    print_test("\n\tPrueba hash iterador ver actual, es una clave valida", indice != -1);
    print_test("\tPrueba hash iterador ver actual, no es el mismo puntero", clave != claves[indice]);
    print_test("\tPrueba hash iterador avanzar es true", hash_iter_avanzar(iter));
    print_test("\tPrueba hash iterador esta al final, es false", !hash_iter_al_final(iter));

    /* Tercer valor */
    clave = hash_iter_ver_actual(iter);
    indice = buscar(clave, claves, sizeof(claves) / sizeof(char *));
    print_test("\n\tPrueba hash iterador ver actual, es una clave valida", indice != -1);
    print_test("\tPrueba hash iterador ver actual, no es el mismo puntero", clave != claves[indice]);
    hash_iter_avanzar(iter);
    print_test("\tPrueba hash iterador esta al final, es true", hash_iter_al_final(iter));

    // /* Vuelve a tratar de avanzar, por las dudas */
    print_test("\n\tPrueba hash iterador ver actual, es NULL", !hash_iter_ver_actual(iter));
    print_test("\tPrueba hash iterador avanzar es false", !hash_iter_avanzar(iter));
    print_test("\tPrueba hash iterador esta al final, es true", hash_iter_al_final(iter));
 
    hash_iter_destruir(iter);
    hash_destruir(hash);
}

static void prueba_hash_iterar_volumen(size_t largo)
{
    hash_t* hash = hash_crear(NULL);

    const size_t largo_clave = 10;
    char (*claves)[largo_clave] = malloc(largo * largo_clave);

    size_t valores[largo];

    /* Inserta 'largo' parejas en el hash */
    bool ok = true;
    for (unsigned i = 0; i < largo; i++) {
        sprintf(claves[i], "%08d", i);
        valores[i] = i;
        ok = hash_guardar(hash, claves[i], &valores[i]);
        if (!ok) break;
    }

    printf("\n\n#PRUEBAS HASH ITERAR CON VOLUMEN\n\n");
    // Prueba de iteración sobre las claves almacenadas.
    hash_iter_t* iter = hash_iter_crear(hash);
    print_test("\n\tPrueba hash iterador esta al final, es false", !hash_iter_al_final(iter));

    ok = true;
    unsigned i;
    const char *clave;
    size_t *valor;

    for (i = 0; i < largo; i++) {
        if ( hash_iter_al_final(iter) ) {
            ok = false;
            break;
        }
        clave = hash_iter_ver_actual(iter);
        if ( clave == NULL ) {
            ok = false;
            break;
        }
        valor = hash_obtener(hash, clave);
        if ( valor == NULL ) {
            ok = false;
            break;
        }
        *valor = largo;
        hash_iter_avanzar(iter);
    }
    print_test("\n\tPrueba hash iteración en volumen", ok);
    print_test("\tPrueba hash iteración en volumen, recorrio todo el largo", i == largo);
    print_test("\tPrueba hash iterador esta al final, es true", hash_iter_al_final(iter));

    ok = true;
    for (i = 0; i < largo; i++) {
        if ( valores[i] != largo ) {
            ok = false;
            break;
        }
    }
    print_test("\tPrueba hash iteración en volumen, se cambiaron todo los elementos", ok);

    free(claves);
    hash_iter_destruir(iter);
    hash_destruir(hash);
}

/* ******************************************************************
 *                        FUNCIÓN PRINCIPAL
 * *****************************************************************/


void pruebas_hash_catedra()
{
    /* Ejecuta todas las pruebas unitarias. */
    prueba_crear_hash_vacio();
    prueba_iterar_hash_vacio();
    prueba_hash_insertar();
    prueba_hash_reemplazar();
    prueba_hash_reemplazar_con_destruir();
    prueba_hash_borrar();
    prueba_hash_clave_vacia();
    prueba_hash_valor_null();
    prueba_hash_volumen(50, true);
    prueba_hash_iterar();
    prueba_hash_iterar_volumen(50);
}

void pruebas_volumen_catedra(size_t largo)
{
    prueba_hash_volumen(largo, false);
}
