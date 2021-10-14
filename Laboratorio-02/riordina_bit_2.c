// SOLUZIONE ALTERNATIVA

#include<stdio.h>

int main() {
    int n;
    printf("Inserire n: ");
    scanf("%d", &n);

    int sequenza[n], inizio = 0, fine = n - 1;
    printf("Inserire la sequenza di bit: ");
    for (int i = 0; i < n; i++) {
        int bit;
        scanf("%d", &bit);
        if (bit) {
            sequenza[fine] = bit;
            fine--;
        } else {
            sequenza[inizio] = bit;
            inizio++;
        }
    }

    printf("Array ordinato: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", sequenza[i]);
    }
    printf("\n");

    return 0;
}