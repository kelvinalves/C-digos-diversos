#include <stdio.h> 
#include <stdlib.h>

typedef struct adjacencia {
	int destino;
	struct adjacencia* proxima;
} incidencia;

typedef struct lista {
	incidencia* lider;  
} lista;

typedef struct grafo {
	int rotulo;
	lista* vertice; 
} vetor;

incidencia* inserir(int destino);
vetor* criar(int nome);
void aresta(vetor* grafo, int origem, int destino);
void imprimir(vetor* grafo);

int main()
{
	int quantidade, origem, operador, destino;
	printf("Informe o número de vértices: ");
	scanf("%d", &quantidade);
	vetor* grafo = criar(quantidade);
	
	do {
		printf("\n0 -> Sair\n");
		printf("1 -> Adicionar aresta\n");
		printf("2 -> Imprimir\n");
		printf("Opção: ");
		scanf("%d", &operador);
		
		switch(operador) {
			
			case 1:
				printf("Informe os vértices de origem e destino: ");
				scanf("%d %d", &origem, &destino);
				aresta(grafo, origem-1, destino-1);
				break;

			case 2:
				imprimir(grafo);
				break;

			default:
				if(operador)
					printf("Informe uma opção válida\n\n");

		}

	} while(operador);
	
	return 0; 
}

incidencia* inserir(int destino)
{
	incidencia* vertice = (incidencia*)malloc(sizeof(incidencia));
	vertice->destino = destino;
	vertice->proxima = NULL;
	return vertice;
}
  
vetor* criar(int nome)
{
	vetor* grafo = (vetor*)malloc(sizeof(vetor));
	grafo->rotulo = nome;
	grafo->vertice = (lista*)malloc(nome*sizeof(lista));
	
	for (int i = 0; i < nome; ++i)
		grafo->vertice[i].lider = NULL;
	
	return grafo; 
}

void aresta(vetor* grafo, int origem, int destino)
{
	incidencia* celula = inserir(destino);
	celula->proxima = grafo->vertice[origem].lider;
	grafo->vertice[origem].lider = celula;
	celula = inserir(origem);
	celula->proxima = grafo->vertice[destino].lider;
	grafo->vertice[destino].lider = celula; 
}

void imprimir(vetor* grafo)
{
	for (int nome = 0; nome < grafo->rotulo; ++nome) {
		incidencia* impressor = grafo->vertice[nome].lider;
		printf("\nLista de adjacências do vértice %d\nLíder ", nome+1);
		
		while (impressor) {
			printf("-> %d", impressor->destino+1);
			impressor = impressor->proxima;
		}
		
		printf("\n");
	}

}
