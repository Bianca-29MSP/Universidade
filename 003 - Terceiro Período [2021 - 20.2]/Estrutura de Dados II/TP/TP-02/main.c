#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "geradorArq.h"
#include "heap.h"
#include "intercalacao2f.h"
#include "intercalacaofp1.h"
#include "quickSortExterno.h"

void printfTXT(char *path, int n);

void convertTxtToBin(char *filename, int quantidade);

void convertBinToTxt();

int main(int argc, char *argv[])
{
  char filename[30];
  int metodo;
  int quantidade;
  int situacao;
  char imprime = 0;
  char finalfile[100];

  strcpy(filename, argv[1]);
  metodo = atoi(argv[2]);
  quantidade = atoi(argv[3]);
  situacao = atoi(argv[4]);

  if (argc == 6 && !strcmp(argv[5], "[-P]"))
    imprime = 1;

  //geradorArq("data/PROVAO_.TXT", quantidade, situacao);

  //Iniciando analise
  Analise analisePrimeiraFase, analiseSegundaFase, analise;

  if (metodo == 1)
    strcpy(finalfile, intercalacaoBalanceadaVariosCaminhos2f(filename, quantidade, &analisePrimeiraFase, &analiseSegundaFase));
  else if (metodo == 2)
    strcpy(finalfile, balanceadafp1caminhos(filename, quantidade, &analisePrimeiraFase, &analiseSegundaFase));
  else if (metodo == 3)
  {
    convertTxtToBin(filename, quantidade);

    ordenacaoQuickSortExterno(quantidade, &analise);

    convertBinToTxt();

    strcpy(finalfile, "qsExterno/provaoFinal.txt");
  }

  if (imprime)
  {
    printf("\nArquivo de entrada:\n\n");
    printfTXT(filename, quantidade);
    printf("\nArquivo de saída [ordenado]:\n\n");
    printfTXT(finalfile, quantidade);
  }

  if (metodo == 1)
    printf("Metodo de intercalação balanceada de vários caminhos (2f fitas) | ");
  else if (metodo == 2)
    printf("Metodo de intercalação balanceada de vários caminhos (f+1 fitas) | ");
  else
    printf("Quicksort externo | ");

  if (situacao == 1)
    printf("Ordenado ascendentemente pelas notas\n");
  else if (situacao == 2)
    printf("Ordenado descendentemente pelas notas\n");
  else
    printf("Desordenado aleatoriamente pelas notas\n");

  if (metodo == 3)
  {
    printf("Analise QuickSort externo:\n");
    imprimirAnalise(&analise);
  }
  else
  {
    printf("Analise geração dos blocos [Fase 1]:\n");
    imprimirAnalise(&analisePrimeiraFase);
    printf("Analise geração dos blocos [Fase 2]:\n");
    imprimirAnalise(&analiseSegundaFase);
  }
  return 0;
}

void printfTXT(char *path, int n)
{
  TipoDado dado;
  FILE *arq = fopen(path, "r");
  while (n > 0 && fscanf(arq, "%s %lf %2[A-Z] %49[A-Z Ã Â À Õ Ó Ô Ç Ì Ê É ' -] %29[A-Z Ã Â À Õ Ó Ô Ç Ì Ê É ' -]\n", dado.inscricao, &dado.nota, dado.estado, dado.cidade, dado.curso) != EOF)
  {
    printf("%s %lf %s %s %s\n", dado.inscricao, dado.nota, dado.estado, dado.cidade, dado.curso);
    n--;
  }
}

void convertTxtToBin(char *filename, int quantidade)
{
  //Convertendo o arquivo txt pra binário
  TipoChave dado;
  FILE *in = fopen(filename, "r");
  FILE *out = fopen("qsExterno/provao.dat", "wb");
  while (fscanf(in, "%s %lf %2[A-Z a-z] %49[A-Z Ã Â À Á Õ Ó Ô Ç Ì Ê É ' -] %29[A-Z Ã Â À Á Õ Ó Ô Ç Ì Ê É ' -]", dado.inscricao, &dado.nota, dado.estado, dado.cidade, dado.curso) != EOF && quantidade > 0)
  {
    fwrite(&dado, sizeof(TipoChave), 1, out);
    quantidade--;
  }
  fclose(in);
  fclose(out);
}

void convertBinToTxt()
{
  //convertendo arquivo binario para txt
  TipoChave dado;
  FILE *arqTxt = fopen("qsExterno/provaoFinal.txt", "w");
  FILE *arqBin = fopen("qsExterno/provao.dat", "rb");

  fread(&dado, sizeof(TipoChave), 1, arqBin);
  while (!feof(arqBin))
  {
    fprintf(arqTxt, "%s %lf %s %s %s\n", dado.inscricao, dado.nota, dado.estado, dado.cidade, dado.curso);
    fread(&dado, sizeof(TipoChave), 1, arqBin);
  }

  fclose(arqTxt);
  fclose(arqBin);
}
