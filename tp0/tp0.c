#include "tp0.h"

// Funcion aux

int minimo (int a, int b){
    return a > b ? b : a;
}

//


void swap (int *x, int *y) {
    /******************************************************************
    * Usa un aux para guardar el contenido del primer puntero
    *****************************************************************/
    int aux = *x;
    *x = *y;
    *y = aux;
}


int maximo(int vector[], int n) {
    /******************************************************************
    * DEvuelve la posicion del mayor elemento del array
    *****************************************************************/
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

    for (int i = 0; i < n1 && i < n2 ; i++) {

            if (vector1[i] > vector2[i]){
                return 1;
            }

            if (vector1[i] < vector2[i]) {
                return -1;
            }
    }

    if (n1 == n2) return 0;

    return n1 > n2 ? 1 : -1 ;


}

void seleccion(int vector[], int n) {

    /******************************************************************
     * Ordeno dejando al final el mas grande (reduciendo el array)
     *****************************************************************/
    int aux, i;

    for (i = n - 1; i > 0 ; i--) {
        aux = maximo(vector, i+1);

        if (vector[aux] != vector[i]){
            swap(&vector[aux], &vector[i]);
        }

    }

}


