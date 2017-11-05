#include <stdio.h>
#include <stdlib.h>
#define N 46

typedef struct pilha {
	char dados[N];
	int topo;
} pilha;

int empilha (pilha*p, char x)
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
	int i = 0;
	char palavra[N];
	pilha p;
	p.topo = -1;
  
	printf("Digite uma palavra: ");
	fgets(palavra, N, stdin);
  
	while (palavra[i]) {
		if (empilha(&p, palavra[i]) == -1) {
			printf("Espaço insuficiente na pilha!\n");
			return -1;
		}
		i++;
	}
	while (p.topo > -1) {
		printf("%c", desempilha(&p));
	}
	printf("\n");
	return 0;
}
