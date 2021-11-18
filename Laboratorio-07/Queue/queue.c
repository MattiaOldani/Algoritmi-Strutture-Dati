#include<stdio.h>
#include<stdlib.h>
#include"queue.h"
#include"../Item/item.h"

// Crea una nuova coda vuota
Queue *new_queue(int n) {
    Queue *new;
    new = malloc(sizeof(Queue));
    new -> front = -1;
    new -> rear = -1;
    new -> n_elements = 0;
    new -> len = n;
    new -> array = malloc(n * sizeof(int));
    return new;
}

// De-alloca la memoria occupata dalla coda e mette il riferiment a NULL
void delete_queue(Queue **q) {
    free((*q) -> array);
    free(*q);
    *q = NULL;
}

// Aggiunge un elemento in coda
void enqueue(Queue *q, Item item) {
    if (q -> n_elements == q -> len)
        return;
    q -> array[(q -> rear++) % q -> len] = item;
    q -> n_elements++;
}

// Rimuove e ritorna l'elemento in testa
Item dequeue(Queue *q) {
    Item element;
    element = q -> array[q -> front];
    q -> front = (q -> front + 1) % q -> len;
    q -> n_elements--;
    return element;
}

// Ritorna il valore in testa
Item frontValue(Queue *q) {
    return q -> array[q -> front];
}

// Ritorna '1' se la coda è vuota, '0' altrimenti
int is_empty_queue(Queue *q) {
    return q == NULL || q -> n_elements == 0;
}

// Stampa il contenuto della coda
void print_queue(Queue *q) {
    if (q == NULL || q -> n_elements == 0) {
        printf("Coda vuota\n");
        return;
    }
    printf("Coda: ");
    if (q -> front > q -> rear) {
        for (int i = q -> front; i < q -> n_elements + q -> front; i++) {
            print_item(q -> array[i % q -> len]);
        }
    } else {
        for (int i = q -> front; i < q -> rear; i++) {
            print_item(q -> array[i]);
        }
    }
    printf("\n");
}