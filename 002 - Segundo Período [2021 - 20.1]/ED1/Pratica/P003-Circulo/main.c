//
//  main.c
//  Circulo & Ponto
//

#include <stdio.h>
#include "circulo.h"

int main()
{

    // * Ponto *
    /*
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
    
    pto_libera(p2);
    pto_libera(p3);
    */

    /* Circulo */
    float raio = 5.0;
    Ponto *centro = pto_cria(2.0, 3.0);
    Circulo *circ = circ_cria(centro, raio);

    Ponto *pt = pto_cria(3.0, 4.0);

    Circulo *circ2 = circ_cria_ptn(5.0, 3.0, 3.0);

    int distancia = circ_interior(circ, pt);

    circ_imprime_detalhes_distancia(circ, centro, pt, distancia);

    printf("Área: %.2f\n", circ_area(circ));

    circ_libera(&circ);
    circ_libera(&circ2);

    pto_libera(&pt);

    //printf("%p %p %p %p\n", circ, circ2, pt, circ);

    return 0;
}
