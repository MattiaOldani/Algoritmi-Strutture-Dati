#include<stdio.h>

#define MAX 99

int main() {
    int sequenza[MAX] = { 0 };
    int lunghezza = 0;
    
    while(1) {
        int n;

        printf("Inserisci un numero: ");
        scanf("%d", &n);
        if (n == 0) {
            break;
        }

        if (lunghezza == 0) {
            sequenza[0] = n;
            lunghezza++;
            continue;
        }

        for (int i = 0; i < lunghezza; i++) {
            if (sequenza[i] == 0) {
                sequenza[i] = n;
                break;
            }
            if (sequenza[i] > n) {
                int inserire = n;
                for (int j = i; j <= lunghezza; j++) {
                    int aux = sequenza[j];
                    sequenza[j] = inserire;
                    inserire = aux;
                }
                break;
            }
        }
        lunghezza++;
    }

    printf("Array ordinato:\n[");
    for (int i = 0; i < lunghezza - 1; i++) {
        printf("%d ", sequenza[i]);
    }
    printf("\b]\n");

    return 0;
}