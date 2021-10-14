#include<stdio.h>

int main() {
    int r, c;
    printf("Inserisci r e c: ");
    scanf("%d %d", &r, &c);
    getchar();

    char campo[r][c], ch;
    int i = 0, j = 0;
    printf("Inserisci la matrice come se fosse una stringa scrivendola per righe: ");
    while ( ( ch = getchar() ) != '\n' ) {
        campo[i][j] = ch;
        j = (j + 1) % c;
        if (j == 0) {
            i++;
        }
    }

    for (int j = 0; j < c; j++) {
        for (int i = r - 1; i > 0; i--) {
            int flag = 1;
            if (campo[i][j] == '*') {
               for (int t = i - 1; t >= 0 && flag; t--) {
                    if (campo[t][j] != '*') {
                        campo[i][j] = campo[t][j];
                        campo[t][j] = '*';
                        flag = 0;
                    }
                }
                if (flag) {
                    break;
                } 
            }
        }
    }

    printf("\nLa matrice schiacciata è:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%c ", campo[i][j]);
        }
        printf("\n");
    }

    return 0;
}