#include<stdio.h>

#define MAX 10

int main() {
    printf("I primi %d quadrati perfetti sono: ", MAX);
    for (int i = 1; i <= MAX; i++) {
        printf("%d ", i*i);
    }
    printf("\n");
    return 0;
}