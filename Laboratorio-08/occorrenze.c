#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include"./BinarySearchTree/binary_search_tree.h"
#include"./Item/item.h"

#define WORD 20

int main() {
    Bst_node root = NULL;

    // Primo input
    while (1) {
        int i = 0, counter = 0;
        char *word, ch;
        word = malloc((WORD + 1)* sizeof(char));

        ch = getchar();
        while (ch != ' ' && ch != '\n') {
            if (counter >= WORD) {
                printf("Inserita una parola troppo lunga\n");
                exit(EXIT_FAILURE);
            }
            if (!ispunct(ch))
                *(word + i++) = tolower(ch);
            counter++;
            ch = getchar();
        }
        *(word + i++) = '\0';

        if (strcmp(word, "stop") == 0)
            break;
        
        Item item = {word, 1};
        Bst_node find = bst_find(root, item);
        if (find == NULL)
            root = bst_insert(root, item);
        else
            find -> item . occ++;
    }

    printf("\nStampa delle occorrenze in ordine alfabetico\n");
    bst_inorder(root);

    printf("\nStampa delle occorrenze in ordine inverso\n");
    bst_invorder(root);

    bst_delete(&root);

    return 0;
}