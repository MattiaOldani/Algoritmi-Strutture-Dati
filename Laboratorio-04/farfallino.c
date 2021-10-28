#include<stdio.h>

void farf(char parola[]);

int main(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        printf("Prima: %s || Dopo: ", argv[i]);
        farf(argv[i]);
    }
    return 0;
}

void farf(char parola[]) {
    for (char *i = parola; *i != 0; i++) {
        if (*i == 'a' || *i == 'e' || *i == 'i' || *i == 'o' || *i == 'u') {
            printf("%c%c%c", 'f', *i, 'f');
        } else {
            printf("%c", *i);
        }
    }
    printf("\n");
}