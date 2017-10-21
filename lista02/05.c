#include <stdio.h>

int fatorial(int n)
{
    	int fat = 1;
    
    	while (n>1) {
        	fat *= n;
        	--n;
    	}
    	return fat;
}

int binomial(int n, int k)
{
    	int binomial;
    
    	binomial = fatorial(n)/(fatorial(k)*fatorial(n-k));
    
    	return binomial;
}

int main ()
{
  	int n, k;

  	printf("Informe n e k: ");
  	scanf("%i %i", &n, &k);
  	printf("%i\n", binomial(n, k));
  
	return 0;
}
