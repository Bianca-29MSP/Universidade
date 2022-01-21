//
//  ponto.h
//  Ponto
//

#ifndef ponto_h
#define ponto_h

#include <stdio.h>

typedef struct ponto Ponto;

Ponto* pto_cria(float x, float y);
void pto_libera(Ponto** p);
void pto_acessa(Ponto* p, float *x, float* y);
void pto_atribui(Ponto* p, float x, float y);
float pto_distancia(Ponto* p1, Ponto *p2);
void pto_imprime(Ponto* p1);

#endif /* ponto_h */
