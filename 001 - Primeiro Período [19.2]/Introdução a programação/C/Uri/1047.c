#include <stdio.h>

int main()
{
	int horaI, minutoI, horaT, minutoT, totalM, totalH;
	
	scanf("%d %d %d %d", &horaI, &minutoI, &horaT, &minutoT);
	
    totalM = minutoT - minutoI;
	totalH = horaT - horaI;
	
	if(totalH < 0)
		if(totalM < 0)
			totalH = (horaT + (24 - horaI)) - 1;
		else
			totalH = horaT + (24 - horaI);

	else if (totalH == 0)
			if(totalM == 0)
				totalH = 24;
			else if(totalM < 0)
				totalH = (1440 - (minutoI + minutoT)) / 60;
			else
				totalH = 0;

	else if(totalH == 1)
		totalH = 0;

	else
		if(totalM < 0)
			totalH = totalH - 1;
		else
			totalH = totalH;


	if(totalM < 0)
		totalM = totalM + 60;

	else if (totalM == 0)
		if(totalH == 24)
			totalM = 0;
		else if(totalH < 0)
			totalM = (minutoT - minutoI) + 60;
		else
			totalM = 0;

	else if (totalM > 0)
		totalM = totalM;

	printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", totalH, totalM);

	return 0;
}




