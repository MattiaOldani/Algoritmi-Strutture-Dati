#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
    int info;
    struct node *next;
};

bool list_insert(int n, struct node **l);
bool list_delete(int n, struct node **l);
void list_destroy(struct node *list);
void search(int n, struct node *l);
void print_list(struct node *l);
void clear();

int main() {
    int elements = 0;
    char ch;
    struct node *head = NULL;

    while ( (ch = getchar()) != 'f' ) {
        switch (ch) {
            int n;
            case '+':
                scanf("%d", &n);
                if (list_insert(n, &head))
                    elements++;
                clear();
                break;
            case '-':
                scanf(" %d", &n);
                if (list_delete(n, &head))
                    elements--;
                clear();
                break;
            case '?':
                scanf(" %d", &n);
                search(n, head);
                clear();
                break;
            case 'c':
                printf("L'insieme contiene %d elementi\n", elements);
                clear();
                break;
            case 'p':
                print_list(head);
                clear();
                break;
            case 'd':
                list_destroy(head);
                head = NULL;
                clear();
        }
    }
    list_destroy(head);

    return 0;
}

bool list_insert(int n, struct node **l) {
    struct node *p = *l;
    for (; p != NULL && p -> info != n; p = p -> next);

    if (p == NULL) {
        struct node *new = malloc(sizeof(struct node));
        new -> info = n;
        new -> next = *l;
        *l = new;
        return true;
    } else {
        return false;
    }
}

bool list_delete(int n, struct node **l) {
    struct node *curr = *l, *prev = NULL;
    for (; curr != NULL && curr -> info != n; ) {
        prev = curr;
        curr = curr -> next;
    }

    if (curr != NULL) {
        if (prev == NULL) {
            struct node *head = *l;
            *l = head -> next;
            free(head);
        } else {
            prev -> next = curr -> next;
            free(curr);
        }
        return true;
    } else {
        return false;
    }
}

void list_destroy(struct node *list) {
    for ( ; list != NULL; ) {
        struct node *p;
        p = list -> next;
        free(list);
        list = p;
    }
}

void search(int n, struct node *list) {
    struct node *p;
    while (p != NULL && p -> info != n)
        p = p -> next;
    if (p == NULL)
        printf("L'elemento %d non è presente nell'insieme\n", n);
    else
        printf("L'elemento %d è presente nell'insieme\n", n);
}

void print_list(struct node *l) {
    printf("Elementi dell'insieme: ");
    while (l != NULL) {
        printf("%d ", l -> info);
        l = l -> next;
    }
    printf("\n");
}

void clear() {
    char ch;
    while ( (ch = getchar()) != '\n');
}