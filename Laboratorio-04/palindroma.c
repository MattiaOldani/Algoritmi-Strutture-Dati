#include<stdio.h>
#include<stdlib.h>

int palindroma(char parola[]);

int main(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        if (palindroma(argv[i])) {
            printf("La parola %s è palindroma\n", argv[i]);
        } else {
            printf("La parola %s non è palindroma\n", argv[i]);
        }
    }

    return 0;
}

int palindroma(char parola[]) {
    char *inizio, *fine;
    for (inizio = parola, fine = parola; *fine != 0; fine++);
    fine--;

    for (; inizio < fine; inizio++, fine--)
        if (*inizio != *fine)
            return 0;

    return 1;
}