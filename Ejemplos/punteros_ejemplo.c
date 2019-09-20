//
// Created by lguerra on 9/1/19.
//

#include<stdio.h>

void jugar(int* n){
    int y = *n; // Recupera el valor dentro de la posicion de memoria

    y = (y+2) / 2 + 2 - (3 * y); // Opera con el valor y actuliza el valor de n
    *n = y;
}


int main(void){
    int x = 10;
    jugar(&x); // Paso como referencia la posicion de memoria de x
    printf("%d \n", x);


    return 0;
}