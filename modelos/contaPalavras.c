#include <stdio.h>
#include <stdlib.h>

int main(){
  int quantidade=1;
  char *frase;
  printf("Escreva uma frase: ");
  /*Aceita todos os caracteres com exceção enter*/
  scanf("%[^\n]", frase);
  /*limpa buffer*/
  scanf("%*[^\n]");
  /*retoma a aquisição de caracteres*/ 
  scanf("%*c");
  while (*frase != '\0') {
    if ((*frase==' ')||(*frase=='\t')||(*frase=='\r')||(*frase=='\n'))
      quantidade++;
    frase++;
  }
  printf("Há %d palavras.", quantidade);
  return 0;
}
/*'\0' -> Fim da string
  ' ' -> Espaço
  '\t' -> Tabulação
  '\n' -> enter, quebra de linha
  '\r' -> Início de linha*/
