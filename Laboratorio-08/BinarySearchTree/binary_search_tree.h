#ifndef BINARY_SEARCH__TREE_H

#define BINARY_SEARCH_TREE_H

#include"../Item/item.h"

struct bst_node {
    Item item;
    struct bst_node *l, *r;
};

typedef struct bst_node *Bst_node;

// Crea un nuovo albero binario con radice 'item'
Bst_node bst_new();

// De-alloca l'albero
void bst_delete(Bst_node *bst);

// Visita in profondità con ordine simmetrico
void bst_inorder(Bst_node bst);

// Visita in profondità con ordine inverso
void bst_invorder(Bst_node bst);

// Inserisce 'item' nell'albero
Bst_node bst_insert(Bst_node bst, Item item);

// Cancella l'elemento 'item' dall'albero, se presente
Bst_node bst_remove(Bst_node bst, Item item);

// Ricerca 'item' nell'albero e ritorna il sotto-albero
// con radice 'item' se lo trova, NULL altrimenti
Bst_node bst_find(Bst_node bst, Item item);

// Ritorna la chiave minima dell'albero
Item bst_min(Bst_node bst);

// Ritorna la chiave massima dell'albero
Item bst_max(Bst_node bst);

// Crea un albero binario dato un array
Bst_node bst_arr2tree(Item a[], int size);

#endif