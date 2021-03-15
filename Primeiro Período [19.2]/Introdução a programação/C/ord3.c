#include <stdio.h>

void ord3(int *a, int *b, int *c);

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	ord3(&a, &b, &c);

	printf("%d %d %d\n", a, b, c);
	return 0;
}

void ord3(int *a, int *b, int *c)
{
	int temp1, temp2;
	if(*c < *a  &&  *c < *b){
		temp1 = *a;
		*a = *c;
		if(temp1 > *c  &&  temp1 < *b){
			temp2 = *b;
			*b = temp1;
			*c = temp2;
		}else{
			*c = temp1;
		}
	}
	else if(*b < *a  &&  *b < *c){
		temp1 = *a;
		*a = *b;
		if(temp1 > *b  &&  temp1 < *c){
			temp2 = *b;
			*b = temp1;
			*c = temp2;
		}else{
			*c = temp1;
		}
	}
	else{
		if(*c > *a && *c < *b){
			temp1 = *b;
			*b = *c;
			*c = temp1;
		}else{
			*a = *a;
			*b = *b;
			*c = *c;
		}
	}
}
