#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c;
    printf("Inserisci a: ");
    scanf("%f", &a);
    printf("Inserisci b: ");
    scanf("%f", &b);
    printf("Inserisci c: ");
    scanf("%f", &c);
    float delta = - (b * b - 4 * a * c);
    
    printf("Le soluzioni dell'equazione sono:\n");
    printf("x1 = %f + i*%f\n", -b / 2*a, sqrt(delta) / 2*a);
    printf("x2 = %f + i*%f\n", -b / 2*a, -sqrt(delta) / 2*a);
    return 0;
}