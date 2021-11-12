/*
    1:
        La funzone f1 restituisce 1
    2:
        'e' perchè il nodo con 'val = 1' non verrà chiamato con f1
        In generale, l'ultimo elemento della lista non viene chiamato con f1
        perchè l'espressione booleana che controlla  p -> next == NULL è
        verificata ogni volta che si è sull'ultimo nodo
        Ritorna 1 perchè nella prima chiamata si ha 2 < 1, mentre nella seconda
        si ha p -> next == NULL quindi return 1
    3:
        Se head è il puntatore alla testa di una lista qualsiasi formata da
        almeno 2 nodi, allora la chiamata f1(head) restituisce 1 se e solo
        gli elementi dei nodi sono ordinati in modo decrescente
    4:
        La funzione f2(head) restituisce il nodo con valore 1
    5:
        Se head è il puntatore alla testa di una lista qualsiasi formata da
        almeno 2 nodi, allora la chiamata f2(head) restituisce un puntatore al
        nodo con valore minimo della lista
*/

#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node *next;
};

typedef struct node* Node;

Node newNode(int val, Node p);
int f1(Node p);
Node f2(Node p);
Node f3 (Node p, Node q);

int main() {
    Node x = newNode(1, NULL);
	Node head = newNode(2, x);
}

Node newNode(int val, Node p) {
	Node new = malloc(sizeof(struct node));
	new -> val = val;
	new -> next = p;
	return new;
}

// Verifica se la lista ha nodi con valori ordinati in modo decrescente
int f1(Node p) {
	getchar();
	if (p -> next == NULL)
        return 1;
	else
		if (p -> val < p -> next -> val)
			return 0;
		else
			return f1(p -> next);
}

Node f2(Node p) {
	getchar();
	if (p -> next == NULL) 
		return p;
	else 
		return f3(p -> next, p);
}

Node f3(Node p, Node q) {
	Node temp;
	if (p -> val < q -> val)
		temp = p;
	else
		temp = q;
	if (p -> next == NULL)
		return temp;
	else 
		return f3(p -> next, temp);
}