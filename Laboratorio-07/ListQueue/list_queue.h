#ifndef LIST_QUEUE_H

#define LIST_QUEUE_H

#include"../Item/item.h"

struct node {
    Item info;
    struct node *next;
};

typedef struct node* Node;

typedef struct {
    Node head;
    Node tail;
    int n_elements;
} Queue;

// Inizializza una coda vuota
Queue *new_queue();

// De-alloca lo spazio allocato dalla coda e mette un riferimento NULL
void delete_queue(Queue **q);

// Aggiunge un elemento in coda
void enqueue(Queue *q, Item item);

// Rimuove e ritorna l'elemento in testa
Item dequeue(Queue *q);

// Ritorna il valore in testa
Item frontValue(Queue *q);

// Ritorna '1' se la coda è vuota, '0' altrimenti
int  is_empty_queue(Queue *q);

// Stampa il contenuto della coda
void print_queue(Queue *q);

#endif