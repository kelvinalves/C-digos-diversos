#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct pilha {
	int dados[N];
	int topo;
} pilha;

int empilha (pilha*p, int x)
{
	if (p->topo + 1 < N) {
		++(p->topo);
		p->dados[p->topo] = x;
		return 1;
	}
	return -1;
}

int desempilha (pilha*p)
{
	--(p->topo);
	return p->dados[p->topo + 1];
}

int main ()
{
	pilha bin;
	int x = 22;
	bin.topo = -1;
	while (x) {
		if (empilha(&bin, x%2) == -1) {
			printf("Espaço insuficiente na pilha!\n");
			return -1;
		}
	x /= 2;
	}
	while (bin.topo > -1) {
		printf("%d", desempilha(&bin));
	}
	printf("\n");
	return 0;
}
