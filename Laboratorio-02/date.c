#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct {
    int giorno;
    int mese;
    int anno;
} Data;

int main() {
    int i = 0, flag = 0, n_date = 0;
    Data date[MAX], ultima_data;
    
    while (i < MAX) {
        int giorno, mese, anno;

        printf("Inserisci una data nel formato dd/mm/yyyy: ");
        scanf("%d/%d/%d", &giorno, &mese, &anno);

        if (giorno == 0 && mese == 0 && anno == 0) {
            flag = 1;
            continue;
        }

        Data data = { giorno, mese, anno };

        if (flag == 0) {
            date[n_date] = data;
            n_date++;
        } else {
            ultima_data = data;
            break;
        }
    }
    printf("\n");

    for (int i = 0; i < n_date; i++) {
        Data data = date[i];
        if (data.anno < ultima_data.anno) {
            printf("%02d/%02d/%02d\n", data.giorno, data.mese, data.anno);
            continue;
        }
        if (data.mese < ultima_data.mese && data.anno == ultima_data.anno) {
            printf("%02d/%02d/%02d\n", data.giorno, data.mese, data.anno);
            continue;
        }
        if (data.giorno < ultima_data.giorno && data.mese == ultima_data.mese && data.anno == ultima_data.anno) {
            printf("%02d/%02d/%02d\n", data.giorno, data.mese, data.anno);
        }
    }

    return 0;
}