#include <stdio.h>
#include <stdlib.h>

int main ()
{
  int i, j;
  int m[3][3];
  
  printf("Informe a matriz\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("Informe o elemento %i%i da matriz: ", i+1, j+1);
      scanf("%i", &m[i][j]);
    }
  }
  printf("Transposta\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("m[%i][%i] = %i\n", i+1, j+1, m[j][i]);
    }
  }
  return 0;
}
