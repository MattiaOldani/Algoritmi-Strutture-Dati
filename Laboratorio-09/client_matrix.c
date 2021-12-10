#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"GraphMatrix/graph_matrix.h"
#include"Item/item.h"

void graph_random(Graph g, float p);

int main() {
    // GENERAZIONE DI UN GRAFO RANDOM
    int nv;
    printf("Inserisci numero di vertici: ");
    scanf(" %d", &nv);

    Graph g = graph_new(nv, pow(nv - 1, 2) / 2);
    float p = 0.5;
    srand(time(NULL));
    
    graph_random(g, p);
    graph_print(g);
    graph_breadth_first_search(g);
    graph_depth_first_search(g);
    
    graph_destroy(g);

    return 0;
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