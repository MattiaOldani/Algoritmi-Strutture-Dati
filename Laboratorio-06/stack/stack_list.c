#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#include"item.h"

struct node {
    Item info;
    struct node *next;
};

struct node *stack;

// Svuota la pila
void make_empty() {
    if (stack != NULL) {
        struct node *p;
        while (stack != NULL) {
            p = stack -> next;
            free(stack -> info);
            free(stack);
            stack = p;
        }
    } else {
        stack = NULL;
    }
}

// Restituisce 1 se la pila è vuota, 0 altrimenti
int is_empty() {
    if (stack == NULL)
        return 1;
    return 0;
}

// Se la pila non è vuota, restituisce il top
// Altrimenti esce con un messaggio di errore
Item top() {
    if (stack == NULL)
        exit(EXIT_FAILURE);
    return stack -> info;
}

// Se la pila non è vuota, estrae il top della pila
// Altrimenti esce con un messaggio di errore
Item pop() {
    Item value = stack -> info;
    stack = stack -> next;
    return value;
}

// Se c'è spazio, aggiunge 'n' alla pila
// Altrimenti esce con un messaggio di errore
void push(Item item) {
    struct node *new;
    new = malloc(sizeof(struct node));
    new -> info = item;
    new -> next = stack;
    stack = new;
}

// Stampa il contenuto della pila, partendo dal top
void print_stack() {
    struct node *p = stack;
    printf("Contenuto della pila: ");
    while (p != NULL) {
        print_item(p -> info);
        p = p -> next;
    }
    printf("\n");
}