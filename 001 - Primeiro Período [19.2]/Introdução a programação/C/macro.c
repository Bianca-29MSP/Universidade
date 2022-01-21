#include <stdio.h>

#define TROCA(a, b, temp) (temp = a, a = b, b = temp)

int main()
{
	int a, b, temp;
	scanf("%d %d", &a, &b);

	printf("A = %d, B = %d\n", a, b);

	TROCA(a, b, temp);

	printf("A = %d, B = %d\n", a, b);

	return 0;
}