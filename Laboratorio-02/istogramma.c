#include<stdio.h>
#include<ctype.h>

#define N_LETTERE 26

int main() {
    int lettere[N_LETTERE] = { 0 };
    char c;
    
    printf("Inserisci una frase: ");
    while ( (c = getchar() ) != '.' ) {
        if (!isalpha(c)) { continue; }
        lettere[toupper(c)-65]++;
    }

    for (int i = 0; i < N_LETTERE; i++) {
        if (lettere[i] > 0) {
            printf("%c ", i+65);
            for (int j = 0; j < lettere[i]; j++) {
                printf("*");
            }
            printf("\n");
        }
    }
    
    return 0;
}