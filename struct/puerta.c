//
// Created by lguerra on 9/5/19.
//

#include "puerta.h"
#include <stdlib.h>

struct puerta {
    bool estado;
};


puerta_t* crear_puerta() {
    puerta_t* p = malloc(sizeof(puerta_t));
    if (p == NULL) {
        return NULL;
    }
    cerrar_puerta(p);
    return p;
}

void destruir_puerta(puerta_t* p) {
    free(p);
}

void abrir_puerta(puerta_t* p) {
    p->estado = true;
}

void cerrar_puerta(puerta_t* p) {
    p->estado = false;
}

bool puerta_esta_abierta(puerta_t* p) {
    return p->estado;
}