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

int main() {
  int quantidade, origem = 1, destino = 1;
  printf("Informe o número de vértices: ");
  scanf("%d", &quantidade);
  vetor* grafo = criar(quantidade);
  while(origem > 0 && destino > 0) {
    printf("Informe os vértices de origem e destino: ");
    scanf("%d %d", &origem, &destino);
    if(origem <= quantidade && destino <= quantidade)
      aresta(grafo, origem-1, destino-1);
    else
      printf("Informe valores válidos\n");
  }
  imprimir(grafo);
  return 0; 
}

incidencia* inserir(int destino) { 
  incidencia* vertice = (incidencia*)malloc(sizeof(incidencia));
  vertice->destino = destino; 
  vertice->proxima = NULL; 
  return vertice;
}
  
vetor* criar(int nome) {
  vetor* grafo = (vetor*)malloc(sizeof(vetor));
  grafo->rotulo = nome;
  grafo->vertice = (lista*)malloc(nome*sizeof(lista));
  for (int i = 0; i < nome; ++i)
    grafo->vertice[i].lider = NULL; 
  return grafo; 
}

void aresta(vetor* grafo, int origem, int destino) {
  incidencia* celula = inserir(destino); 
  celula->proxima = grafo->vertice[origem].lider; 
  grafo->vertice[origem].lider = celula;
  celula = inserir(origem); 
  celula->proxima = grafo->vertice[destino].lider; 
  grafo->vertice[destino].lider = celula; 
}

void imprimir(vetor* grafo) {
  for (int nome = 0; nome < grafo->rotulo; ++nome) { 
    incidencia* impressor = grafo->vertice[nome].lider; 
    printf("\n Lista de adjacências do vértice %d\n Líder ", nome+1); 
    while (impressor) { 
      printf("-> %d", impressor->destino+1); 
      impressor = impressor->proxima; 
    } 
    printf("\n"); 
  } 
}
