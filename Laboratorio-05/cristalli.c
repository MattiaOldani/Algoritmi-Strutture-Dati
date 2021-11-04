#include<stdio.h>
#include<stdlib.h>

int latoCristallo(int t);
char **creaMatrice(int n);
void stampaMatrice(char **m, int n);
void cristallo(char **m, int l);
void crist(char **m, int r0, int c0, int l);
void copiaSottoMatrice(char **m, int l, int r0, int c0, int r1, int c1);

int main() {
    char **matrix;
    int t, lato;
    printf("Inserisci il tempo t: ");
    scanf(" %d", &t);

    if (t >= 0) {
        lato = latoCristallo(t);
        matrix = creaMatrice(lato);
        if (matrix == NULL) {
            printf("Impossibile allocale la memoria\n");
            return 0;
        }
        cristallo(matrix, lato);
        stampaMatrice(matrix, lato);
        free(matrix);
    }

    return 0;
}

int latoCristallo(int t) {
    if (t == 0)
        return 1;
    return 1 + 2 * latoCristallo(t -1);
}

char **creaMatrice(int n) {
    char **matrix;
    matrix = malloc(n * sizeof(char *));
    if (matrix != NULL) {
        for (int i = 0; i < n; i++) {
            matrix[i] = malloc(n * sizeof(char));
            if (matrix[i] == NULL)
                return NULL;
            else
                for (int j = 0; j < n; j++)
                    matrix[i][j] = '.';
        }
        return matrix;
    }
    else {
        return NULL;
    }
}

void stampaMatrice(char **m, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%c", m[i][j]);
        printf("\n");
    }
}

void cristallo(char **m, int l) {
    crist(m, 0, 0, l);
}

void crist(char **m, int r0, int c0, int l) {
    if (l == 1) {
        m[r0][c0] = '*';
        return;
    }
    int r_center = (2 * r0 + l) / 2;
    int c_center = (2 * c0 + l) / 2;
    m[r_center][c_center] = '*';
    crist(m, r0, c0, l / 2);
    copiaSottoMatrice(m, l / 2, r0, c0, r0, c0 + c_center + 1);
    copiaSottoMatrice(m, l / 2, r0, c0, r0 + r_center + 1, c0);
    copiaSottoMatrice(m, l / 2, r0, c0, r0 + r_center + 1, c0 + c_center + 1);
}

void copiaSottoMatrice(char **m, int l, int r0, int c0, int r1, int c1) {
    for (int i = 0; i < l; i++)
        for (int j = 0 ; j < l; j++)
            m[r1 + i][c1 + j] = m[r0 + i][c0 + j];
}