#include<stdio.h>

int main() {
    int counter = 0, index = 0;
    char c;
    while ( (c = getchar() ) != '.') {
        if (c == '(') {
            counter++;
        } else if (c == ')') {
            counter--;
        }
        if (counter < 0) {
            printf("Carattere %d: troppe parentesi chiuse!\n", index);
            return 0;
        }
        index++;
    }
    if (counter > 0) {
        printf("Carattere %d: mancano parentesi chiuse alla fine!\n", index);
    } else {
        printf("La stringa è un’espressione ben parentesizzata\n");
    }
    return 0;
}