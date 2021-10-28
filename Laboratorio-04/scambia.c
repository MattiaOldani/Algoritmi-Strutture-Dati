#include<stdio.h>

void scambia(int *p, int *q);

int main() {
    int p = 5, q= 10;
    printf("%d %d\n", p, q);

    scambia(&p, &q);

    printf("%d %d\n", p, q);

    return 0;
}

void scambia(int *p, int *q) {
    int aux = *p;
    *p = *q;
    *q = aux;
}