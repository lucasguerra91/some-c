#include<stdio.h>
int _faltante(int* a, int* b, int inicio, int final){

    int medio = (inicio + final) / 2;

    if (medio > 0 && a[medio] != b[medio]){
        return a[medio] > b[medio] ? a[medio] : b[medio];
    }

    int izq = _faltante(a, b, 0, medio - 1);
    int der = _faltante(a, b, medio + 1, final);

    return der > izq ? der : izq;
}


int faltante(int* a, int* b, int n){
    return _faltante(a, b, 0, n-1);
}

int main(){
    int a[]= {2,4,6,8,9,10,12};
    int b[] = {2,4,6,8,10,12};
    int n = 6;

    int numero = faltante(a, b, n);
    printf("\nEl faltante es %d", numero);

    printf("%d", a[7]);
    return 0;
}
