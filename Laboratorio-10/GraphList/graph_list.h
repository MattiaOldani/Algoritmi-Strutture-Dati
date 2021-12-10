#ifndef GRAPH_LIST_H

#define GRAPH_LIST_H

#include"../Item/item.h"

struct node {
    Item info;
    struct node *next;
};

typedef struct node Node;

struct graph {
    int V;
    int E;
    Node **A;
};

typedef struct graph *GraphList;

// Crea un nuovo grafo con 'nv' vertici e 'ne' archi
GraphList new_graph(int nv, int ne);

// Popola il grafo leggendo gli archi da una matrice di adiacenza
GraphList matrix2graph(int **matr, int n);

// Inserisce un arco nel grafo
void edge_insert(GraphList gl, int start, int end);

// Stampa il grafo elencando per ogni vertice l'insieme dei vertici adiacenti
void print_graph(GraphList gl);

// De-alloca lo spazio occupato dal grafo
void delete_graph(GraphList *gl);
 
#endif