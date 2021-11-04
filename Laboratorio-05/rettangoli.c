#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct {
    float x, y;
} Punto;

typedef struct {
    Punto p1, p2;
} Rettangolo;

int main() {
    float b, h, area, duep;
    Rettangolo *r;
    r = malloc(sizeof(Rettangolo));

    if (r == NULL) {
        printf("Errore nell'allocazione della memoria");
        return 0;
    }

    printf("Inserisci le coordinate del punto in basso a sx: ");
    scanf(" %f %f", &r -> p1.x, &r -> p1.y);
    printf("Inserisci le coordinate del punto in alto a dx: ");
    scanf(" %f %f", &r -> p2.x, &r -> p2.y);

    b = r -> p2.x - r -> p1.x;
    h = r -> p2.y - r -> p1.y;
    area = b * h / 2;
    duep = 2 * (b + h);
    printf("Area del rettangolo: %f\n", area);
    printf("Perimetro del rettangolo: %f\n", duep);
    free(r);

    return 0;
}
