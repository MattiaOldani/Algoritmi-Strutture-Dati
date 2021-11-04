#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

char *read_line(char c);
char *read_word();

int main() {
    char c;
    printf("Inserisci il carattere terminatore: ");
    scanf(" %c", &c);

    char *line = read_line(c);
    if (line == NULL)
        printf("Errore nell'allocazione della memoria\n");
    else {
        printf("La stringa letta è: ");
        for (int i = 0; *(line + i) != '\0'; i++)
            printf("%c", *(line + i));
        printf("\n\n\n");
    }
    free(line);

    char *parola = read_word();
    if (parola == NULL || *parola == ' ')
        printf("Errore nell'allocazione della memoria\n");
    else {
        printf("La parola letta è: ");
        for (int i = 0; *(parola + i) != '\0'; i++) {
            printf("%c", *(parola + i));
        }
        printf("\n");
    }
    free(parola);

    return 0;
}

char *read_line(char c) {
    char *line, ch;
    int size = 2, i = 0;
    line = malloc(size * sizeof(char));

    if (line == NULL)
        return line;

    printf("Inserisci la frase terminata dal carattere %c: ", c);
    while ( (ch = getchar()) != 'c') {
        if (i >= size) {
            char* aux;
            size *= 2;
            aux = realloc(line, size);
            if (aux == NULL)
                return aux;
            line = aux;
        }
        *(line + i++) = ch;
    }
    getchar();
    if (i >= size) {
        char *aux;
        aux = realloc(line, size + 1);
        if (aux == NULL) {
            return aux;
        }
        line = aux;
    }
    *(line + i) = '\0';

    return line;
}

char *read_word() {
    char *parola, c;
    int size = 2, i = 0;
    parola = malloc(size * sizeof(char));

    if (parola == NULL)
        return parola;
    
    printf("Inserisci una parola: ");
    while ( (c = getchar()) != EOF) {
        if (!isalnum(c)) {
            if (i == 0)
                *parola = ' ';
            break;
        }
        if (i >= size) {
            char *aux;
            size *= 2;
            aux = realloc(parola, size);
            if (aux == NULL)
                return aux;
            parola = aux;
        }
        *(parola + i++) = c;
    }
    if (i >= size) {
        char *aux;
        aux = realloc(parola, size + 1);
        if (aux == NULL) {
            return aux;
        }
        parola = aux;
    }
    *(parola + i) = '\0';

    return parola;
}
