#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node {
    int info;
    struct node *next;
};

struct node *olist_insert(int n, struct node *l);
struct node *olist_search(int n, struct node *l);
void print_list(struct node *list);
void list_destroy(struct node *list);

int main() {
    struct node *list = NULL;
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        int n = rand() % 10000;
        list = olist_insert(n, list);
        printf("Estratto il numero %d\n", n);
        print_list(list);
    }
    list_destroy(list);

    return 0;
}

struct node *olist_insert(int n, struct node *l) {
    struct node *curr = l, *prev = NULL;
    for ( ; curr != NULL && curr -> info < n ; ) {
        prev = curr;
        curr = curr -> next;
    }
    struct node *new;
    new = malloc(sizeof(struct node));
    new -> info = n;
    new -> next = curr;
    if (prev == NULL)
        l = new;
    else
        prev -> next = new;
    return l;
}

struct node *olist_search(int n, struct node *l) {
    struct node *p = l;
    while (p != NULL && p -> info < n)
        p = p -> next;
    if (p -> info == n)
        return p;
    else
        return NULL;
}

void print_list(struct node *list) {
    while (list != NULL) {
        printf("%d ", list -> info);
        list = list -> next;
    }
    printf("\n");
}

void list_destroy(struct node *list) {
    for ( ; list != NULL; ) {
        struct node *p;
        p = list -> next;
        free(list);
        list = p;
    }
}