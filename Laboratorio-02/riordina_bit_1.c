// SOLUZIONE RICHIESTA

#include<stdio.h>

int main() {
    int n;
    printf("Inserire n: ");
    scanf("%d", &n);

    int sequenza[n];
    printf("Inserire la sequenza di bit: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &sequenza[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        if (sequenza[i] == 1) {
            int flag = 1;
            for (int j = i + 1; j < n && flag; j++) {
                if (sequenza[j] == 0) {
                    int aux = sequenza[i];
                    sequenza[i] = sequenza[j];
                    sequenza[j] = aux;
                    flag = 0;
                }
            }
            if (flag == 0) {
                break;
            }
        }
    }

    printf("Array ordinato: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", sequenza[i]);
    }
    printf("\n");

    return 0;
}