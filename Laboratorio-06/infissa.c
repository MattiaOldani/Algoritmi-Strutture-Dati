#include<stdio.h>
#include<stdlib.h>
#include"./stack/stack.h"
#include"./stack/item.h"

int main() {
    char token[10], ch;

    make_empty();

    while (1) {
        scanf("%s", token);
        ch = getchar();
        switch (token[0]) {
            case '+':
            case '-':
            case '*':
            case '/':
                push(token[0]);
                break;
            case '(':
                break;
            case ')':
                print_item(pop());
                break;
            default:
                printf("%d ", atoi(token));
        }
        if (ch == '\n')
            break;
    }
    while (!is_empty())
        print_item(pop());
    printf("\n");

    make_empty();

    return 0;
}