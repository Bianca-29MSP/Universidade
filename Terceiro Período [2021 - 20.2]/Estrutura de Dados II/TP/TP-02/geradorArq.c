#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "geradorArq.h"
#include "dado.h"

typedef TipoDado Dado;

void geradorInscricao(Dado *aluno)
{
  int nZero = rand() % 4 + 1;
  int i, init = 0;
  char insc[8];
  if (nZero != 0)
  {
    for (i = 0; i < nZero; i++)
      insc[i] = '0';
    init = nZero - 1;
  }

  for (i = init; i < 8; i++)
    insc[i] = (rand() % 8 + 1) + '0';

  strcpy(aluno->inscricao, insc);
}

void geradorEstadoCidade(Dado *aluno)
{
  char *estados_cidades[][60] = {
      {"MG", "BELO HORIZONTE                                 "},
      {"MG", "UBERLÂNDIA                                     "},
      {"MG", "CONTAGEM                                       "},
      {"MG", "JUIZ DE FORA                                   "},
      {"MG", "BETIM                                          "},
      {"MG", "MONTES CLAROS                                  "},
      {"MG", "RIBEIRÃO DAS NEVES                             "},
      {"MG", "UBERABA                                        "},
      {"MG", "GOVERNADOR VALADARES                           "},
      {"MG", "IPATINGA                                       "},
      {"MG", "SETE LAGOAS                                    "},
      {"MG", "DIVINÓPOLIS                                    "},
      {"MG", "MARIANA                                        "},
      {"MG", "OURO PRETO                                     "},
      {"MG", "TIMÓTEO                                        "},
      {"SP", "SÃO PAULO                                      "},
      {"SP", "GUARULHOS                                      "},
      {"SP", "CAMPINAS                                       "},
      {"SP", "SÃO BERNARDO DO CAMPO                          "},
      {"SP", "SÃO JOSÉ DOS CAMPOS                            "},
      {"SP", "SANTO ANDRÉ                                    "},
      {"SP", "RIBEIRÃO PRETO                                 "},
      {"SP", "OSASCO                                         "},
      {"SP", "SOROCABA                                       "},
      {"SP", "MAUÁ                                           "},
      {"SP", "SÃO JOSÉ DO RIO PRETO                          "},
      {"SP", "MOGI DAS CRUZES                                "},
      {"SP", "SANTOS                                         "},
      {"SP", "DIADEMA                                        "},
      {"SP", "JUNDIAÍ                                        "},
      {"AM", "MANAUS                                         "},
      {"AM", "PARINTINS                                      "},
      {"AM", "ITACOATIARA                                    "},
      {"AM", "MANACAPURU                                     "},
      {"AM", "COARI                                          "},
      {"AM", "TABATINGA                                      "},
      {"AM", "MAUÉS                                          "},
      {"AM", "TEFÉ                                           "},
      {"AM", "MANICORÉ                                       "},
      {"AM", "HUMAITÁ                                        "},
      {"BA", "SALVADOR                                       "},
      {"BA", "FEIRA DE SANTANA                               "},
      {"BA", "VITÓRIA DA CONQUISTA                           "},
      {"BA", "CAMAÇARI                                       "},
      {"BA", "JUAZEIRO                                       "},
      {"BA", "ITABUNA                                        "},
      {"BA", "LAURO DE FREITAS                               "},
      {"BA", "ILHÉUS                                         "},
      {"BA", "JEQUIÉ                                         "},
      {"RJ", "RIO DE JANEIRO                                 "},
      {"RJ", "SÃO GONÇALO                                    "},
      {"RJ", "DUQUE DE CAXIAS                                "},
      {"RJ", "NOVA IGUAÇU                                    "},
      {"RJ", "NITERÓI                                        "},
      {"RJ", "BELFORD ROXO                                   "},
      {"RJ", "CAMPOS DOS GOYTACAZES                          "},
      {"RJ", "CABO FRIO                                      "},
      {"RJ", "ANGRA DOS REIS                                 "},
      {"RJ", "NILÓPOLIS                                      "}}; //58

  int index = rand() % 58;
  strcpy(aluno->estado, estados_cidades[index][0]);
  strcpy(aluno->cidade, estados_cidades[index][1]);
}

void geradorCurso(Dado *aluno)
{
  char *cursos[32] = {
      "ADMINISTRAÇÃO                 ",
      "ARQUITETURA E URBANISMO       ",
      "BIOMEDICINA                   ",
      "CIÊNCIA DA COMPUTAÇÃO         ",
      "CIÊNCIAS BIOLÓGICAS           ",
      "CIÊNCIAS CONTÁBEIS            ",
      "CIÊNCIAS ECONÔMICAS           ",
      "COMÉRCIO EXTERIOR             ",
      "DESIGN                        ",
      "DIREITO                       ",
      "EDUCAÇÃO FÍSICA               ",
      "ENFERMAGEM                    ",
      "ENGENHARIA ELETRICA           ",
      "ENGENHARIA MECÂNICA           ",
      "FARMÁCIA                      ",
      "FÍSICA                        ",
      "FISIOTERAPIA                  ",
      "GASTRONOMIA                   ",
      "GEOGRAFIA                     ",
      "GESTÃO DE RECURSOS HUMANOS    ",
      "GESTÃO DE TURISMO             ",
      "GESTÃO PUBLICA                ",
      "HISTÓRIA                      ",
      "LETRAS                        ",
      "MEDICINA                      ",
      "NUTRIÇÃO                      ",
      "ODONTOLOGIA                   ",
      "PEDAGOGIA                     ",
      "PSICOLOGIA                    ",
      "RADIOLOGIA                    ",
      "RELAÇÕES INTERNACIONAIS       ",
      "TURISMO                       "}; //32

  int index = rand() % 32;
  strcpy(aluno->curso, cursos[index]);
}

void geradorArq(char *path, int tam, int op)
{
  srand(time(NULL));
  Dado aluno;
  Dado aux;

  FILE *arq = fopen(path, "w");
  if (arq == NULL)
  {
    printf("Não foi possivel criar o arquivo.\n");
    exit(1);
  }

  double minNota = 0.0;
  double maxNota = 100.0;

  int divider = tam / 100;

  for (int i = 1; i <= tam; i++)
  {
    if (op == 1)
    { //ascendentemente
      if ((i + 1) % divider)
        aluno.nota = minNota++;
    }
    else if (op == 2)
    { //descendentemente
      if ((i + 1) % divider)
        aluno.nota = maxNota--;
    }
    else
    { //aleatorio
      aluno.nota = (rand() % 100) + ((rand() % 100) / 100.0);
    }

    geradorInscricao(&aluno);
    geradorEstadoCidade(&aux);
    geradorCurso(&aluno);
    if (aluno.nota < 10)
      fprintf(arq, "%s 0%.1lf %s %s  %s\n", aluno.inscricao, aluno.nota, aux.estado, aux.cidade, aluno.curso);
    else
      fprintf(arq, "%s %.1lf %s %s  %s\n", aluno.inscricao, aluno.nota, aux.estado, aux.cidade, aluno.curso);
  }

  fclose(arq);
}