#include "hash.h"
#include "testing.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void prueba_crear_hash_vacio()
{
    hash_t* hash = hash_crear(NULL);

    print_test("Prueba hash crear hash vacio", hash);
    print_test("Prueba hash la cantidad de elementos es 0", hash_cantidad(hash) == 0);

//    print_test("Prueba hash obtener clave A, es NULL, no existe", !hash_obtener(hash, "A"));
//    print_test("Prueba hash pertenece clave A, es false, no existe", !hash_pertenece(hash, "A"));
//    print_test("Prueba hash borrar clave A, es NULL, no existe", !hash_borrar(hash, "A"));

//    hash_destruir(hash);
    free(hash);
}


void prueba_guardar_hash(){
    hash_t* hash = hash_crear(NULL);

    char *clave1 = "perro", *valor1 = "guau";
    char *clave2 = "gato", *valor2 = "miau";
    char *clave3 = "vaca", *valor3 = "mu";

    /* Inserta 1 valor y luego lo borra */
    print_test("Prueba hash insertar clave1", hash_guardar(hash, clave1, valor1));
    print_test("Prueba hash la cantidad de elementos es 1", hash_cantidad(hash) == 1);
    print_test("Prueba hash obtener clave1 es valor1", hash_obtener(hash, clave1) == valor1);

    print_test("Prueba hash pertenece clave1, es true", hash_pertenece(hash, clave1));
    //print_test("Prueba hash borrar clave1, es valor1", hash_borrar(hash, clave1) == valor1);
    //print_test("Prueba hash la cantidad de elementos es 0", hash_cantidad(hash) == 0);

    /* Inserta otros 2 valores y no los borra (se destruyen con el hash) */
    print_test("Prueba hash insertar clave2", hash_guardar(hash, clave2, valor2));
    print_test("Prueba hash la cantidad de elementos es 1", hash_cantidad(hash) == 1);
    print_test("Prueba hash obtener clave2 es valor2", hash_obtener(hash, clave2) == valor2);
    print_test("Prueba hash obtener clave2 es valor2", hash_obtener(hash, clave2) == valor2);
    print_test("Prueba hash pertenece clave2, es true", hash_pertenece(hash, clave2));

    print_test("Prueba hash insertar clave3", hash_guardar(hash, clave3, valor3));
    print_test("Prueba hash la cantidad de elementos es 2", hash_cantidad(hash) == 2);
    print_test("Prueba hash obtener clave3 es valor3", hash_obtener(hash, clave3) == valor3);
    print_test("Prueba hash obtener clave3 es valor3", hash_obtener(hash, clave3) == valor3);
    print_test("Prueba hash pertenece clave3, es true", hash_pertenece(hash, clave3));

    free(hash);
}

void pruebas_hash_alumno(){
    prueba_crear_hash_vacio();
    prueba_guardar_hash();
}