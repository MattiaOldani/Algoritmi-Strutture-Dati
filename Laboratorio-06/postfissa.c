#include<stdio.h>
#include<stdlib.h>
#include"./stack/stack.h"
#include"./stack/item.h"

int main() {
    char token[10], ch;
    make_empty();

    while(1) {
        scanf("%s", token);
        ch = getchar();
        switch (token[0]) {
            Item x, y, n;
            case '+':
                x = pop();
                y = pop();
                push(x + y);
                break;
            case '-':
                x = pop();
                y = pop();
                push(x - y);
                break;
            case '*':
                x = pop();
                y = pop();
                push(x * y);
                break;
            case '/':
                x = pop();
                y = pop();
                push(x / y);
                break;
            default:
                n = atoi(token);
                push(n);
        }
        if (ch == '\n')
            break;
    }
    printf("Risultato: %d\n", pop());

    make_empty();

    return 0;
}