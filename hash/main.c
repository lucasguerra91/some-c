#include "testing.h"
#include <stdlib.h>
#include <stdio.h>

extern void pruebas_hash_alumno(void);


/* ******************************************************************
 *                        PROGRAMA PRINCIPAL
 * *****************************************************************/

void pruebas_hash_catedra(void);
void pruebas_volumen_catedra(size_t);

int main(int argc, char *argv[])
{
//    printf("~~~ PRUEBAS DEL ALUMNO ~~~\n");
//    pruebas_hash_alumno();
       if (argc > 1) {
       // Asumimos que nos están pidiendo pruebas de volumen.
       long largo = strtol(argv[1], NULL, 10);
       pruebas_volumen_catedra((size_t) largo);

       return failure_count() > 0;
   }

    printf("\n~~~ PRUEBAS CÁTEDRA ~~~\n");
    pruebas_hash_catedra();

    return failure_count() > 0;
}
