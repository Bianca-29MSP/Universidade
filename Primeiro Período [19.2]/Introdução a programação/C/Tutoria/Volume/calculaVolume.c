// v = (4.0/3.0) * pi * r^3
//v = h/3.0 * (AB + sqrt(AB*Ab+Ab))
// v = pi r2 h / 3

#include <math.h>
#include "calculaVolume.h"

void volumeEsfera(double *volumeE, double raio)
{
	*volumeE = (4.0/3.0) * 3.14159 * pow(raio,3);
}

void volumeTronco(double *volumeT,  double altura, double AB, double Ab)
{
	*volumeT = (altura / 3.0) * (AB + sqrt(AB * Ab) + Ab);
}

void volumeCone(double *volumeC, double raio, double altura)
{
	*volumeC = (3.14159 * pow(raio,2) * altura) / 3;
}