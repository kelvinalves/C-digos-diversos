#include <stdio.h>

float volume(float altura, float comprimento, float largura)
{
	float volume; 
	volume = altura*comprimento*largura;
    	return volume;
}


int main ()
{
	float altura, comprimento, largura;

	printf("Informe altura, comprimento e largura: ");
    	scanf("%f %f %f", &altura, &comprimento, &largura);
	printf("%.2f\n", volume(altura, comprimento, largura));

    	return 0;
}
