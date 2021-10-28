#include<stdio.h>

void max_secondmax(int a[], int n, int *max, int *second_max);

int main() {
    int n;
    printf("Inserisci il numero di elementi: ");
    scanf(" %d", &n);

    int sequenza[n];
    printf("Inserisci un numero per riga\n");
    for (int i = 0; i < n; i++) {
        scanf(" %d", &sequenza[i]);
    }

    int max = 0, second_max = 0;
    max_secondmax(sequenza, n, &max, &second_max);

    printf("Il massimo è %d mentre il secondo massimo è %d\n", max, second_max);

    return 0;
}

void max_secondmax(int a[], int n, int *max, int *second_max) {
    *max = *a;
    *second_max = *a;
    for (int *i = a + 1; i < a + n; i++) {
        if (*i > *max) {
            *second_max = *max;
            *max = *i;
        } else if (*i > *second_max) {
            *second_max = *i;
        }
    }
}