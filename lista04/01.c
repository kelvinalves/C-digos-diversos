#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ponto {
	float x, y, z;
} ponto;

void coordenadas (ponto*p, char c)
{
	printf("Informe as coordenadas do ponto %c: ", c);
	scanf("%f %f %f", &p->x, &p->y, &p->z);
}

float distancia (ponto*a, ponto*b)
{
	float norma;

	norma = sqrt(pow((b->x - a->x),2) + pow((b->y - a->y),2) + pow((b->z - a->z),2));

	return norma;
}

int main()
{
	ponto a, b;

	coordenadas(&a, 'A');
	coordenadas(&b, 'B');

	printf("A distância entre o ponto A e o ponto B é %.2f\n", distancia(&a, &b));

	return 0;
}
