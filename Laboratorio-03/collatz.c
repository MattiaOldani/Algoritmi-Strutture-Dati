#include<stdio.h>

void sequenza(int n);
int successivo(int n);

int main() {
    int n;
    printf("Inserisci n: ");
    scanf("%d", &n);
    sequenza(n);

    return 0;
}

void sequenza(int n) {
    int contatore = 1;
    do {
        printf("%d ", n);
        n = successivo(n);
        contatore++;
    } while (n != 1);
    printf("1\nLunghezza della sequenza: %d\n", contatore);
}

int successivo(int n) {
    return (n % 2 == 0) ? (n / 2) : (3 * n + 1);
}