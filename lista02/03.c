#include <stdio.h>
#include <math.h>

double gau_leg(int iter)
{
  	double pi, a1, a = 1, b = 1 / sqrt(2), t = 0.25, p = 1;
  
  	for (int i = 0; i < iter; i++) {
    		a1 = (a + b) / 2;
    		b = sqrt(a * b);
    		t = t - p * pow((a - a1), 2);
    		p *= 2;
    		a = a1;
  	}
  	pi = pow((a + b), 2) / (4 * t);

  	return pi;
}

int main ()
{
  	int iter;

  	printf("Informe o número de iterações: ");
  	scanf("%i", &iter);
  	printf("%.20lf\n", gau_leg(iter));
  
	return 0;
}
