#include<stdio.h>

int main() {
    int mese, inizio, massimo;
    printf("Inserisci il numero del mese: ");
    scanf("%d", &mese);
    printf("Inserisci il giorno d'inizio mese: ");
    scanf("%d", &inizio);
    
    inizio--;
    switch(mese) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            massimo = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            massimo = 30;
            break;
        case 2:
            massimo = 28;
    }

    int calendario[5][7];
    int giorno = 1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            if (j < inizio) {
                calendario[i][j] = 0;
            } else {
                if (giorno <= massimo) {
                    calendario[i][j] = giorno;
                    giorno++;
                } else {
                    calendario[i][j] = 0; 
                }
            }
        }
        inizio = 0;
    }

    printf(" L  M  M  G  V  S  D\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            int giorno = calendario[i][j];
            if (giorno == 0) {
                if (i == 0) {
                    printf("   ");
                } else {
                    printf("  ");
                }
            } else {
                if (giorno < 10) {
                    printf(" %d ", giorno);
                } else {
                    printf("%d ", giorno);
                }
            }
        }
        printf("\n");
    }
    return 0;
}