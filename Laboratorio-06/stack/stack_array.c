#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

int stack[100];
int index = -1;

// Svuota la pila
void make_empty() {
    index = -1;
}

// Restituisce 1 se la pila è vuota, 0 altrimenti
int is_empty() {
    if (index == -1)
        return 1;
    return 0;
}

// Se la pila non è vuota, restituisce il top
// Altrimenti esce con un messaggio di errore
int top() {
    if (is_empty())
        exit(EXIT_FAILURE);
    return stack[index];
}

// Se la pila non è vuota, estrae il top della pila
// Altrimenti esce con un messaggio di errore
int pop() {
    if (is_empty())
        exit(EXIT_FAILURE);
    return stack[--index];
}

// Se c'è spazio, aggiunge 'n' alla pila
// Altrimenti esce con un messaggio di errore
void push(int n) {
    if (index == 99)
        exit(EXIT_FAILURE);
    else
        stack[++index] = n;
}

// Stampa il contenuto della pila, partendo dal top
void print_stack() {
    printf("Contenuto della pila: ");
    for (int i = 0; i <= index; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}