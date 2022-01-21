#include <stdio.h>
#include <math.h>

int main()
{
    double raio, area;

    const double pi = 3.14159;

    scanf("%lf", &raio);

    area = pi * pow(raio, 2);

    printf("A=%.4lf \n", area);

    return 0;
}
