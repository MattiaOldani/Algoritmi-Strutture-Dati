// DA AGGIUNGERE GESTIONE PER LE BASI > 10

#include<stdio.h>

#define CIFRE 100

int main() {
    int b, n;
    printf("Inserisci b e n: ");
    scanf("%d %d", &b, &n);

    int convertito[CIFRE], i = 0;
    for (; n > 0; i++) {
        convertito[i] = n % b;
        n /= b;
    }

    printf("Il numero convertito è: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", convertito[j]);
    }
    printf("\n");

    return 0;
}