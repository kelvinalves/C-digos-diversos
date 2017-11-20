#include <stdio.h>
#include <stdlib.h>

typedef struct tempo {
 	int m, s, d; 
} tempo;

int medida (tempo *t, int n)
{
	printf("Medida t%d: ", n);
	scanf("%d %d %d", &t->m, &t->s, &t->d);

	return t->m * 6000 + t->s * 100 + t->d;
}

tempo diferenca (tempo *t1, tempo *t2)
{
	int resto;
	resto = medida(&*t2, 2) - medida(&*t1, 1);

	t2->m = resto / 6000;
	t2->s = (resto % 6000) / 100;
	t2->d = (resto % 6000) % 100;

	return *t2;
}

int main()
{
	tempo t1, t2;

	t2 = diferenca(&t1, &t2);

	if (t2.d < 0) printf("(t2 - t1) = - %.2dmin %.2ds %.2d\n", -t2.m, -t2.s, -t2.d);
	else printf("(t2 - t1) = %.2dmin %.2ds %.2d\n", t2.m, t2.s, t2.d);

	return 0;
}
