//
//  circulo.h
//  Circulo
//

#ifndef circulo_h
#define circulo_h

#include <stdio.h>
#include <stdlib.h>

#include "ponto.h"

#define PI 3.14159

typedef struct circulo Circulo;

Circulo *circ_cria(Ponto *centro, float raio);
Circulo *circ_cria_ptn(float x, float y, float raio);
void circ_libera(Circulo **circ);
float circ_area(Circulo *circ);
int circ_interior(Circulo *circ, Ponto *pt);
void circ_imprime(Circulo *circ, Ponto *centro);
void circ_imprime_detalhes_distancia(Circulo *circ, Ponto *centro, Ponto *pt, int distancia);

#endif
