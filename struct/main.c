//
// Created by lguerra on 9/5/19.
// Se compila con 	gcc -g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror -o puerta *.c
//
#include "puerta.h"
#include <stdio.h>

int main(int argc, const char *argv[]) {
    puerta_t* p = crear_puerta();
    printf(puerta_esta_abierta(p) ? "Esta abierta\n" : "Esta cerrada\n");
    abrir_puerta(p);
    printf(puerta_esta_abierta(p) ? "Esta abierta\n" : "Esta cerrada\n");
    destruir_puerta(p);
}
