#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "intercalacao2f.h"

enum _tape
{
  Entrada,
  Saida
};

typedef enum _tape Tape;

const char *intercalacaoBalanceadaVariosCaminhos2f(char *filename, int n, Analise *analisePrimeiraFase, Analise *analiseSegundaFase)
{
  TipoHeap heap;
  heap_constroiHeap(&heap, N);

  const char *filesIn[10] = {
      "fitas/2f/in/fita01.txt",
      "fitas/2f/in/fita02.txt",
      "fitas/2f/in/fita03.txt",
      "fitas/2f/in/fita04.txt",
      "fitas/2f/in/fita05.txt",
      "fitas/2f/in/fita06.txt",
      "fitas/2f/in/fita07.txt",
      "fitas/2f/in/fita08.txt",
      "fitas/2f/in/fita09.txt",
      "fitas/2f/in/fita10.txt",
  };

  const char *filesOut[10] = {
      "fitas/2f/out/fita11.txt",
      "fitas/2f/out/fita12.txt",
      "fitas/2f/out/fita13.txt",
      "fitas/2f/out/fita14.txt",
      "fitas/2f/out/fita15.txt",
      "fitas/2f/out/fita16.txt",
      "fitas/2f/out/fita17.txt",
      "fitas/2f/out/fita18.txt",
      "fitas/2f/out/fita19.txt",
      "fitas/2f/out/fita20.txt",
  };

  FILE *arq;

  //cria as fitas limpas de entrada
  for (int i = 0; i < N; i++)
  {
    arq = fopen(filesIn[i], "wt");
    fclose(arq);
  }

  //cria as fitas limpas de saída
  for (int i = 0; i < N; i++)
  {
    arq = fopen(filesOut[i], "wt");
    fclose(arq);
  }

  // cada posição do array representa quantos blocos cada fita têm
  int nBlocos[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  // recebe a soma da quantidade total de blocos
  int nBlocosSum = 0;

  //Fase 1
  iniciaAnalise(analisePrimeiraFase);
  iniciaContagemTempo(analisePrimeiraFase);

  //gera os primeiros blocos ordenados
  geracaoBlocosOrdenados(filename, &heap, filesIn, nBlocos, n, analisePrimeiraFase);

  finalizaContagemTempo(analisePrimeiraFase);
  updateTempo(analisePrimeiraFase);

  //soma as blocos em cada fita para obter o total de blocos e zera o array nBlocos
  for (int i = 0; i < N; i++)
  {
    nBlocosSum += nBlocos[i];
    nBlocos[i] = 0;
  }

  FILE *arqs[10];
  int whitchFita = 0;
  Tape intercala = Entrada;

  //Fase 2
  iniciaAnalise(analiseSegundaFase);
  iniciaContagemTempo(analiseSegundaFase);
  while (nBlocosSum > 1)
  {
    nBlocosSum = 0;
    if (intercala == Entrada)
    { //ler da entrada e escrever na saída
      for (int i = 0; i < N; i++)
      { //limpando filesOut
        arq = fopen(filesOut[i], "wt");
        fclose(arq);
      }

      //abre todos de entrada os arquivos para a leitura
      for (int i = 0; i < N; i++)
        arqs[i] = fopen(filesIn[i], "r");

      whitchFita = 0;

      intercalacao(&heap, arqs, filesOut, nBlocos, &whitchFita, analiseSegundaFase);

      intercala = Saida;
    }
    else if (intercala == Saida)
    { //ler da saída e escrever na entrada
      for (int i = 0; i < N; i++)
      { //limpando filesIn
        arq = fopen(filesIn[i], "wt");
        fclose(arq);
      }

      //abre todos de saída os arquivos para a leitura
      for (int i = 0; i < N; i++)
        arqs[i] = fopen(filesOut[i], "r");

      whitchFita = 0;

      intercalacao(&heap, arqs, filesIn, nBlocos, &whitchFita, analiseSegundaFase);

      intercala = Entrada;
    }

    //fecha todos os arquivos abertos
    for (int i = 0; i < N; i++)
      fclose(arqs[i]);

    //soma as blocos em cada fita para obter o total de blocos e zera o array nBlocos
    for (int i = 0; i < N; i++)
    {
      nBlocosSum += nBlocos[i];
      nBlocos[i] = 0;
    }
  }
  finalizaContagemTempo(analiseSegundaFase);
  updateTempo(analiseSegundaFase);

  if (intercala == Entrada)
  { //ler da entrada e escrever na saída
    for (int i = 0; i < N; i++)
    { //limpando filesOut
      arq = fopen(filesOut[i], "wt");
      fclose(arq);
    }
  }

  //libera a memoria da heap
  heap_destroyHeap(&heap);

  //retorna o nome da fita em que o arquivo ordenado está salvo
  if (intercala == Entrada)
    return filesIn[whitchFita - 1];
  else
    return filesOut[whitchFita - 1];
}

void geracaoBlocosOrdenados(char *filename, TipoHeap *heap, const char *filesIn[], int nBlocos[], int n, Analise *analise)
{
  TipoDado dado;
  int indexFita = 0;
  FILE *in = fopen(filename, "r");
  if (in == NULL)
  {
    printf("Erro na ebertura do arquivo de entrada!\n");
    exit(1);
  }

  while (n > 0 && fscanf(in, "%s %lf %2[A-Z] %49[A-Z Ã Â À Á Õ Ó Ô Ç Ì Ê É ' -] %29[A-Z Ã Â À Á Õ Ó Ô Ç Ì Ê É ' -]\n", dado.inscricao, &dado.nota, dado.estado, dado.cidade, dado.curso) != EOF)
  {
    updateTransferencias(analise, 1);
    insertDado(heap, filesIn, nBlocos, &indexFita, dado, analise);
    n -= 1;
  }
  fclose(in);

  if (heap_hasFullMarked(heap))
  {                                                       //se a heap estiver com tudo marcador reseta a heap desmarcando
    indexFita = indexFita != (N - 1) ? indexFita + 1 : 0; //altera a fita para a escrita
    heap_reset(heap);
    //atualização da quantidade de blocos da fita
    nBlocos[indexFita] += 1;
  }

  FILE *arq = fopen(filesIn[indexFita], "a+");

  while (heap->tam > 0)
  { //limpa os elementos restantes na heap e escreve no arquivo
    TipoItem tmp = heap_remove(heap, analise);
    updateTransferencias(analise, 1);
    fprintf(arq, "%s %lf %s %s %s\n", tmp.chave.inscricao, tmp.chave.nota, tmp.chave.estado, tmp.chave.cidade, tmp.chave.curso);

    if (heap->nMarked == heap->tam && heap->tam > 0)
    { //verifica se tudo está marcado
      updateTransferencias(analise, 1);
      fprintf(arq, "%c\n", '\0'); //indica final de um bloco
      fclose(arq);
      nBlocos[indexFita] += 1;
      indexFita = indexFita != (N - 1) ? indexFita + 1 : 0;
      arq = fopen(filesIn[indexFita], "a+");
      heap_reset(heap); //reseta todos os dados marcador para não marcados
    }
  }
  updateTransferencias(analise, 1);
  fprintf(arq, "%c\n", '\0'); //fim da fita
  fclose(arq);
}

void intercalacao(TipoHeap *heap, FILE *fitaRead[], const char *fitaWrite[], int nBlocos[], int *indexFita, Analise *analise)
{
  FILE *fita;
  FILE *fitaPai;
  TipoDado dado;
  TipoItem min;
  int totalBlocosFinalizados = 0;
  int blocoFitaEhFinalizado[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int fitasAtivas[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int nFitasAtivas = 0, i = 0, j = 0;

  //preenchimento da heap com os dados do arquivo
  while (!heap_isFull(heap))
  { //preencheno a heap intercalando as fitas
    if (fscanf(fitaRead[i], "%s", dado.inscricao) != EOF)
    {
      updateTransferencias(analise, 1);
      if (strcmp(dado.inscricao, "\0"))
      { //caso não seja fim do bloco
        updateTransferencias(analise, 1);
        fscanf(fitaRead[i], "%lf %2[A-Z a-z] %49[A-Z Ã Â À Á Õ Ó Ô Ç Ì Ê É ' -] %29[A-Z Ã Â À Á Õ Ó Ô Ç Ì Ê É ' -]", &dado.nota, dado.estado, dado.cidade, dado.curso);
        heap_addReg(heap, dado, false, i + 1, analise);
        fitasAtivas[i] = 1;
        j += fitasAtivas[i];
      }
    }

    if (i == (N - 1) && !heap_isFull(heap) && j == 0) //é verdadeiro quando não há dados para serem lidos
      break;

    if (i < (N - 1)) // incrementa para a proxima fita
      i++;
    else // reseta o para o inicio das fitas
    {
      i = 0;
      j = 0;
    }
  }

  //conta a quantidade de fitas ativas, ou seja, fitas que estão sendo lidas
  for (int i = 0; i < N; i++)
    nFitasAtivas += fitasAtivas[i];

  while (totalBlocosFinalizados < nFitasAtivas || !heap_isEmpty(heap))
  {
    min = heap_minValue(heap);
    if (blocoFitaEhFinalizado[min.fitaIndicator - 1])
    { //se na fita não há mais itens no bloco, apenas remove o item da heap
      TipoItem tmp = heap_remove(heap, analise);
      fita = fopen(fitaWrite[*indexFita], "a+");
      updateTransferencias(analise, 1);
      fprintf(fita, "%s %lf %s %s %s\n", tmp.chave.inscricao, tmp.chave.nota, tmp.chave.estado, tmp.chave.cidade, tmp.chave.curso);
      fclose(fita);
    }
    else
    { //há mais dados da mesma fita e do mesmo bloco para adicionar a heap
      fitaPai = fitaRead[min.fitaIndicator - 1];
      updateTransferencias(analise, 1);
      fscanf(fitaPai, "%s ", dado.inscricao);
      if (!strcmp(dado.inscricao, "\0"))
      { //se for o final de um bloco
        totalBlocosFinalizados += 1;
        blocoFitaEhFinalizado[min.fitaIndicator - 1] = 1; //indica que o bloco em n foi finalizado

        //remove o ultimo item dessa fita da heap
        TipoItem tmp = heap_remove(heap, analise);
        fita = fopen(fitaWrite[*indexFita], "a+");
        updateTransferencias(analise, 1);
        fprintf(fita, "%s %lf %s %s %s\n", tmp.chave.inscricao, tmp.chave.nota, tmp.chave.estado, tmp.chave.cidade, tmp.chave.curso);
        fclose(fita);
      }
      else
      { // ainda não é o fim do bloco
        updateTransferencias(analise, 1);
        fscanf(fitaPai, "%lf %2[A-Z a-z] %49[A-Z Ã Â À Á Õ Ó Ô Ç Ì Ê É ' -] %29[A-Z Ã Â À Á Õ Ó Ô Ç Ì Ê É ' -]", &dado.nota, dado.estado, dado.cidade, dado.curso);
        TipoItem tmp = heap_organize(heap, dado, false, min.fitaIndicator, analise);
        fita = fopen(fitaWrite[*indexFita], "a+");
        updateTransferencias(analise, 1);
        fprintf(fita, "%s %lf %s %s %s\n", tmp.chave.inscricao, tmp.chave.nota, tmp.chave.estado, tmp.chave.cidade, tmp.chave.curso);
        fclose(fita);
      }
    }
  }

  if (nFitasAtivas == 0) //caso não tenha nenhum bloco para intercalar, termina a função
    return;
  else if (totalBlocosFinalizados == nFitasAtivas)
  { //chamada recursiva para os blocos restante
    nBlocos[*indexFita] += 1;

    //escrita para indicar o fim do bloco
    fita = fopen(fitaWrite[*indexFita], "a+");
    updateTransferencias(analise, 1);
    fprintf(fita, "%c\n", '\0'); //indica final de um bloco
    fclose(fita);

    //incrementa o indicador da fita ou reseta para 0
    *indexFita = *indexFita != (N - 1) ? *indexFita + 1 : 0;
    intercalacao(heap, fitaRead, fitaWrite, nBlocos, indexFita, analise);
  }
}

void insertDado(TipoHeap *heap, const char *filesIn[], int nBlocos[], int *indexFita, TipoChave nValue, Analise *analise)
{
  FILE *arq;

  if (!heap_isFull(heap))
  {
    heap_addReg(heap, nValue, false, -1, analise);
  }
  else
  {
    if (heap_hasFullMarked(heap))
    { //se a heap estiver com todos os itens marcados
      arq = fopen(filesIn[*indexFita], "a+");
      updateTransferencias(analise, 1);
      fprintf(arq, "%c\n", '\0'); //indica final de um bloco
      fclose(arq);
      nBlocos[*indexFita] += 1;
      *indexFita = *indexFita != (N - 1) ? *indexFita + 1 : 0; //incrementa o indicador da fita ou reseta para 0
      heap_reset(heap);                                        //altera todos os itens marcados para não marcados
    }

    updateComparacoes(analise, 1);
    if (nValue.nota < heap_minValue(heap).chave.nota)
    { //novo valor for menor que o valor retirado ha heap, ele é marcado, e será considerado o menor
      TipoItem tmp = heap_organize(heap, nValue, true, -1, analise);
      arq = fopen(filesIn[*indexFita], "a+");
      updateTransferencias(analise, 1);
      fprintf(arq, "%s %lf %s %s %s\n", tmp.chave.inscricao, tmp.chave.nota, tmp.chave.estado, tmp.chave.cidade, tmp.chave.curso);
      fclose(arq);
    }
    else
    { //caso o novo valor senha maior ou menor que o valor retirado
      TipoItem tmp = heap_organize(heap, nValue, false, -1, analise);
      arq = fopen(filesIn[*indexFita], "a+");
      updateTransferencias(analise, 1);
      fprintf(arq, "%s %lf %s %s %s\n", tmp.chave.inscricao, tmp.chave.nota, tmp.chave.estado, tmp.chave.cidade, tmp.chave.curso);
      fclose(arq);
    }
  }
}
