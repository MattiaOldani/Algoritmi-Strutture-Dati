#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *list_insert_1(int n, struct node *l);
void list_insert_2(int n, struct node **l);
struct node *list_search(int n, struct node *l);
void print_list(struct node *list);

int main() {
    int flag = 1;
    struct node *list1 = NULL, *list2 = NULL;
    while(flag) {
        char option;
        int n;
        printf("\nI- Inserisci\nC- Cerca\nS- Stampa\nF- Fine\nOpzione scelta: ");
        scanf(" %c", &option);
        switch (option) {
            case 'I':
                printf("Inserisci il valore del nodo: ");
                scanf(" %d", &n);
                list1 = list_insert_1(n, list1);
                list_insert_2(n, &list2);
                break;
            case 'C':
                printf("Inserisci il valore da cercare: ");
                scanf(" %d", &n);
                if (list_search(n, list1) != NULL)
                    printf("Elemento trovato\n");
                else
                    printf("Elemento non trovato\n");
                break;
            case 'S':
                print_list(list1);
                // print_list(list2);
                break;
            case 'F':
                while (list1 != NULL) {
                    struct node *next1 = list1 -> next;
                    struct node *next2 = list2 -> next;
                    free(list1);
                    free(list2);
                    list1 = next1;
                    list2 = next2;
                }
                flag = 0;
        } 
    }

    return 0;
}

struct node *list_insert_1(int n, struct node *l) {
    struct node *new = malloc(sizeof(struct node));
    new -> info = n;
    new -> next = l;
    return new;
}

void list_insert_2(int n, struct node **l) {
    struct node *new = malloc(sizeof(struct node));
    new -> info = n;
    new -> next = *l;
    *l = new;
}

struct node *list_search(int n, struct node *l) {
    for ( ; l != NULL && l -> info != n; l = l -> next);
    return l;
}

void print_list(struct node *list) {
    while (list != NULL) {
        printf("Nodo contenente %d\n", list -> info);
        list = list -> next;
    }
}