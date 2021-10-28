#include<stdio.h>
#include<string.h>

void smallest_largest(char *s[], int n, char **smallest, char **largest);

int main(int argc, char **argv) {
    char *smallest, *largest;

    smallest_largest(argv + 1, argc - 1, &smallest, &largest);
    printf("Parola minima: %s || Parola massima: %s\n", smallest, largest);

    return 0;
}

void smallest_largest(char *s[], int n, char **smallest, char **largest) {
    *smallest = *s;
    *largest = *s;
    for (char **i = s + 1; i < s + n; i++) {
        if (strcmp(*smallest, *i) > 0) {
            *smallest = *i;
        } else if (strcmp(*largest, *i) < 0) {
            *largest = *i;
        }
    }
}