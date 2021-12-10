#include<stdio.h>
#include<stdlib.h>
#include"queue.h"
#include"../Item/item.h"

// Inizializza una coda vuota
Queue *new_queue() {
    Queue *new;
    new = malloc(sizeof(Queue));
    new -> head = NULL;
    new -> tail = NULL;
    new -> n_elements = 0;
    return new;
}

// De-alloca lo spazio allocato dalla coda e mette un riferimento NULL
void delete_queue(Queue **q) {
    Element *p = (*q) -> head;
    while (p != NULL) {
        Element *next = p -> next;
        free(p);
        p = next;
    }
    free(*q);
    *q = NULL;
}

// Aggiunge un elemento in coda
void enqueue(Queue *q, Item item) {
    Element *new_node;
    new_node = malloc(sizeof(struct element));
    new_node -> info = item;
    new_node -> next = NULL;
    if (q -> tail == NULL) {
        q -> tail = new_node;
        q -> head = new_node;
    } else  {
        q -> tail -> next = new_node;
        q -> tail = new_node;
    }
    q -> n_elements++;
}

// Rimuove e ritorna l'elemento in testa
Item dequeue(Queue *q) {
    Item info = q -> head -> info;
    Element *delete = q -> head;
    q -> head = q -> head -> next;
    free(delete);
    q -> n_elements--;
    if (q -> n_elements == 0)
        q -> tail = NULL;
    return info;
}

// Ritorna il valore in testa
Item frontValue(Queue *q) {
    return q -> head -> info;
}

// Ritorna '1' se la coda è vuota, '0' altrimenti
int  is_empty_queue(Queue *q) {
    return q == NULL || q -> n_elements == 0;
}

// Stampa il contenuto della coda
void print_queue(Queue *q) {
    if (q == NULL || q -> n_elements == 0) {
        printf("Coda vuota\n");
        return;
    }

    printf("Coda: ");
    Element *p = q -> head;
    while (p != NULL) {
        print_item(p -> info);
        p = p -> next;
    }
    printf("\n");
}