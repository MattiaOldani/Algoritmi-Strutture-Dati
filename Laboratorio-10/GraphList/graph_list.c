#include<stdio.h>
#include<stdlib.h>
#include"graph_list.h"
#include"../Item/item.h"

// Crea un nuovo grafo con 'nv' vertici e 'ne' archi
GraphList new_graph(int nv, int ne) {
    GraphList gl = malloc(sizeof(struct graph));
    gl -> V = nv;
    gl -> E = ne;
    gl -> A = calloc(nv, sizeof(Node));
    return gl;
}

// Popola il grafo leggendo gli archi da una matrice di adiacenza
GraphList matrix2graph(int **matr, int n) {
    int counter = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (matr[i][j] == 1)
                counter++;
    
    GraphList gl = new_graph(n, counter);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (matr[i][j] == 1)
                edge_insert(gl, i, j);
    
    return gl;
}

// Inserisce un arco nel grafo
void edge_insert(GraphList gl, int start, int end) {
    Node *new_node;
    new_node = malloc(sizeof(struct node));
    new_node -> info = end;
    new_node -> next = NULL;

    Node *current = gl -> A[start];
    Node *previous = NULL;
    while (current != NULL) {
        previous = current;
        current = current -> next;
    }

    if (previous == NULL)
        gl -> A[start] = new_node;
    else
        previous -> next = new_node;
}

// Stampa il grafo elencando per ogni vertice l'insieme dei vertici adiacenti
void print_graph(GraphList gl) {
    for (int i = 0; i < gl -> V; i++) {
        printf("Vertice: %d || Vicini: ", i);
        Node *list = gl -> A[i];
        while (list != NULL) {
            print_item(list -> info);
            list = list -> next;
        }
        printf("\n");
    }
}

// De-alloca lo spazio occupato dal grafo
void delete_graph(GraphList *gl) {
    for (int i = 0; i < (*gl) -> V; i++) {
        Node *list = (*gl) -> A[i];
        while (list != NULL) {
            Node *next = list -> next;
            free(list);
            list = next;
        }
    }
    free(*gl);
    *gl = NULL;
}