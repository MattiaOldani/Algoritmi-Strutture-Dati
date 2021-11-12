#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *next;
};

void list_insert(int n, struct node **l);
void list_delete(int n, struct node **l);
void print_list(struct node *list);

int main() {
    struct node *list = NULL;
    for (int i = 0; i < 10; i++)
        list_insert(i, &list);
    print_list(list);
    for (int i = 0; i < 10; i += 3) {
        list_delete(i, &list);
        print_list(list);
    }
    while (list != NULL) {
        struct node *next = list -> next;
        free(list);
        list = next;
    }

    return 0;   
}

void list_insert(int n, struct node **l) {
    struct node *new = malloc(sizeof(struct node));
    new -> info = n;
    new -> next = *l;
    *l = new;
}

void list_delete(int n, struct node **l) {
    struct node *curr = *l, *prev = NULL;
    for (; curr != NULL && curr -> info != n; ) {
        prev = curr;
        curr = curr -> next;
    }

    if (curr == NULL) {
        printf("L'elemento da cancellare non esiste\n");
    } else if (prev == NULL) {
        struct node *head = *l;
        *l = head -> next;
        free(head);
    } else {
        prev -> next = curr -> next;
        free(curr);
    }
}

void print_list(struct node *list) {
    while (list != NULL) {
        printf("Nodo contenente %d\n", list -> info);
        list = list -> next;
    }
    printf("\n");
}