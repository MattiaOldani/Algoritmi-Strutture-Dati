#include<stdio.h>
#include<stdlib.h>

#define INITIAL_SIZE 2

void stampa(int a[], int lung);
void scambia(int a[], int i, int j);
void selectionsort(int a[], int n);
void mergesort(int a[], int sx, int dx);
void merge(int a[], int sx, int m, int dx);

int main() {
    int *a, *b, i = 0, size = INITIAL_SIZE;
    a = malloc(size * sizeof(int));
    b = malloc(size * sizeof(int));

    printf("Inserisci una sequenza di interi: ");
    while (1) {
        char ch;
        if (i >= size) {
            size *= 2;
            a = realloc(a, size * sizeof(int));
            b = realloc(b, size * sizeof(int));
        }
        int n;
        scanf(" %d", &n);
        *(a + i) = n;
        *(b + i++) = n;
        if ( (ch = getchar()) == '\n' )
            break;
    }

    printf("La sequenza inserita è: ");
    stampa(a, i);

    printf("La sequenza ordinata con selesort è: ");
    selectionsort(a, i);
    stampa(a, i);
    free(a);

    printf("La sequenza ordinata con mergesort è: ");
    mergesort(b, 0, i);
    stampa(b, i);
    free(b);

    return 0;
}

void stampa(int a[], int lung) {
    for (int* i = a; i < a + lung; i++) {
        printf("%d ", *i);
    }
    printf("\n");
}

void scambia(int a[], int i, int j) {
    int aux = *(a + i);
    *(a + i) = *(a + j);
    *(a + j) = aux;
}

void selectionsort(int a[], int n) {
    if (n == 0 || n == 1)
        return;
    int min = 0;
    for (int i = 1; i < n; i++)
        if (a[i] > a[min])
            min = i;
    scambia(a, min, n - 1);
    selectionsort(a, n - 1);
}

void mergesort(int a[], int sx, int dx) {
    if (abs(dx - sx) == 0 || abs(dx - sx) == 1)
        return;
    int m = (sx + dx) / 2;
    mergesort(a, sx, m);
    mergesort(a, m, dx);
    merge(a, sx, m, dx);
}

void merge(int a[], int sx, int m, int dx) {
    int *help, i = 0, s = sx, t = m;
    help = malloc((dx - sx) * sizeof(int));

    while (s < m && t < dx) {
        if (a[s] < a[t])
            *(help + i++) = a[s++];
        else
            *(help + i++) = a[t++];
    }

    if (s == m)
        while (t < dx)
            *(help + i++) = a[t++];
    else
        while (s < m)
            *(help + i++) = a[s++];
    
    for (int i = 0, j = sx; j < dx; i++, j++)
        *(a + j) = *(help + i);
}