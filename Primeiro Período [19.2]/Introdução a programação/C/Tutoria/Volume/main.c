#include <stdio.h>
#include "calculaVolume.h"

int main()
{
	//Esfera
	printf("ESFERA: \n");
	double raio, volumeE;
	printf("Digite o raio: ");
	scanf("%lf", &raio);
	volumeEsfera(&volumeE, raio);

	//Tronco
	printf("TRONCO DA PIRAMIDE: \n");
	double altura, AB, Ab, volumeT;
	printf("Digite a altura do tronco: ");
	scanf("%lf", &altura);
	printf("Digite a area de base maior: ");
	scanf("%lf", &AB);
	printf("Digite a area de base menor: ");
	scanf("%lf", &Ab);
	volumeTronco(&volumeT, altura, AB, Ab);

	//CONE
	printf("CONE: \n");
	double volumeC, raioC, alturaC;
	printf("Digite o raio: ");
	scanf("%lf", &raioC);
	printf("Digite a altura do Cone: ");
	scanf("%lf", &alturaC);
	volumeCone(&volumeC, raioC, alturaC);

	printf("Volume da esfera: %.2lf\n", volumeE);
	printf("Volume do tronco da piramide: %.2lf\n", volumeT);
	printf("Volume do cone: %.2lf\n", volumeC);
	return 0;
}