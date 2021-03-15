#include <stdio.h>

int main()
{
	int A1, A2, A3;

	scanf("%d %d %d", &A1, &A2, &A3);

	int caso1 = (A2 * 2) + (A3 * 4);
	
	int caso2 = (A1 * 2) + (A3 * 2);

	int caso3 = (A1* 4) + (A2 * 2);

	if (caso2 == 0 && caso1 == caso3)
		printf("%d\n", caso1);	

	else if (caso1 < caso2 && caso1 < caso3)
		printf("%d\n", caso1);

	else if (caso2 <= caso1 && caso2 < caso3)
		printf("%d\n", caso2);

	else if (caso3 <= caso1 && caso3 < caso2)
		printf("%d\n", caso3);

	else if (caso2 == caso3 && caso2 < caso1)
		printf("%d\n", caso2);

		
	return 0;
}