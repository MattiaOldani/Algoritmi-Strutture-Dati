#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10

int main() {
    char campo[N][N];
    char direzioni[4] = { 'N', 'E', 'S', 'O' };
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            campo[i][j] = '.';
        }
    }
    campo[0][0] = 'A';

    srand(time(NULL));
    int i = 0, j = 0, flag = 1;
    char lettera = 'B';
    
    while(lettera <= 90 && flag) {
        int counter = 0;
        int indice = rand() % 4;
        char direzione = direzioni[indice];
        while (counter < 4) {
            switch (direzione) {
                case 'N':
                    if (i - 1 >= 0 && campo[i - 1][j] == '.') {
                        campo[i - 1][j] = lettera;
                        i--;
                        break;
                    }
                case 'E':
                    if (j + 1 < N && campo[i][j + 1] == '.') {
                        campo[i][j + 1] = lettera;
                        j++;
                        break;
                    }
                case 'S':
                    if (i + 1 < N && campo[i + 1][j] == '.') {
                        campo[i + 1][j] = lettera;
                        i++;
                        break;
                    }
                case 'O':
                    if (j - 1 >= 0 && campo[i][j - 1] == '.') {
                        campo[i][j - 1] = lettera;
                        j--;
                        break;
                    }
                default:
                    flag = 0;
            }
            if (flag != 0) {
                break;
            } else {
                flag = 1;
                counter++;
                direzione = direzioni[(indice + 1) % 4];
                indice++;
            }
        }
        if (counter == 4) {
            flag = 0;
        }
        lettera++;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", campo[i][j]);
        }
        printf("\n");
    }

    return 0;
}