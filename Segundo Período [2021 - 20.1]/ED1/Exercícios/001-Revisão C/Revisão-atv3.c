//Ponto & Circunferencia
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct ponto Ponto;
typedef struct circulo Circulo;

struct ponto {
    int x;
    int y;
};

struct circulo {
    Ponto centro;
    int raio;
};

bool circ_interior(Circulo* c, Ponto* p);

int main() {
    Circulo circ;
    Ponto p;
    bool p_interior;
    
    printf("Informações sobre o círculo:\n");
    scanf("%d %d", &circ.centro.x, &circ.centro.y);
    scanf("%d", &circ.raio);
    
    printf("Informações sobre o ponto à verificar:\n");
    scanf("%d %d", &p.x, &p.y);
    
    p_interior = circ_interior(&circ, &p);
    if(p_interior)
        printf("Ponto interno à circunferência, ou pertence à circunferência.\n");
    else
        printf("Ponto externo à circunferência.\n");
    
    return 0;
}

bool circ_interior(Circulo* c, Ponto* p) {
    //(Cx – Px)^2 + (Cy – Py)^2 = Raio^2
    int a = c->centro.x - p->x;
    int b = c->centro.y - p->y;
    printf("%d %d", a, b);
    int k = pow(a, 2) + pow(b, 2);
    int r = pow(c->raio, 2);
    if(k < r || k == r)
        return true;
    else if(k > r)
        return false;
}