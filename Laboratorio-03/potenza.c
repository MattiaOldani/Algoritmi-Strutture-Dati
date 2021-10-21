#include<stdio.h>

int potenza(int a, int b);

int main() {
    int a, b;
    printf("Inserisci base e esponente: ");
    scanf("%d %d", &a, &b);

    printf("Il risultato è: %d\n", potenza(a, b));

    return 0;
}

int potenza(int a, int b) {
    if (b == 0) {
        return 1;
    }
    return a * potenza(a, b - 1);
}