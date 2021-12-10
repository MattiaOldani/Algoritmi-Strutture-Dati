#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"graph_matrix.h"
#include"../Queue/queue.h"
#include"../Item/item.h"

// Funzione utilizzata da 'graph_depth_first_search'
void graph_recursive_search(Graph g, int i, int *aux);

// Crea un grafo con 'n' nodi e 'm' archi
Graph graph_new(int nv, int ne) {
    Graph g = malloc(sizeof(struct graph));
    g -> V = nv;
    g -> E = ne;
    g -> A = calloc(nv, sizeof(int *));
    for (int i = 0; i < nv; i++)
        g -> A[i] = calloc(nv, sizeof(int));
    return g;
}

// Distrugge il grafo
void graph_destroy(Graph g) {
    for (int i = 0; i < g -> V; i++)
        free(g -> A[i]);
    free(g);
}

// Inserisce l'arco (v, w) nel grafo
void graph_edgeinsert(Graph g, int v, int w) {
    g -> A[v - 1][w  - 1] = 1;
}

// Legge da STDIN un grafo
// FORMATO:
//  - Inserire 'E' archi nel formato vertice_partenza, vertice_arrivo, uno per riga
void graph_read(Graph g) {
    printf("Inserisci %d archi\n", g -> E);
    for (int i = 0; i < g -> E; i++) {
        int start, end;
        scanf(" %d %d", &start, &end);
        graph_edgeinsert(g, start, end);
        graph_edgeinsert(g, end, start);
    }
}

// Stampa su STDOUT per ogni vertice la lista dei suoi vicini
void graph_print(Graph g) {
    printf("Grafo sotto forma di matrice:\n");
    for (int i = 0; i < g -> V; i++) {
        for (int j = 0; j < g -> V; j++)
            print_item(g -> A[i][j]);
        printf("\n");
    }
}

// Stampa su STDOUT un grafo tramite visita in profondità
void graph_depth_first_search(Graph g) {
    int *aux, start;
    aux = calloc(g -> V, sizeof(int));
    
    srand(time(NULL));
    start = rand() % g -> V;

    printf("Grafo letto a partire dal vertice %d: ", start + 1);
    for (int i = start, counter = 0; counter < g -> V; counter++) {
        if (!aux[i]) {
            printf("%d ", i + 1);
            graph_recursive_search(g, i, aux);
        }
        i = (i + 1) % g -> V;
    }
    printf("\n");
    free(aux);
}

// Stampa su STDOUT un grafo tramite visita in ampiezza
void graph_breadth_first_search(Graph g) {
    Queue *q;
    int *aux, start;
    q = new_queue();
    aux = calloc(g -> V, sizeof(int));
    
    srand(time(NULL));
    start = rand() % g -> V;
    aux[start] = 1;
    enqueue(q, start);

    printf("Grafo letto a partire dal vertice %d: ", start + 1);
    print_item(start + 1);
    while (!is_empty_queue(q)) {
        int *row, u;
        u = dequeue(q);
        row = g -> A[u];
        for (int i = 0; i < g -> V; i++) {
            if (!aux[i] && row[i]) {
                print_item(i + 1);
                *(aux + i) = 1;
                enqueue(q, i);
            }
        }
    }
    printf("\n");
    delete_queue(&q);
    free(aux);
}

// Funzione utilizzata da 'graph_depth_first_search'
void graph_recursive_search(Graph g, int i, int *aux) {
    *(aux + i) = 1;
    
    int *row;
    row = g -> A[i];

    for (int i = 0; i < g -> V; i++) {
        if (!aux[i] && row[i]) {
            print_item(i + 1);
            graph_recursive_search(g, i, aux);
        }
    }
}