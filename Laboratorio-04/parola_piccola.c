#include<stdio.h>
#include<string.h>

int smallest_word_index(char *s[], int n);

int main(int argc, char **argv) {
    printf("Indice della parola minima: %d\n", smallest_word_index(argv + 1, argc - 1));

    return 0;
}

int smallest_word_index(char *s[], int n) {
    int minimo = 0, indice = 1;
    for (char **i = s + 1; i < s + n; i++, indice++) {
        printf("STRINGA IN CONSIDERAZIONE: %s\n", *i);
        if (strcmp(*(s + minimo), *i) > 0) {
            minimo = indice;
        }
    }
    return minimo;
}