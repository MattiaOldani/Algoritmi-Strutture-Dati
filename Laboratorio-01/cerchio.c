#include<stdio.h>
#include<math.h>

int main() {
    float raggio;
    printf("Inserire il raggio del cerchio: ");
    scanf("%f", &raggio);
    printf("L'area del cerchio è: %f\n", raggio * raggio * M_PI);
    return 0;
}