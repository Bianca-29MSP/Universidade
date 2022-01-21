#ifndef dados_h
#define dados_h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define QTD_DADOS 15

typedef struct
{
  int chave;
  long int dado1;
  char dado2[500];
  char dado3[3000];
} Dados;

int dados_getSizeof();

Dados *dados_cria_array(int n);

//Protótipos
void dados_setChave(Dados *d, int ch);
void dados_setDado1(Dados *d, long int dt);
void dados_setDado2(Dados *d, char *str);
void dados_setDado3(Dados *d, char *str);

int dados_getChave(Dados *d);
long int dados_getDado1(Dados *d);
char *dados_getDado2(Dados *d);
char *dados_getDado3(Dados *d);

#endif
