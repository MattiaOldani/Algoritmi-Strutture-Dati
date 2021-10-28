#include <stdio.h>

#define LENGTH 100

int main() {
    int a[LENGTH];
    int *p;
    
    printf("Inserisci una serie di numeri (uno per riga) che termina con 0\n");
    for (p = a; p < a + LENGTH; p++) {
        scanf( "%d", p);
        if (*p == 0)
            break;
    }
    
    printf("La sequenza inserita al contrario è: ");
    while (--p >= a)
        printf("%d ", *p);
    
    printf("\n");
    
    return 0;

}