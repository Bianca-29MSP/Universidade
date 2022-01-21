#ifndef carro_h
#define carro_h
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct carro Carro;

Carro **car_create_array(int n);

Carro *car_create(char *modelo, char *car, int ano, float preco, float quilometragem_rodada);

void car_destroy(Carro **carro);

void car_update(Carro **carro, Carro *attz_carro, char *modelo, char *cor, int ano, int n);

int buscar_carro(Carro **carro, char *modelo, char *cor, int ano, int n);

void mostrar_carro_especifico(Carro **carro, char *modelo, char *cor, int ano, int n);

int car_delete(Carro **carro, char *modelo, char *cor, int ano, int n);

void get_carros(Carro **carro, int n);

#endif
