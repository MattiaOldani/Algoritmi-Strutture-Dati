#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"./stack/stack.h"
#include"./stack/item.h"

int tag_equals(char *tag1, char *tag2);

int main() {
    make_empty();

    while (1) {
        int size = 3, i = 0;
        char *in, ch;
        in = malloc(size * sizeof(char));
        ch = getchar();
        while ( ch != ' ' && ch != '\n') {
            if (i >= size) {
                size *= 2;
                in = realloc(in, size);
            }
            *(in + i++) = ch;
            ch = getchar();
        }
        if (i >= size) {
            size *= 2;
            in = realloc(in, size);
            *(in + i++) = '\0';
        }
        if (in[1] != '/')
            push(in);
        else {
            if (!is_empty()) {
                if (tag_equals(in, pop()) == 0) {
                    printf("Il documento non è ben formato\n");
                    make_empty();
                    return 0;
                }
            } else {
                printf("Il documento non è ben formato\n");
                make_empty();
                return 0;
            }
        }
        if (ch == EOF || ch == '\n')
            break;
    }
    printf("Il documento è ben formato\n");
    make_empty();

    return 0;
}

int tag_equals(char *tag1, char *tag2) {
    printf("%s %s\n", tag1, tag2);
    int i = 2, j = 1; 
    for ( ; *(tag1 + i) != '>' && *(tag2 + j) != '>'; i++, j++)
        if (*(tag1 + i) != *(tag2 + j))
            return 0;
    if (*(tag1 + i) == '>') {
        if (*(tag2 + j) == '>')
            return 1;
    }
    return 0;
}