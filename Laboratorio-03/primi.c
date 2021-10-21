#include<stdio.h>
#include<math.h>

int primo(int n);

int main() {
    int n;
    printf("Inserisci n: ");
    scanf("%d", &n);

    if (primo(n)) {
        printf("%d è primo\n", n);
    } else {
        printf("%d non è primo\n", n);
    }

    return 0;
}

int primo(int n) {
    for (int i = 2; i < (int)sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}