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


void prueba_guardar_hash()
{
    hash_t* hash = hash_crear(NULL);
    char clave[] = "Hola";
    int valor = 10;
    print_test("Guardar en hash", hash_guardar(hash, clave, &valor) == true);
    print_test("La nueva cantidad de elementos es 1", hash_cantidad(hash) == 1);

    free(hash);
}

void pruebas_hash_alumno(){
    prueba_crear_hash_vacio();
    prueba_guardar_hash();
}