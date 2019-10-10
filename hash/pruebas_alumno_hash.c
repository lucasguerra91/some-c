#include "hash.h"
#include "testing.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void prueba_crear_hash_vacio()
{
    hash_t* hash = hash_crear(NULL);
    printf("\n\nPRUEBAS DE CARGA DE DATOS EN HASH\n\n");

    print_test("\n\tCrea hash vacío.", hash);
    print_test("\tCantidad de elementos es 0", hash_cantidad(hash) == 0);

    print_test("\n\tObtener clave A, es NULL, no existe", !hash_obtener(hash, "A"));
    print_test("\tPertenece clave A, es false, no existe", !hash_pertenece(hash, "A"));
    print_test("\tBorrar clave A, es NULL, no existe", !hash_borrar(hash, "A"));

    hash_destruir(hash);
}


void prueba_guardar_hash(){

    hash_t* hash = hash_crear(NULL);

    char *clave1 = "perro", *valor1 = "guau", *valor1a = "guau2", *valor1b = "guau3";

    char *clave2 = "gaton", *valor2 = "miau";

    char *clave3 = "caca", *valor3 = "mu";


    printf("\n\nPRUEBAS DE CARGA DE DATOS EN HASH\n\n");

    // Inserto clave1 , lo actualiza, lo borra y vuelve a insertar
    print_test("\n\tInsertar clave1", hash_guardar(hash, clave1, valor1));
    print_test("\tLa cantidad de elementos es 1", hash_cantidad(hash) == 1);
    print_test("\tObtener clave1 es valor1", hash_obtener(hash, clave1) == valor1);

    print_test("\n\tInsertar clave1a", hash_guardar(hash, clave1, valor1a));
    print_test("\tLa cantidad de elementos es 1", hash_cantidad(hash) == 1);

    print_test("\n\tAl borrar clave1 devuelve valor1a", hash_borrar(hash, clave1) == valor1a);
    print_test("\tPrueba hash la cantidad de elementos es 0", hash_cantidad(hash) == 0);

    print_test("\n\tInsertar clave1b", hash_guardar(hash, clave1, valor1b));
    print_test("\tLa cantidad de elementos es 1", hash_cantidad(hash) == 1);
    print_test("\tPertenece clave1, es true", hash_pertenece(hash, clave1));
    print_test("\tObtener clave1 es valor1b", hash_obtener(hash, clave1) == valor1b);

    // Inserto clave2 y verifico
    print_test("\n\tInsertar clave2", hash_guardar(hash, clave2, valor2));
    print_test("\tLa cantidad de elementos es 2", hash_cantidad(hash) == 2);
    print_test("\tObtener clave2 es valor2", hash_obtener(hash, clave2) == valor2);
    print_test("\tpertenece clave2, es true", hash_pertenece(hash, clave2));

    // Inserto clave 3, la borro y la vuelvo a insertar
    print_test("\n\tInsertar clave3", hash_guardar(hash, clave3, valor3));
    print_test("\tLa cantidad de elementos es 3", hash_cantidad(hash) == 3);
    print_test("\tObtener clave3 es valor3", hash_obtener(hash, clave3) == valor3);
    print_test("\tPertenece clave3, es true", hash_pertenece(hash, clave3));

    print_test("\n\tAl borrar clave3 devuelve valor3", hash_borrar(hash, clave3) == valor3);

    print_test("\n\tInsertar clave3", hash_guardar(hash, clave3, valor3));
    print_test("\tLa cantidad de elementos es 3", hash_cantidad(hash) == 3);
    print_test("\tObtener clave3 es valor3", hash_obtener(hash, clave3) == valor3);
    print_test("\tPertenece clave3, es true", hash_pertenece(hash, clave3));


    // Libera
    hash_destruir(hash);
}

void pruebas_hash_alumno(){
    prueba_crear_hash_vacio();
    prueba_guardar_hash();
}