#include<stdio.h>
#include<stdlib.h>

int*vetor(int*tamanho){
  printf("Informe o tamanho do vetor: ");
  scanf("%d",tamanho);
  return malloc(*tamanho*sizeof(int));
}

void imprime(int tamanho, int*lista){
  for(int indice=0;indice<tamanho;indice++)
    printf("%d",lista[indice]);
}
void insere(int tamanho, int*lista){
  int valor=0;
  for(int indice=tamanho-1;indice>0;indice--)
    lista[indice]=lista[indice-1];
  printf("Informe o valor: ");
  scanf("%d",&valor);
  lista[0]=valor;
}
void remover(int tamanho, int*lista){
  for(int indice=0;indice<tamanho-1;indice++)
    lista[indice]=lista[indice+1];
  lista[tamanho-1]=0;
}
int main(){
  int tamanho,*lista,valor;
  lista=vetor(&tamanho);
  for(int indice=0;indice<tamanho;indice++){
    printf("informe o %dº valor: ",indice+1);
    scanf("%d",&valor);
    lista[indice]=valor;
  }
  imprime(tamanho,lista);
  insere(tamanho,lista);
  imprime(tamanho,lista);
  remover(tamanho,lista);
  imprime(tamanho,lista);
  free(lista);
  return 0;
}
