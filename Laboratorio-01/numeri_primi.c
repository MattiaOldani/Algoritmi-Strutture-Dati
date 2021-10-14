#include<stdio.h>
#include<math.h>

void sequenza_divisori(int n);
int primo1(int n);
int primo2(int n);
void scomposizione(int n);

int main() {
    int n, contatore = 0;
    printf("Inserisci n: ");
    scanf("%d", &n);

    printf("PARTE 1: sequenza decrescente dei divisori di n\n");
    sequenza_divisori(n);

    printf("PARTE 2.1: stabilire se n è primo con un ciclo for\n");
    if (primo1(n)) {
        printf("n è primo\n\n");
    } else {
        printf("n non è primo\n\n");
    }

    printf("PARTE 2.2: stabilire se n è primo con un ciclo while\n");
    if (primo2(n)) {
        printf("n è primo\n\n");
    } else {
        printf("n non è primo\n\n");
    }

    printf("PARTE 3: Stampare la scomposizione in fattori primi di n\n");
    scomposizione(n);
    return 0;
}

void sequenza_divisori(int n) {
    int contatore = 0;
    for (int i = n; i > 1; i--) {
        if (n % i == 0) {
            printf("%d ", i);
            contatore++;
        }
    }
    printf("\n%d ha %d divisore/i\n\n", n, contatore);
}

int primo1(int n) {
    for (int i = 2; i < (int)sqrt(n); i++) {
        if ((n % i) == 0) {
            return 0;
        }
    }
    return 1;
}

int primo2(int n) {
    int i = 2;
    while (i < (int)sqrt(n)) {
        if ((n % i) == 0) {
            return 0;
        }
        i++;
    }
    return 1;
}

void scomposizione(int n) {
    while (n > 1) {
        if (primo1(n)) {
            printf("%d\n", n);
            break;
        }
        for (int i = 2; i < (int)sqrt(n); i++) {
            if (primo1(i) && (n % i) == 0) {
                printf("%d*", i);
                n = n / i;
                break;
            }
        }
    }
}
