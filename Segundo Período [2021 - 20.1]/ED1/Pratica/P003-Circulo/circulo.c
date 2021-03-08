//
//  circulo.c
//  Circulo
//

#include "circulo.h"

struct circulo
{
    Ponto *centro;
    float raio;
};

Circulo *circ_cria(Ponto *centro, float raio)
{
    Circulo *circ = (Circulo *)malloc(sizeof(Circulo));
    if (circ == NULL)
    {
        printf("Memória insuficiente!\n");
        exit(1);
    }

    circ->centro = centro;
    circ->raio = raio;

    return circ;
}

Circulo *circ_cria_ptn(float x, float y, float raio)
{
    Circulo *circ = (Circulo *)malloc(sizeof(Circulo));
    if (circ == NULL)
    {
        printf("Memória insuficiente!\n");
        exit(1);
    }
    Ponto *ponto = pto_cria(x, y);

    circ->centro = ponto;
    circ->raio = raio;

    return circ;
}

void circ_libera(Circulo **circ)
{
    pto_libera(&(**circ).centro);

    free(*circ);
    *circ = NULL;
}

float circ_area(Circulo *circ)
{
    float raio = circ->raio;
    return PI * (raio * raio);
}

int circ_interior(Circulo *circ, Ponto *pt)
{
    float distancia = pto_distancia(circ->centro, pt);
    return (distancia < (circ->raio));
}

void circ_imprime(Circulo *circ, Ponto *centro)
{
    printf("C: ");
    pto_imprime(centro);
    printf("R: ");
    printf("%.2f\n", circ->raio);
}

void circ_imprime_detalhes_distancia(Circulo *circ, Ponto *centro, Ponto *pt, int distancia)
{
    printf("P: ");
    pto_imprime(pt);
    circ_imprime(circ, centro);

    if (distancia)
        printf("Interno\n");
    else
        printf("Externo\n");
}
