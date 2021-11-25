#include<stdio.h>
#include<stdlib.h>
#include"binary_tree.h"
#include"../Item/item.h"

// Crea un nuovo albero binario
Bit_node bit_new(Item item) {
    Bit_node new = malloc(sizeof(Bit_node));
    new -> l = NULL;
    new -> r = NULL;
    new -> item = item;
    return new;
}

// De-alloca l'albero
void bit_delete(Bit_node bit) {
    if (bit == NULL)
        return;
 
    Bit_node root = bit;
    bit_delete(bit -> l);
    bit_delete(bit -> r);
    free(root);
}

// Visita in profondità con ordine anticipato
void bit_preorder(Bit_node bit) {
    if (bit == NULL)
        return;
    print_item(bit -> item);
    bit_preorder(bit -> l);
    bit_preorder(bit -> r);
}

// Visita in profondità con ordine simmetrico
void bit_inorder(Bit_node bit) {
    if (bit == NULL)
        return;
    bit_inorder(bit -> l);
    print_item(bit -> item);
    bit_inorder(bit -> r);
}

// Visita in profondità con ordine posticipato
void bit_postorder(Bit_node bit) {
    if (bit == NULL)
        return;
    bit_postorder(bit -> l);
    bit_postorder(bit -> r);
    print_item(bit -> item);
}

// Visita in profondità con ordine anticipato a sommario
void bit_printassummary(Bit_node bit, int spaces) {
    if (bit == NULL)
        return;
    
    for (int i = 0; i < spaces; i++)
        printf(" ");
    print_item(bit -> item);
    
    if (bit -> l == NULL && bit -> r == NULL)
        return;

    if (bit -> l == NULL) {
        for (int i = 0; i < spaces + 1; i++)
            printf(" ");
        printf("*\n");
    } else {
        bit_printassummary(bit -> l, spaces + 1);
    }
    
    if (bit -> r == NULL) {
        for (int i = 0; i < spaces + 1; i++)
            printf(" ");
        printf("*\n");
    } else {
        bit_printassummary(bit -> r, spaces + 1);
    }
}

// Crea un albero binario dato un array
Bit_node bit_arr2tree(Item a[], int size, int i) {
    Bit_node root = bit_new(a[i]);
    
    if (2 * i + 1 >= size)
        root -> l = NULL;
    else
        root -> l = bit_arr2tree(a, size, 2 * i + 1);
    
    if (2 * i + 2 >= size)
        root -> r = NULL;
    else
        root -> r = bit_arr2tree(a, size, 2 * i + 2);
    
    return root;
}