#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define N_LETTERE 26

int main() {
    int lettere1[N_LETTERE] = { 0 }, lettere2[N_LETTERE] = { 0 };
    char c;
    
    printf("Inserisci la prima parola: ");
    while ( (c = getchar() ) != '\n' ) {
        lettere1[toupper(c)-65]++;
    }

    printf("Inserisci la seconda parola: ");
    while ( (c = getchar() ) != '\n' ) {
        lettere2[toupper(c)-65]++;
    }

    for (int i = 0; i < N_LETTERE; i++) {
        if (lettere1[i] != lettere2[i]) {
            printf("Non sono anagrammi\n");
            return 0;
        }
    }
    printf("Sono anagrammi\n");
    
    return 0;
}