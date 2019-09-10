//
// Created by lguerra on 9/5/19.
//

#ifndef SOME_C_PUERTA_H
#define SOME_C_PUERTA_H

#include <stdbool.h>

typedef struct puerta puerta_t;

puerta_t* crear_puerta();

void destruir_puerta(puerta_t* p);

void abrir_puerta(puerta_t* puerta);

void cerrar_puerta(puerta_t* puerta);

bool puerta_esta_abierta(puerta_t* puerta);

#endif //SOME_C_PUERTA_H
