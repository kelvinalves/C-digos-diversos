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
vetor* criar(int v);
void aresta(vetor* grafo, int origem, int destino);
void imprimir(vetor* grafo);

int main() {
  int quantidade = 5;
  vetor* grafo = criar(quantidade);
  aresta(grafo, 0, 1);
  aresta(grafo, 0, 4);
  aresta(grafo, 1, 2);
  aresta(grafo, 1, 3);
  aresta(grafo, 1, 4);
  aresta(grafo, 2, 3);
  aresta(grafo, 3, 4);
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
    printf("\n Lista de adjacências do vértice %d\n Líder ", nome); 
    while (impressor) { 
      printf("-> %d", impressor->destino); 
      impressor = impressor->proxima; 
    } 
    printf("\n"); 
  } 
}
