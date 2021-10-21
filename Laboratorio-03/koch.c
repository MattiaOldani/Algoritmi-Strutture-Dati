#include<stdio.h>
#include"libpsgraph.h"

void disegnaLato(int lunghezza, int i);
void disegnaFiocco(int lunghezza, int i);

int main() {
    int lunghezza, i;
    printf("Inserisci lunghezza e i: ");
    scanf("%d %d", &lunghezza, &i);
    start("koch.ps");
    disegnaFiocco(lunghezza, i);
    end();
    return 0;
}

void disegnaLato(int lunghezza, int i) {
    if (i == 0) {
        draw(lunghezza);
    } else {
        disegnaLato(lunghezza / 3, i - 1);
        turn(-60);
        disegnaLato(lunghezza / 3, i - 1);
        turn(120);
        disegnaLato(lunghezza / 3, i - 1);
        turn(-60);
        disegnaLato(lunghezza / 3, i - 1);
    }
}

void disegnaFiocco(int lunghezza, int i) {
    disegnaLato(lunghezza, i);
    turn(120);
    disegnaLato(lunghezza, i);
    turn(120);
    disegnaLato(lunghezza, i);
    turn(120);
}