#include <stdio.h>

int main()
{
	int C1, C2, C3, C4;
	scanf("%d %d %d %d", &C1, &C2, &C3, &C4);

	if(C1 == 1)
		printf("1");
	else if(C2 == 1)
		printf("2");
	else if(C3 == 1)
		printf("3");
	else
		printf("4");

	return 0;
}