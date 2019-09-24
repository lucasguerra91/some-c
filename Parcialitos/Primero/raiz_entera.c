#include <stdio.h>

size_t _raiz(size_t n, size_t inicio, size_t final){

    size_t medio = (inicio + final) / 2;

    if (medio * medio > n){
        return _raiz(n, inicio, medio - 1);
    }

    if (medio * medio <= n && (medio + 1) * (medio + 1) > n){
        return medio;
    }

    return _raiz(n, medio +1 , final);

}

size_t raiz(size_t n){
    return _raiz(n, 0 , n - 1);
}



int main(void){

    size_t numero = 25;
    printf("La raiz entera de  %ld es : %ld\n", numero, raiz(numero));

    size_t numero2 = 10;
    printf("La raiz entera de  %ld es : %ld\n", numero2, raiz(numero2));

    size_t numero3 = 11;
    printf("La raiz entera de  %ld es : %ld\n", numero3, raiz(numero3));

    return 0;
}