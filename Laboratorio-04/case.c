#include<stdio.h>
#include<ctype.h>

char *maiuscolo(char *stringa);

int main() {
    char frase[BUFSIZ];
    int i = 0;
    char c;
    printf("Inserisci una frase: ");
    while ( (c = getchar()) != '\n' ) {
        frase[i] = c;
        i++;
    }
    frase[i] = '\0';

    printf("%s\n", maiuscolo(frase));
    return 0;
}

char *maiuscolo(char *stringa) {
    for (char *inizio = stringa; *inizio != 0; inizio++) {
        *inizio = toupper(*inizio);
    }
    return stringa;
}