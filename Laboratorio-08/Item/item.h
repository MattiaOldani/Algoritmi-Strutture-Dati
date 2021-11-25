#ifndef ITEM_H

#define ITEM_H

typedef struct item {
    char *word;
    int occ;
}Item;

// Stampa 'item'
void print_item(Item item);

#endif