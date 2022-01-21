#include "quickSortExterno.h"

void ordenacaoQuickSortExterno(int quantidade, Analise *analise)
{
    iniciaAnalise(analise);
    iniciaContagemTempo(analise);

    FILE *arqLEs;
    FILE *arqLi;
    FILE *arqEi;

    arqLi = fopen("qsExterno/provao.dat", "r+b");
    if (arqLi == NULL)
    {
        printf("Arquivo não pode ser aberto\n");
        exit(1);
    }
    arqEi = fopen("qsExterno/provao.dat", "r+b");
    if (arqEi == NULL)
    {
        printf("Arquivo não pode ser aberto\n");
        exit(1);
    }
    arqLEs = fopen("qsExterno/provao.dat", "r+b");
    if (arqLEs == NULL)
    {
        printf("Arquivo não pode ser aberto\n");
        exit(1);
    }

    quicksortExterno(&arqLi, &arqEi, &arqLEs, 1, quantidade, analise);

    fflush(arqLi);
    fclose(arqEi);
    fclose(arqLEs);
    fclose(arqLi);

    finalizaContagemTempo(analise);
    updateTempo(analise);
}

void quicksortExterno(FILE **arqLi, FILE **arqEi, FILE **arqLEs, int esq, int dir, Analise *analise)
{
    int i, j;

    TipoArea area[N_AREA];

    if (dir - esq < 1)
        return;

    faVazia(area, analise);

    particao(arqLi, arqEi, arqLEs, area, esq, dir, &i, &j, analise);
    fflush(*arqLi);
    fflush(*arqEi);
    fflush(*arqLEs);
    if (i - esq < dir - j)
    {
        quicksortExterno(arqLi, arqEi, arqLEs, esq, i, analise);
        quicksortExterno(arqLi, arqEi, arqLEs, j, dir, analise);
    }
    else
    {
        quicksortExterno(arqLi, arqEi, arqLEs, j, dir, analise);
        quicksortExterno(arqLi, arqEi, arqLEs, esq, i, analise);
    }
}

void leSup(FILE **arqLEs, TipoChave *ultLido, int *ls, short *ondeLer, Analise *analise)
{
    fseek(*arqLEs, (*ls - 1) * sizeof(TipoChave), SEEK_SET);
    updateTransferencias(analise, 1);
    fread(ultLido, sizeof(TipoChave), 1, *arqLEs);
    (*ls)--;
    *ondeLer = FALSE;
}

void leInf(FILE **arqLi, TipoChave *ultLido, int *li, short *ondeLer, Analise *analise)
{
    updateTransferencias(analise, 1);
    fread(ultLido, sizeof(TipoChave), 1, *arqLi);
    (*li)++;
    *ondeLer = TRUE;
}

void inserirArea(TipoArea *area, TipoChave *ultLido, int *nrArea, Analise *analise)
{
    insereItem(*ultLido, area, analise);
    *nrArea = obterNumCelOcupadas(area, analise);
}

void escreverMax(FILE **arqLEs, TipoChave r, int *es, Analise *analise)
{
    fseek(*arqLEs, (*es - 1) * sizeof(TipoChave), SEEK_SET);
    updateTransferencias(analise, 1);
    fwrite(&r, sizeof(TipoChave), 1, *arqLEs);
    (*es)--;
}

void escreverMin(FILE **arqEi, TipoChave r, int *ei, Analise *analise)
{
    updateTransferencias(analise, 1);
    fwrite(&r, sizeof(TipoChave), 1, *arqEi);
    (*ei)++;
}

void retiraMax(TipoArea *area, TipoChave *r, int *nrArea, Analise *analise)
{
    retiraUltimo(area, r, analise);
    *nrArea = obterNumCelOcupadas(area, analise);
}

void retiraMin(TipoArea *area, TipoChave *r, int *nrArea, Analise *analise)
{
    retiraPrimeiro(area, r, analise);
    *nrArea = obterNumCelOcupadas(area, analise);
}

