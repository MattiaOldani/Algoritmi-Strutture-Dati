#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *next;
};

void list_insert(int n, struct node **l);
void print_list(struct node *list);
void print_list_inv(struct node *list);
int *list_to_array(struct node *list);
void list_destroy_it(struct node *list);
void list_destroy_ric(struct node *list);
int number_of_elements(struct node *list);

int main() {
    struct node *list = NULL;
    for (int i = 0; i < 10; i++)
        list_insert(i, &list);
    
    printf("Lista stampata in modo iterativo: ");
    print_list(list);
    printf("Lista stampata in modo ricorsivo: ");
    print_list_inv(list);
    printf("\n");

    int *arr = list_to_array(list);
    int n = number_of_elements(list);
    printf("Array creato dalla lista: ");
    for (int i = 0; i < n; i++)
        printf("%d ", *(arr + i));
    printf("\n");
    
    list_destroy_it(list);
    // list_destroy_ric(list);
    free(arr);

    return 0;
}

void list_insert(int n, struct node **l) {
    struct node *new = malloc(sizeof(struct node));
    new -> info = n;
    new -> next = *l;
    *l = new;
}

void print_list(struct node *list) {
    while (list != NULL) {
        printf("%d ", list -> info);
        list = list -> next;
    }
    printf("\n");
}

void print_list_inv(struct node *list) {
    if (list != NULL) {
        print_list_inv(list -> next);
        printf("%d ", list -> info);
    }
}

int *list_to_array(struct node *list) {
    int counter = number_of_elements(list);
    int *arr = malloc(counter * sizeof(int));
    for (int i = 0; i < counter; i++, list = list -> next)
        *(arr + i) = list -> info;
    return arr;
}

void list_destroy_it(struct node *list) {
    for ( ; list != NULL; ) {
        struct node *p;
        p = list -> next;
        free(list);
        list = p;
    }
}

void list_destroy_ric(struct node *list) {
    if (list != NULL) {
        list_destroy_ric(list -> next);
        free(list);
    }   
}

int number_of_elements(struct node *list) {
    int counter = 0;
    for (struct node *p = list; p != NULL; p = p -> next, counter++);
    return counter;
}