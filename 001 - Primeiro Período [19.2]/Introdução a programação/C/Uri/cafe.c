#include <stdio.h>

int main()
{
	int A1, A2, A3, resultado;

	scanf("%d %d %d", &A1, &A2, &A3);

	
	if (A1 > A2 && A1 > A3)
		resultado = (A2 * 2) + (A3 * 4);

	else if (A2 >= A1 && A2 > A3)
		resultado = (A1 * 2) + (A3 * 2);

	else if (A3 >= A1 && A3 > A2) 
		resultado = (A1 * 4) + (A2 * 2);

	else if(A1 == A3 && A1 > A2)
		resultado = (A2 * 2) + (A3 * 4);
	
	printf("%d\n", resultado);

	return 0;
}