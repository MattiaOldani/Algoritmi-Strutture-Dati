#ifndef GRAPH_MATRIX_H

#define GRAPH_MATRIX_H

#include"../Item/item.h"

struct graph {
    int V;
    int E;
    int **A;
};

typedef struct graph *Graph;

// Crea un grafo con 'n' nodi e 'm' archi
Graph graph_new(int nv, int ne);

// Distrugge il grafo
void graph_destroy(Graph g);

// Inserisce l'arco (v, w) e l'arco (w, v) nel grafo
void graph_edgeinsert(Graph g, int v, int w);

// Legge da STDIN un grafo
// FORMATO:
//  - Inserire 'E' archi nel formato vertice_partenza, vertice_arrivo, uno per riga
void graph_read(Graph g);

// Stampa su STDOUT per ogni vertice la lista dei suoi vicini
void graph_print(Graph g);

// Stampa su STDOUT un grafo tramite visita in profondità
void graph_depth_first_search(Graph g);

// Stampa su STDOUT un grafo tramite visita in ampiezza
void graph_breadth_first_search(Graph g);

#endif