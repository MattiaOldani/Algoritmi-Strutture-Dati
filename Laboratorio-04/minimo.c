#include<stdio.h>

int *smallest(int a[], int n);

int main() {
    int n;
    printf("Inserisci la lunghezza dell'array: ");
    scanf(" %d", &n);

    int a[n];
    printf("Inserisci n elementi (uno per riga)\n");
    for (int i = 0; i < n; i++) {
        scanf(" %d", &a[i]);
    }

    printf("Il minimo della sequenza è: %d\n", *smallest(a, n));

    return 0;
}

int *smallest(int a[], int n) {
    int *minimo = a;
    for (int *i = a + 1; i < a + n; i++) {
        if (*i < *minimo) {
            minimo = i;
        }
    }

    return minimo;
}