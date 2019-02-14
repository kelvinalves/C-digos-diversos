#include <stdio.h>
#include <stdlib.h>

int*comprimento(int*tamanho);
void valores(int*vetor,int tamanho);
int quantidade(int*vetor,int tamanho);

int main(){
  int tamanho=0,*vetor;
  vetor=comprimento(&tamanho);
  if(vetor==NULL){
    printf("Memória insuficiente!\n");
    exit(1);
 	}
  valores(vetor,tamanho);
  printf("Há %d potências de 2\n",quantidade(vetor,tamanho));
  free(vetor);
  return 0;
}

int*comprimento(int*tamanho){
  printf("Informe o tamanho do vetor: ");
  scanf("%d",tamanho);
  return malloc(*tamanho*sizeof(int));
}
void valores(int*vetor,int tamanho){
  int valor=0;
  for(int indice=0;indice<tamanho;indice++){
    printf("Informe o %d° valor: ",indice+1);
    scanf("%d",&valor);
    vetor[indice]=valor;
  }
}
int quantidade(int*vetor,int tamanho){
  int contador=0,potencia=2;
  for(int indice=0;indice<tamanho;indice++){
    while(potencia<vetor[indice])
      potencia*=2;
    if(potencia==vetor[indice])
      contador++;
    potencia=2;
  }
  return contador;
}
