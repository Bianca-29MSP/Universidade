//
//  principal.c
//  Ponto
//
//

#include <stdio.h>
#include "ponto.h"

int main(){

    float x = 1.0;
    float y = 2.0;

    float x_recebe;
    float y_recebe;
    
    Ponto* p1 = pto_cria(2.0,4.0);

    pto_imprime(p1);

    pto_acessa(p1, &x_recebe, &y_recebe);

    printf("[%f, %f]\n", x_recebe, y_recebe);

    pto_atribui(p1, x, y);

    pto_imprime(p1);

    pto_libera(p1);

    Ponto* p2 = pto_cria(-2.0,4.0);
    Ponto* p3 = pto_cria(2.0,2.0);

    float distancia_entre_dois_ptos = pto_distancia(p2, p3);

    printf("%f\n", distancia_entre_dois_ptos);


    //ERRO Ponto* p2 = (Ponto*) malloc(sizeof(Ponto));
    //ERRO   Ponto p2;
    
    return 0;
}
