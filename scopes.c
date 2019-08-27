//
// Created by lucas on 27/8/19.
//

#include <stdio.h>

int main(void){
    /* Este es el comienzo del bloque del main */
    int i = 5;

    {
        /*Aca comienza un nuevo bloque*/
        int i = 6;
        printf("El valor de i en el bloque dentro del main es : %d \n", i);
    }

    /*de vuelta al bloque del main donde i = 5 */
    printf("El valor de i en el bloque del main es : %d \n", i);

    return 0;
}
