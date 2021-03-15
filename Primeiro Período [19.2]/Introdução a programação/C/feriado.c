#include <stdio.h>

int main()
{
	int A, B, C, D, E, F, G, H, I, K, L, M, mes, dia;
	int ano = 2018;
	A = ano % 19;
	B = ano / 100;
	C = ano % 100;
	D = B / 4;
	E = B % 4;
	F = (B + 8) / 25;
	G = (B - F + 1) / 3;
	H = (19 * A + B - D - G + 15) % 30;
	I = C / 4;
	K = C % 4;
	L = (32 + 2 * E + 2 * I - H - K) % 7;
	M = (A + 11 * H + 22 * L) / 451;
	mes = (H + L - 7 * M + 144) / 31 - 1;
	dia = (H + L - 7 * M + 144) % 31 + 2;

	if(dia > 31){
		mes++;
		dia = dia - 31;
	}

	printf("%d / %d\n", dia, mes);

	int diaf, mesf, diac, mesc;
	if (dia - 2 > 31){
		diaf = dia - 31;
		mesf = mes - 2;
	}
	else if(dia - 2 < 0){
		diaf = 2 - dia;
		mesf =  mes - 1;
	}
	else {
		diaf = dia - 2;
		mesf = mes;
	}
	//21
	// 20 / 06
	if(dia + 60 > 30){
		diac = 81 % 30 - 1;
		mesc = mes + (81 / 30);
	}

	

	printf("%d / %d\n", diaf, mesf);  

	printf("%d / %d\n", diac, mesc); 
	return 0;
}