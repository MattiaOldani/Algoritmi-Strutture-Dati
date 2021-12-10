#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"GraphList/graph_list.h"
#include"Item/item.h"

int degree(Graph g, int v);
void graph_random(Graph g, float p);

int main() {
    // DEGREE
    int nv, ne;
    printf("Inserisci numero di vertici e numero di archi: ");
    scanf(" %d %d", &nv, &ne);

    Graph g = graph_new(nv, ne);
    graph_read(g);

    while (1) {
        int n;
        printf("Inserisci un vertice per sapere il suo grado, -1 se vuoi terminare: ");
        scanf(" %d", &n);
        if (n == -1)
            break;
        printf("Grado del vertice %d: %d\n", n, degree(g, n - 1));
    }

    graph_destroy(g);

    
    // GENERAZIONE DI UN GRAFO RANDOM
    printf("\n\nInserisci numero di vertici: ");
    scanf(" %d", &nv);

    g = graph_new(nv, pow(nv - 1, 2) / 2);
    float p = 0.5;
    srand(time(NULL));
    
    graph_random(g, p);
    graph_print(g);

    graph_destroy(g);

    return 0;
}

int degree(Graph g, int v) {
    Node *list = g -> A[v];
    int counter = 0;

    while (list != NULL) {
        counter++;
        list = list -> next;
    }

    return counter;
}

void graph_random(Graph g, float p) {
    printf("Grafo generato in modo casuale\n");
    for (int i = 1; i <= g -> V; i++) {
        for (int j = 1; j <= g -> V; j++) {
            if (i != j) {
                printf("Provo a inserire l'arco %d - %d\n", i, j);
                float extract = (float)rand() / ((float)RAND_MAX);
                if (extract > p) {
                    graph_edgeinsert(g, i, j);
                    printf("Arco inserito\n");
                } else {
                    printf("Arco non inserito\n");
                }
            }
        }
    }
}