#include<stdio.h>
#include<stdlib.h>

int main() {
    char c1, c2;
    printf("Inserisci due caratteri maiuscoli: ");
    scanf("%c %c", &c1, &c2);
    printf("La distanza nell'ordine alfabetico è: %d\n", abs(c1 - c2) + 1);
    return 0;
}