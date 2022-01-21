/*
* Enya Luísa Gomes dos Santos
* 19.2.42.01
*/

#ifndef pessoa_h
#define pessoa_h

typedef struct pessoa Pessoa;

Pessoa *p_cria();

void p_setNome(Pessoa *, char *);

void p_setIdade(Pessoa *, int);

char *p_getNome(Pessoa *);

int p_getIdade(Pessoa *);

void p_libera(Pessoa **);

#endif
