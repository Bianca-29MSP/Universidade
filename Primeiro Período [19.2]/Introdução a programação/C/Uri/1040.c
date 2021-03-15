#include <stdio.h>

int main()
{
	double n1, n2, n3, n4, media;

	scanf("%lf %lf %lf %lf", &n1, &n2, &n3, &n4);

	media = ((n1 * 2) + (n2 * 3) + (n3 * 4) + n4) / 10; 

	printf("Media: %.1lf\n", media);

	if(media >= 7)
		printf("Aluno aprovado.\n");

	else if(media < 5)
		printf("Aluno reprovado.\n");

	else if(media >= 5 && media <= 6.9)
	{
		printf("Aluno em exame.\n");
		double notaExame;
		scanf("%lf", &notaExame);
		printf("Nota do exame: %.1lf\n", notaExame);
		double mediaNova = (media + notaExame) / 2;
		if(mediaNova >= 5)
			printf("Aluno aprovado.\n");
		else
			printf("Aluno reprovado.\n");
		printf("Media final: %.1lf\n", mediaNova);
	}
		
	return 0;
}