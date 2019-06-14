//
// Created by lguerra on 6/14/2019.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void minimo(int* numeros);
void maximo(int* numeros);
void prom(int* numeros);

int main(void){

    int numeros[MAX];

    for (int i = 0; i < MAX ; ++i) {
        char ingreso[MAX];

        printf("Ingrese el numero %d:", i+1 );
        fgets(ingreso, MAX, stdin);

        int numero = atoi(ingreso);
        numeros[i] = numero;
    }

    printf("\n");
    
    minimo(numeros);
    maximo(numeros);
    prom(numeros);

    getchar();
    return 0;
}


void minimo(int* numeros){
    int menor = numeros[0];

    for (int i = 1; i < MAX ; ++i) {
        if (numeros[i] < menor){
            menor = numeros[i];
        }
    }

    printf("El minimo es: %d\n", menor);
}

void maximo(int* numeros){
    int maximo = numeros[0];

    for (int i = 1; i < MAX ; ++i) {
        if (numeros[i] > maximo){
            maximo = numeros[i];
        }
    }

    printf("El maximo es: %d\n", maximo);
}

void prom(int* numeros){
    int acumulado = 0;

    for (int i = 0; i < MAX ; ++i) {
        acumulado += numeros[i];
    }

    int promedio = acumulado / MAX;
    printf("El promedio es: %d\n", promedio);
}