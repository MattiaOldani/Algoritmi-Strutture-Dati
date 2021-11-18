#ifndef STACK_H

#define STACK_H

#include"item.h"

// Svuota la pila
void make_empty();

// Restituisce 1 se la pila è vuota, 0 altrimenti
int is_empty();

// Se la pila non è vuota, restituisce il top
// Altrimenti esce con un messaggio di errore
Item top();

// Se la pila non è vuota, estrae il top della pila
// Altrimenti esce con un messaggio di errore
Item pop();

// Se c'è spazio, aggiunge 'n' alla pila
// Altrimenti esce con un messaggio di errore
void push(Item item);

// Stampa il contenuto della pila, partendo dal top
void print_stack();

#endif