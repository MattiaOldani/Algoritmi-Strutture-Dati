#include<stdio.h>

int main() {
    int n;
    printf("Inserire n: ");
    scanf("%d", &n);

    printf("Inserire la sequenza di numeri: ");
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x != i) {
            printf("%d\n", i);
            break;
        } else if (i == n - 1) {
            printf("%d\n", n);
        }
    }

    return 0;
}