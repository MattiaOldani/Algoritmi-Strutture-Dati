#ifndef BINARY_TREE_H

#define BINARY_TREE_H

#include"../Item/item.h"

struct bit_node {
    Item item;
    struct bit_node *l, *r;
};

typedef struct bit_node *Bit_node;

// Crea un nuovo albero binario
Bit_node bit_new(Item item);

// De-alloca l'albero
void bit_delete(Bit_node bit);

// Visita in profondità con ordine anticipato
void bit_preorder(Bit_node bit);

// Visita in profondità con ordine simmetrico
void bit_inorder(Bit_node bit);

// Visita in profondità con ordine posticipato
void bit_postorder(Bit_node bit);

// Visita in profondità con ordine anticipato a sommario
void bit_printassummary(Bit_node bit, int spaces);

// Crea un albero binario dato un array
Bit_node bit_arr2tree(Item a[], int size, int i);

#endif