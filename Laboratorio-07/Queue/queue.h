#ifndef QUEUE_H

#define QUEUE_H

#include"../Item/item.h"

typedef struct {
    int front;
    int rear;
    int len;
    int n_elements;
    int *array;
} Queue;

// Crea una nuova coda vuota
Queue *new_queue(int n);

// De-alloca la memoria occupata dalla coda
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