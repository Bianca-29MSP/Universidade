/*
* arvore_expressao.h
* Trabalho pratico 2 de EDI (BCC202) - Árvore de expressão   
* Enya Luísa Gomes dos Santos - 19.2.4201                          17/04/2021            
*/
#include "pilha.h"
#include "pilha_arvore.h"
#include "arvore.h"

/*
*FUNÇÃO: calculaArvExpressao
*OBJETIVO: Realizar a montagem e o cáculo de uma árvore binaria de expressão -
            com chamadas de outras funções - e retornar a saída.
*IN: String da expressão, opção escolhida no main para o tipo da saída;                        
*OUT: valot float que o resultado do cálculo da expressão.
*/
float calculaArvExpressao(char *, int);

/*
*FUNÇÃO: geraArvoreExpressao
*OBJETIVO: Realizar a montagem da árvore binária completa que será calculada.
*IN: String da expressão.                  
*OUT: Árvore binária completa já montada.
*/
ArvoreNo *geraArvoreExpressao(char *);

/*
*FUNÇÃO: geraSubarvoreExpressao
*OBJETIVO: Realizar a montagem de umas das subárvores, ou galhos, da árvore
          principal por meio de uma parte da expressão, a parte esquerda ou
          a parte a direita.
*IN: String da expressão, inicio da expressão, fim da expressão e ponteiro de int
    para a posição atual da string a ser analidada(essa usada necessariamente para 
    quando houver parenteses na expressão).                        
*OUT: Árvore binária, sendo um dos ramos da raiz, esquerda ou direita.
*/
ArvoreNo *geraSubarvoreExpressao(char *, int, int, int *);

/*
*FUNÇÃO: buscaOperadorPrincipal
*OBJETIVO: Encontrar o operador da ultima operação, aquele q será a raiz da árvore.
*IN: String da expressão, inicio da string e fim da string.                  
*OUT: Posição do operador na string
*/
int buscaOperadorPrincipal(char *, int, int);

/*
*FUNÇÃO: calculadoraArvore
*OBJETIVO: Iniciar a pilha que cálcula a expressão de forma pós-fixada e chamar a 
          função arvorePosOrdem(ArvoreNo *, Pilha *) a fim de calcular a árvore
          de expressão, além disso retorna o resultado desse calculo.
*IN: Referencia de uma árvore binaria.                  
*OUT: Valor float, sendo esse o resultado da expressão.
*/
float calculadoraArvore(ArvoreNo **);

/*
*FUNÇÃO: trataString
*OBJETIVO: Retirar todos os espaços da string, caso tenha.
*IN: String da expressão, tamanho da string.                  
*OUT: void
*/
void trataString(char *, int);

/*
*FUNÇÃO: contemEspaco
*OBJETIVO: Verificar ser a string possui espaço.
*IN: String da expressão, tamanho da string.                  
*OUT: void
*/
int contemEspaco(char *, int);

/*
*FUNÇÃO: ehOperador
*OBJETIVO: Verificar ser a o caracter se trata de um operador.
*IN: Charater a ser analisado.                  
*OUT: int, sendo 1 para verdadeiro e 0 para falso.
*/
int ehOperador(char);

/*
*FUNÇÃO: ehOperando
*OBJETIVO: Verificar ser a o caracter se trata de um operando.
*IN: Charater a ser analisado.                  
*OUT: int, sendo 1 para verdadeiro e 0 para falso.
*/
int ehOperando(char);