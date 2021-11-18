#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *next;
};

typedef struct node *Node;

typedef struct {
    Node head;
    Node tail;
} *List_with_tail;

Node new_node(int e);
void addAtEnd(List_with_tail l, int e);

int main() {
    /*
        Belli sti esercizi di copia e incolla kek
    */

    return 0;
}

Node new_node(int e) {
    Node new = malloc(sizeof(struct node));
    new -> info = e;
    new -> next = NULL;
    return new;
}

void addAtEnd(List_with_tail l, int e) {
    if (l -> tail == NULL) {
        l -> tail = new_node(e);
        l -> head = l -> tail;
    } else {
        l -> tail -> next = new_node(e);
        l -> tail = l -> tail -> next;
    }
}