void particao(FILE **arqLi, FILE **arqEi, FILE **arqLEs, TipoArea *area, int esq, int dir, int *i, int *j, Analise *analise)
{
    int ls = dir;
    int es = dir;
    int li = esq;
    int ei = esq;
    int nrArea = 0;
    double lInf = INT_MIN;
    double lSup = INT_MAX;

    short ondeLer = TRUE;

    TipoChave ultLido, r;
    fseek(*arqLi, (li - 1) * sizeof(TipoChave), SEEK_SET);
    fseek(*arqEi, (ei - 1) * sizeof(TipoChave), SEEK_SET);

    *i = esq - 1;
    *j = dir + 1;
    while (ls >= li)
    {
        if (nrArea < N_AREA - 1)
        {
            if (ondeLer)
            {
                leSup(arqLEs, &ultLido, &ls, &ondeLer, analise);
            }
            else
            {
                leInf(arqLi, &ultLido, &li, &ondeLer, analise);
            }
            inserirArea(area, &ultLido, &nrArea, analise);
            continue;
        }
        if (ls == es)
            leSup(arqLEs, &ultLido, &ls, &ondeLer, analise);
        else if (li == ei)
            leInf(arqLi, &ultLido, &li, &ondeLer, analise);
        else if (ondeLer)
            leSup(arqLEs, &ultLido, &ls, &ondeLer, analise);
        else
            leInf(arqLi, &ultLido, &li, &ondeLer, analise);

        updateComparacoes(analise, 1);
        if (ultLido.nota > lSup)
        {
            *j = es;
            escreverMax(arqLEs, ultLido, &es, analise);
            continue;
        }

        updateComparacoes(analise, 1);
        if (ultLido.nota < lInf)
        {
            *i = ei;
            escreverMin(arqEi, ultLido, &ei, analise);
            continue;
        }

        inserirArea(area, &ultLido, &nrArea, analise);

        if (ei - esq < dir - es)
        {
            retiraMin(area, &r, &nrArea, analise);
            escreverMin(arqEi, r, &ei, analise);
            lInf = r.nota;
        }
        else
        {
            retiraMax(area, &r, &nrArea, analise);
            escreverMax(arqLEs, r, &es, analise);
            lSup = r.nota;
        }
    }

    while (ei <= es)
    {
        retiraMin(area, &r, &nrArea, analise);
        escreverMin(arqEi, r, &ei, analise);
    }
}

void faVazia(TipoArea *area, Analise *analise)
{
    for (int i = 0; i < N_AREA; i++)
    {
        strcpy(area[i].inscricao, " ");
        area[i].nota = -1.0;
        strcpy(area[i].estado, " ");
        strcpy(area[i].cidade, " ");
        strcpy(area[i].curso, " ");
    }
}

int obterNumCelOcupadas(TipoArea *area, Analise *analise)
{
    int cont = 0;

    //Conta até achar uma posição vazia ou até o fim da área
    updateComparacoes(analise, 1);
    while (area[cont].nota != -1.0 && cont < N_AREA)
    {
        updateComparacoes(analise, 1);
        cont++;
    }

    return cont;
}

void retiraUltimo(TipoArea *area, TipoChave *r, Analise *analise)
{
    int cont = 0;

    //Achando a última posição válida da área
    updateComparacoes(analise, 1);
    while (area[cont].nota != -1.0 && cont < N_AREA)
    {
        updateComparacoes(analise, 1);
        cont++;
    }

    cont--; //Achar o último aluno válido, antes da primeira posição vazia (aluno com inscrição -1)

    //R recebe o último aluno
    *r = area[cont];

    //Esta última posição se torna vazia
    strcpy(area[cont].inscricao, " ");
    area[cont].nota = -1.0;
    strcpy(area[cont].estado, " ");
    strcpy(area[cont].cidade, " ");
    strcpy(area[cont].curso, " ");
}

void retiraPrimeiro(TipoArea *area, TipoChave *r, Analise *analise)
{
    int i = 0, j = 1;

    //R recebe o primeiro elemento da área
    *r = area[0];

    //Reorganizando a área
    updateComparacoes(analise, 1);
    while (area[j].nota != -1.0 && i < N_AREA - 1)
    {
        updateComparacoes(analise, 1);
        area[i] = area[j];
        i++;
        j++;
    }

    //Criando uma posição vazia no último elemento
    strcpy(area[i].inscricao, " ");
    area[i].nota = -1.0;
    strcpy(area[i].estado, " ");
    strcpy(area[i].cidade, " ");
    strcpy(area[i].curso, " ");
}

void insereItem(TipoChave ultLido, TipoArea *area, Analise *analise)
{
    int i = 0;
    int j = N_AREA - 2, k = N_AREA - 1;

    //Achando a posição correta na área

    updateComparacoes(analise, 2);
    while (area[i].nota < ultLido.nota && area[i].nota != -1.0 && i < N_AREA)
    {
        updateComparacoes(analise, 2);
        i++;
    }

    //Reorganizando a área
    while (j >= i)
    {
        area[k] = area[j];
        j--;
        k--;
    }

    //Posição recebe o aluno a ser inserido
    area[i] = ultLido;
}
