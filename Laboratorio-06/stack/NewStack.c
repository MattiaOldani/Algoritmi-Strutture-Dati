#include<stdio.h>
#include<stdlib.h>
#include"NewStack.h"
#include"item.h"

struct node {
    Item info;
    struct node *next;
};

// Crea la pila
Stack *create_stack() {
    Stack *new;
    new = malloc(sizeof(Stack));
    new -> element = NULL;
    return new;
}

void delete_stack(Stack *s) {

}

// Svuota la pila
void make_empty(Stack *s) {
    struct node *p;
    p = s -> element;
    while (p != NULL) {
        struct node *q;
        q = p -> next;
        free(p);
        p = q;
    }
    s -> element = NULL;
}

// Restituisce 1 se la pila è vuota, 0 altrimenti
int is_empty(Stack *s) {
    if (s == NULL)
        return 1;
    return 0;
}

// Se la pila non è vuota, restituisce il top
// Altrimenti esce con un messaggio di errore
Item top(Stack *s) {
    if (s == NULL)
        exit(EXIT_FAILURE);
    return s -> element -> info;
}

// Se la pila non è vuota, estrae il top della pila
// Altrimenti esce con un messaggio di errore
Item pop(Stack *s) {
    Item value = s -> element -> info;
    s -> element = s -> element -> next;
    return value;
}

// Se c'è spazio, aggiunge 'n' alla pila
// Altrimenti esce con un messaggio di errore
void push(Stack *s, Item item) {
    Stack *new;
    new = malloc(sizeof(struct node));
    new -> element -> info = item;
    new -> element -> next = s -> element;
    s = new;
}

// Stampa il contenuto della pila, partendo dal top
void print_stack(Stack *s) {
    struct node *p = s -> element;
    printf("Contenuto della pila: ");
    while (p != NULL) {
        print_item(p -> info);
        p = p -> next;
    }
    printf("\n");
}