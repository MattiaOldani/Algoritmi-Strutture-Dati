#include<stdio.h>
#include<stdlib.h>
#include"./stack/NewStack.h"
#include"./stack/item.h"

int main() {
    Stack *p, *q;
    p = create_stack();
    q = create_stack();

    push(p);

    return 0;
}