//
// Created by lguerra on 9/1/19.
//
#include <stdio.h>

void swap (int *x, int *y) {
    int aux = *x;
    *x = *y;
    *y = aux;
}


int main(void){
    int a, b;
    a = 5;
    b = 10;
    printf("a = %d  b = %d \n", a, b);
    swap(&a, &b);
    printf("a = %d  b = %d \n", a, b);
    return 0;
}