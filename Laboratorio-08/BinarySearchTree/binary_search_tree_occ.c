#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"binary_search_tree.h"
#include"../Item/item.h"

// Crea un nuovo albero binario con radice 'item'
Bst_node bst_new(Item item) {
    Bst_node new = malloc(sizeof(struct bst_node));
    new -> l = NULL;
    new -> r = NULL;
    new -> item = item;
    return new;
}

// De-alloca l'albero
void bst_delete(Bst_node *bst) {
    if (*bst == NULL)
        return;

    Bst_node *root = bst;
    bst_delete(&((*bst) -> l));
    bst_delete(&((*bst) -> r));
    free((*root) -> item . word);
    free(*root);
    *bst = NULL;
}

// Visita in profondità con ordine simmetrico
void bst_inorder(Bst_node bst) {
    if (bst == NULL)
        return;
    bst_inorder(bst -> l);
    print_item(bst -> item);
    bst_inorder(bst -> r);
}

// Visita in profondità con ordine inverso
void bst_invorder(Bst_node bst) {
    if (bst == NULL)
        return;
    bst_invorder(bst -> r);
    print_item(bst -> item);
    bst_invorder(bst -> l);
}

// Inserisce 'item' nell'albero
Bst_node bst_insert(Bst_node bst, Item item) {
    if (bst == NULL)
        return bst_new(item);
    
    Bst_node root = bst;
    if (strcmp(item . word, bst -> item . word) < 0)
        bst -> l = bst_insert(bst -> l, item);
    else
        bst -> r = bst_insert(bst -> r, item);
    return root;
}

// Cancella l'elemento 'item' dall'albero, se presente
Bst_node bst_remove(Bst_node bst, Item item) {
    Bst_node curr = bst, prev = NULL;
    while (curr != NULL && strcmp(curr -> item . word, item . word) != 0) {
        prev = curr;
        curr = (strcmp(item . word,  curr -> item . word) < 0 ? curr -> l : curr -> r);
    }
    if (curr != NULL) {
        if (curr -> l == NULL) {
            if (prev != NULL) {
                if (strcmp(curr -> item . word, prev -> item . word) < 0)
                    prev -> l = curr -> r;
                else
                    prev -> r = curr -> r;
            } else {
                bst = curr -> r;
            }
            free(curr -> item . word);
            free(curr);
        } else if (curr -> r == NULL) {
            if (prev != NULL) {
                if (strcmp(curr -> item . word, prev -> item. word) < 0)
                    prev -> l = curr -> l;
                else
                    prev -> r = curr -> l;
            } else {
                bst = curr -> l;
            }
            free(curr -> item . word);
            free(curr);
        } else {
            Bst_node other_prev = curr, max = curr -> l;
            while (max -> r != NULL) {
                other_prev = max;
                max = max -> r;
            }
            curr -> item = max -> item;
            if (curr == other_prev)
                curr -> l = max -> l;
            else
                other_prev -> r = max -> l;
            free(max -> item . word);
            free(max);
        }
    }
    return bst;
}

// Ricerca 'item' nell'albero e ritorna il sotto-albero
// con radice 'item' se lo trova, NULL altrimenti
Bst_node bst_find(Bst_node bst, Item item) {
    Bst_node curr = bst;
    while (curr != NULL && strcmp(curr -> item . word, item . word) != 0) {
        curr = (strcmp(item .word, curr -> item . word) < 0 ? curr -> l : curr -> r);
    }
    return curr;
}

// Ritorna la chiave minima dell'albero
Item bst_min(Bst_node bst) {
    Bst_node curr = bst, prev = NULL;
    while (curr != NULL) {
        prev = curr;
        curr = curr -> l;
    }
    return prev -> item;
}

// Ritorna la chiave massima dell'albero
Item bst_max(Bst_node bst) {
    Bst_node curr = bst, prev = NULL;
    while (curr != NULL) {
        prev = curr;
        curr = curr -> r;
    }
    return prev -> item;
}

// Crea un albero binario dato un array
Bst_node bst_arr2tree(Item a[], int size) {
    Bst_node root = bst_new(a[0]);

    for (int i = 1; i < size; i++) {
        root = bst_insert(root, a[i]);
    }

    return root;
}