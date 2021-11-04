#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char **newBook(int n);
int book(char **reg, char * name, int k);
void cancel(char **reg, int k);
void move(char **reg, int from, int to);
void printBook(char **reg, int n);

int main() {
    int n, k, from, to;
    char **reg = NULL, *name, c;

    while ( (c = getchar()) != 'f' ) {
        switch (c) {
            case 'b':
                scanf(" %d", &n);
                if (reg != NULL)
                    free(reg);
                reg = newBook(n);
                if (reg == NULL) {
                    printf("ERRORE: impossibile allocare la memoria\n");
                    return 0;
                }
                break;
            case '+':
                scanf(" %d", &k);
                scanf(" %s", name);
                if (!book(reg, name, k))
                    return 0;
                break;
            case '-':
                scanf(" %d", &k);
                cancel(reg, k);
                break;
            case 'm':
                scanf(" %d", &from);
                scanf(" %d", &to);
                move(reg, from, to);
                break;
            case 'p':
                printBook(reg, n);
                break;
        }
    }
    
    for (int i = 0; i < n; i++)
        free(reg[i);
    free(reg);

    return 0;
}

char **newBook(int n) {
    char **reg;
    reg = malloc(n * sizeof(char *));
    if (reg != NULL)
        for (int i = 0; i < n; i++)
            reg[i] = NULL;
    return reg;
}

int book(char **reg, char * name, int k) {
    if (reg[k] == NULL) {
        reg[k] = malloc(strlen(name));
        if (reg[k] == NULL) {
            printf("ERRORE: impossibile allocare la memoria\n");
            return 0;
        }
        strcpy(reg[k], name);
    } else {
        printf("ERRORE: tentato di inserire un contatto dove ne era già presente uno\n");
    }
    return 1;
}

void cancel(char **reg, int k) {
    if (reg[k] != NULL) {
        reg[k] = NULL;
    } else {
        printf("ERRORE: tentato di eliminare un contatto che non esiste\n");
    }
}

void move(char **reg, int from, int to) {
    if (reg[from] != NULL && reg[to] == NULL) {
        reg[to] = reg[from];
        reg[from] = NULL;
    } else {
        printf("ERRORE: spostamento non consentito\n");
    }
}

void printBook(char **reg, int n) {
    printf("REGISTER[0...%d]:\n", n-1);
    for (int i = 0; i < n; i++)
        if (reg[i] != NULL)
            printf("%d --> %s\n", i, reg[i]);
    printf("\n");
}
