#include<stdio.h>

#define N_CIFRE 10

int main() {
    int n, flag = 0;
    int cifre[N_CIFRE] = { 0 };
    printf("Inserisci un numero: ");
    scanf("%d", &n);
    
    while (n > 0) {
        cifre[n % 10]++;
        n /= 10;
    }
    for (int i = 0; i < N_CIFRE; i++) {
        if (cifre[i] > 1) {
            flag = 1;
            break;
        }
    }

    if (flag) {
        printf("Cifre ripetute: ");
        for (int i = 0; i < N_CIFRE; i++) {
            if (cifre[i] > 1) {
                printf("%d ", i);
            }
        }
        printf("\n");
    } else {
        printf("Non ci sono cifre ripetute\n");
    }

    return 0;
}