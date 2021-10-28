#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define N 100

void treVolte(char *a[], int n) {
    char **p, *q;
    int conta = 0;
    
    for (p = a; p < a + n; p++) {
        int contae = 0;
        for (char *c = *p; *c; c++) {
            if (*c == 'e')
                contae++;
            if (contae == 3) {
                conta++;
                // AGGIUNTA
                // Aggiungo l'istruzione break perchè una volta che ho aumentato
                // 'conta' so che la parola è accettabile e posso passare alla prossima
                // Inoltre, senza il break, se la stringa non avesse altre 'e' ma avesse
                // altri n caratteri, 'conta' aumenterebbe il suo valore di n poichè
                // 'contae' sarebbe sempre uguale a 3, aumentando quindi 'conta'
                break;
            }
        }
        // Si può fare meglio?
        // Certamente si
        // Lo so fare meglio?
        // Certamente no
        // Funziona?
        // Ovviamente no, Lonati vieni in mio aiuto
        if (conta == 3) {
            int len = strlen(a[0]);
            char grasso[len];
            strcpy(grasso, a[0]);
            strcpy(a[0], *p);
            strcpy(*p, grasso);
            return;
        }
    }
}

int main(int argc, char **argv) {
    treVolte(argv + 1, argc - 1);
    
    // AGGIUNTA
    // Aggiungo + 1 perchè senza il + 1 il programma stampa anche
    // l'eseguibile a terminale
    for (char** p = argv + 1; p < argv + argc; p++)
        printf("%s ", *p);
    
    printf("\n");
    
    return 0;
}