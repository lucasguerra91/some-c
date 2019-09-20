//
// Created by lguerra on 9/2/19.
//



#include <stdio.h>
#include "tp0.h"

/* *****************************************************************
 *                     FUNCIONES A COMPLETAR                       *
 *         (ver en tp0.h la documentación de cada función)         *
 * *****************************************************************/

int main(void){
    int vec1[] = {4, 8, 15, 16, 23, 42};
    // int vec1_ord[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 6; ++i) {
        printf(" - %d -", vec1[i]);
    }

    printf("\nDespues del cambio\n");

    seleccion(vec1, 6 );

    for (int i = 0; i < 6; ++i) {
        printf("- %d -", vec1[i]);
    }
    printf("\n\n");
    return 0;
}

void swap (int *x, int *y) {
    printf("ingresan al swap %d y %d\n", *x, *y);
//    if (*x == *y){
//        return;
//    }
    int aux = *x;
    *x = *y;
    *y = aux;
}


int maximo(int vector[], int n) {

    if (n <= 0) {
        return -1;
    }

    int maximo = vector[0];
    int pos = 0;

    for (int i = 1; i < n; i++) {
        if (vector[i] > maximo){
            maximo = vector[i];
            pos = i;
        }
    }

    return pos;
}


int comparar(int vector1[], int n1, int vector2[], int n2) {

    if (n1 == 0){
        if (n2 == 0){
            return 0;
        } else{
            return -1;
        }
    }

    if (n2 == 0){
        return 1;
    }


    int limite, limite_menor;

    if (n1 > n2){
        limite = n1;
        limite_menor = n2;
    }else{
        limite = n2;
        limite_menor = n1;
    }

    for (int i = 0; i < limite; i++) {

        if (i < limite_menor){

            if (vector1[i] > vector2[i]){
                return 1;
            }

            if (vector1[i] < vector2[i]){
                return -1;
            }

            continue;
        } else{
            if (n1 == limite){
                return 1;
            }

            if (n2 == limite){
                return -1;
            }
        }


    }

    return 0;
}

void seleccion(int vector[], int n) {

    int aux, i;

    for (i = n - 1; i > 0 ; i--) {
        aux = maximo(vector, i+1);

        if (vector[aux] != vector[i]){
            swap(&vector[aux], &vector[i]);
        }

    }

}
