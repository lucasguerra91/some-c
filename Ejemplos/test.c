//
// Created by lguerra on 9/1/19.
//
#include <stdio.h>

int main()
{
    int a[] = { 1, 2, -3, -4 };
    int b[] = { 1, 2, -3 };

    a[4] = 0;
    b[3] = 0;
    printf("compara %d y %d", a[3],b[3]);

    if (a[3] > b[3]){
        printf("%d es mayor que %d", a[3],b[3]);
    }
    return 0;
}
