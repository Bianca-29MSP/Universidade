//
//  ponto.c
//  Ponto
//

#include "ponto.h"
#include <stdlib.h>
#include <stdio.h>

float raiz_quadrada(float numero);
float potenciacao(float base, int expoente);

struct ponto{
    float x, y;
};

Ponto* pto_cria(float x, float y){
    Ponto* aux = (Ponto*) malloc(sizeof(Ponto));
    if(aux==NULL)
    {
        printf("Memoria eh insuficiente");
        exit(1);
    }
    aux->x = x;
    aux->y = y;
    return aux;     
}

void pto_libera(Ponto* p){
    free(p);
}

void pto_acessa(Ponto* p, float *x, float* y) {
    *x = p->x;
    *y = p->y;
}

void pto_atribui(Ponto* p, float x, float y) {
    p->x = x;
    p->y = y;
}

float pto_distancia(Ponto* p1, Ponto *p2) {
    float ya = p1->y;
    float xa = p1->x;

    float xb = p2->x;
    float yb = p2->y;
    

    float calc1 = potenciacao((xb - xa), 2);
    float calc2 = potenciacao((yb - ya), 2);
    float calc = calc1 + calc2;
    float resultado = raiz_quadrada(calc);
    return resultado;

}

void pto_imprime(Ponto* p1) {
    float x = p1->x;
    float y = p1->y;
    printf("[%f, %f]\n", x, y);
}

float raiz_quadrada(float numero) {
    float a = numero, b=1;
    while ( (a-b) > 0 ) {
        a = (b+a)/2;
        b = numero / a;
    }
    return a;
}

float potenciacao(float base, int expoente) {
    int i = 0;
    int potencia = 1;
    while(i < expoente) {
        potencia *= base;
        i++;
    }
    
    return potencia;
}

