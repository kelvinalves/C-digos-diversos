#include <stdio.h>
#include <math.h>

float disc(float a, float b, float c)
{
  	float delta;
  
  	delta = b * b -4 * a * c;
  
  	printf("delta = %.2f\n", delta);
  
  	return delta;
}

void raiz(float a, float b)
{
  	float x;
  
  	x = -b / (2 * a);
  
  	printf("x = %.2f\n", x);
}

void raizes(float a, float b, float delta)
{
  	float x1, x2;
  
  	x1 = (-b + sqrt(delta))/ (2 * a);
  	x2 = (-b - sqrt(delta))/ (2 * a);
  
  	printf("x' = %.2f\nx''= %.2f\n", x1, x2);
}

void raizesComp(float a, float b, float delta)
{
  	float real, comp1, comp2;
  
  	comp1 = sqrt(-delta)/ (2 * a);
  	comp2 = -sqrt(-delta)/ (2 * a);
  	real = -b / (2 * a);
  
  	printf("x' = %.2fr  %.2fi\nx''= %.2fr %.2fi\n", real, comp1, real, comp2);
}

int main ()
{
  	float a, b, c, delta;
  
  	printf("Informe os coeficientes da função: ");
	scanf("%f %f %f", &a, &b, &c);
	
	delta = disc(a, b, c);
	
	if (delta == 0) {
    		raiz(a, b);
  	}
  	else if (delta > 0) {
    		raizes(a, b, delta);
  	}
  	else {
    		raizesComp (a, b, delta);
  	}	
	return 0;
}
