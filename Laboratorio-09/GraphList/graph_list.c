#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"graph_list.h"
#include"../Queue/queue.h"
#include"../Item/item.h"

// Funzione utilizzata da 'graph_depth_first_search'
void graph_recursive_search(Graph g, int i, int *aux);

// Crea un grafo con 'n' nodi e 'm' archi
Graph graph_new(int nv, int ne) {
    Graph new = malloc(sizeof(struct graph));
    new -> V = nv;
    new -> E = ne;
    new -> A = calloc(nv, sizeof(struct node *));
    return new;
}

// Distrugge il grafo
void graph_destroy(Graph g) {
    for (int i = 0; i < g -> V; i++) {
        Node *node = g -> A[i];
        Node *aux = NULL;
        while (node != NULL) {
            aux = node;
            node = node -> next;
            free(aux);
        }
    }
    free(g -> A);
    free(g);
}

// Inserisce l'arco (v, w) nel grafo
void graph_edgeinsert(Graph g, int v, int w) {
    Node *new_node = malloc(sizeof(struct node));
    new_node -> item = w;
    new_node -> next = NULL;

    Node *curr = g -> A[v - 1];
    Node *prev = NULL;

    while (curr != NULL) {
        prev = curr;
        curr = curr -> next;
    }
    if (prev == NULL)
        g -> A[v - 1] = new_node;
    else
        prev -> next = new_node;
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
    printf("Grafo letto elencando i vicini di ogni vertice:\n");
    for (int i = 0; i < g -> V; i++) {
        printf("Vertice: %d ---> Vicini: ", i + 1);
        for (Node *n = g -> A[i]; n != NULL; n = n -> next) {
            print_item(n -> item);
        }
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
        int u;
        u = dequeue(q);
        for (Node *n = g -> A[u]; n != NULL; n = n -> next) {
            int current = n -> item;
            if (!aux[current - 1]) {
                print_item(current);
                *(aux +current - 1) = 1;
                enqueue(q, current - 1);
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
    
    for (Node *node = g -> A[i]; node != NULL; node = node -> next) {
        if (!aux[node -> item - 1]) {
            print_item(node -> item);
            graph_recursive_search(g, node -> item - 1, aux);
        }
    }
}