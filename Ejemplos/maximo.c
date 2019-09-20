#include <stdio.h>

#define SIZE 8

int maximo(int vector[], int n);


int main(void){

    int i, array[SIZE];

    printf("Agregar numeros al vector \n");
    for(i = 0; i < SIZE; i++){
        scanf("%d", &array[i]);
    }

    int mayor = maximo(array, SIZE);
    printf("La posicion del mayor elemento en el array es : %d", mayor);
    return 0;
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
    return pos + 1 ;
}
