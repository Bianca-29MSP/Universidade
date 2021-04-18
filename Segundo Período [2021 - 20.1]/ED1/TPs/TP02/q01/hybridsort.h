/*
* hybridsort.h
* Trabalho pratico 2 de EDI (BCC202) - Quicksort combinado com insertionsort   
* Enya Luísa Gomes dos Santos - 19.2.4201                          17/04/2021            
*/

/*
*ESTRUTURA CAMPO
*OBJETIVO: Estrutura responsavel por armazenar as contagens de movimentações e
*          comprações do insertionsort e do quicksort
*/
typedef struct
{
  int movInsertion;
  int compInsertion;
  int movQuick;
  int compQuick;
} Contador;

typedef int Item;

/*
*FUNÇÃO: hybridsortInicia
*OBJETIVO: Iniciar o algoritiro híbrido com quicksort e insertionsort.
*IN: Vetor de inteiros, tamanho do vetor, ponteiro para estrutura Contador e 
    inteiro com a opção do pivô.                         
*OUT: void
*/
void hybridsortInicia(Item *v, int n, Contador *count, int op);

/*
*FUNÇÃO: hybridsort
*OBJETIVO: Ordenar um vetor de forma híbrido com quicksort e insertionsort.
*IN: Vetor de inteiros, inicio do vetor, fim do vetor e inteiro com a opção
          do pivô.                         
*OUT: void
*/
void hybridsort(Item *v, int l, int r, int op);

/*
*FUNÇÃO: partition
*OBJETIVO: Particionar o vetor para ordena-lo, seguindo a lógica do algoritmo de
          ordenação quicksort.
*IN: Vetor de inteiros, inicio do vetor, fim do vetor e inteiro com a opção
    do pivô.                       
*OUT: void
*/
int partition(Item *v, int l, int r, int op);

/*
*FUNÇÃO: pivoMedianaDeTres
*OBJETIVO: Escolher o pivô do quicksort por meio da mediana entre o primeiro
          elemento do array, o do meio e o último. 
*IN: Vetor de inteiros, inicio do vetor, fim do vetor.                         
*OUT: void
*/
void pivoMedianaDeTres(Item *v, int l, int r);

/*
*FUNÇÃO: insertionsort
*OBJETIVO: Ordenar um vetor usando a lógica do algoritmo de ordenação
          insertionsort.
*IN: Vetor de inteiros, inicio do vetor, fim do vetor.                         
*OUT: void
*/
void insertionsort(Item *arr, int l, int r);