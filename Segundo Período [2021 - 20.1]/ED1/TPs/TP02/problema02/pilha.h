/*
* pilha.h
* Trabalho pratico 2 de EDI (BCC202) - Árvore de expressão   
* Enya Luísa Gomes dos Santos - 19.2.4201                          17/04/2021            
*/
typedef struct pilha Pilha;

typedef float Item;

/*
* PILHA DINÂMICA
* Funções básicas de uma estrutura de pilha de float
*/
Pilha *pilhaInicia();

int pilhaEhVazia(Pilha *);

int pilhaPush(Pilha *, Item);

Item pilhaPop(Pilha *);

int pilhaTamanho(Pilha *);

void pilhaUnstack(Pilha **);

/*
*FUNÇÃO: calculadoraPosOrdem
*OBJETIVO: Realizar os calculos da pilha com a expressão pós fixada.
*IN: Ponteiro de pilha, caracter de um operador para realizar a operação.                      
*OUT: float
*/
float calculadoraPosOrdem(Pilha *, char);

/*
*FUNÇÃO: constroiPilhaPosFixada
*OBJETIVO: Receber um caracter, e a partir dele montar uma pilha com o resultado
          da expressão pós-fixada.
*IN: Ponteiro de pilha, caracter disposto na árvore.                        
*OUT: void
*/
void constroiPilhaPosFixada(Pilha *, char);
