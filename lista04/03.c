#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

#pragma pack(1)

int main (int argc, char **argv)
{
	char url[] = "arquivo media_alunos.txt";
	FILE *arq_in, *arq_out;
	aluno aluno;

	if (argc < 2) {
		printf("%s\n", argv[0]);

		return -1;
	}

	arq_in = fopen(argv[1], "r");
	arq_out = fopen(url, "w");

	if (arq_in == NULL)
		printf("Erro, nao foi possivel abrir o arquivo\n");
	else
		while ((fscanf(arq_in, "\%s \%d \%f \%f %f", aluno.nome, &aluno.ra, &aluno.p1, &aluno.p2, &aluno.p3)) != EOF)
			fprintf(arq_out, "%s teve media %.2f\n", aluno.nome, (aluno.p1 + aluno.p2 + aluno.p3)/3);

	fclose(arq_in);
	fclose(arq_out);

	return 0;
}
