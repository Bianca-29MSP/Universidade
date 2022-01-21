#include "intercalacaofp1.h"

// enum para dizer se a fita atual é de entrada ou saída
enum _tape
{
	in,
	out
};

//função que reune as outras
const char *balanceadafp1caminhos(const char *filename, int qtd, Analise *primeiraFase, Analise *segundaFase)
{

	// nomes dos arquivos que representam as fitas de entrada
	const char *filesIn[FITASIN] = {
			"fitas/f1/in/fita01.txt",
			"fitas/f1/in/fita02.txt",
			"fitas/f1/in/fita03.txt",
			"fitas/f1/in/fita04.txt",
			"fitas/f1/in/fita05.txt",
			"fitas/f1/in/fita06.txt",
			"fitas/f1/in/fita07.txt",
			"fitas/f1/in/fita08.txt",
			"fitas/f1/in/fita09.txt",
			"fitas/f1/in/fita10.txt",
			"fitas/f1/in/fita11.txt",
			"fitas/f1/in/fita12.txt",
			"fitas/f1/in/fita13.txt",
			"fitas/f1/in/fita14.txt",
			"fitas/f1/in/fita15.txt",
			"fitas/f1/in/fita16.txt",
			"fitas/f1/in/fita17.txt",
			"fitas/f1/in/fita18.txt",
			"fitas/f1/in/fita19.txt",
	};

	// nome do arquivo que representa a fita de saída
	const char *fileOut = {
			"fitas/f1/out/fita20.txt",
	};

	FILE *arq;

	//criação dos arquivos vazios para representar as fitas de entrada e saída
	for (int i = 0; i < FITASIN; i++)
	{
		arq = fopen(filesIn[i], "w");
		fclose(arq);
	}

	arq = fopen(fileOut, "w");
	fclose(arq);

	TipoHeap heap;
	//construção da heap
	heap_constroiHeap(&heap, FITASIN);

	//quantidade de blocos por fita e total de blocos
	int nBlocos[FITASIN], blocosT = 0;

	for (int i = 0; i < FITASIN; i++)
		nBlocos[i] = 0;

	//Inicio da analise da primeira fase
	iniciaAnalise(primeiraFase);
	iniciaContagemTempo(primeiraFase);

	criablocosOrdenadosfp1(&heap, filename, qtd, filesIn, nBlocos, primeiraFase);

	//Fim da analise da primeira fase
	finalizaContagemTempo(primeiraFase);
	updateTempo(primeiraFase);

	// contando os blocos e resetando nBlocos
	for (int i = 0; i < FITASIN; i++)
	{
		blocosT += nBlocos[i];
		nBlocos[i] = 0;
	}

	FILE *arqsIn[FITASIN];
	FILE *arqOut;
	// intercala começa com in, pois inicialmente os blocos ordenados são inseridos na entrada
	Tape intercala = in;

	int fita = 0;

	//Inicio da analise da segunda fase
	iniciaAnalise(segundaFase);
	iniciaContagemTempo(segundaFase);
	// fase de intercalação dos blocos
	while (blocosT > 1)
	{
		blocosT = 0;
		// intercalação caso os dados estejam nos arquivos de entrada
		if (intercala == in)
		{
			// limpando fileOut
			arqOut = fopen(fileOut, "w");
			fclose(arqOut);

			//abrindo arqsIn para leitura
			for (int i = 0; i < FITASIN; i++)
				arqsIn[i] = fopen(filesIn[i], "r");

			fita = 0;

			// intercalação dos arquivos da entrada e transferencia para a saida
			intercalafp1(&heap, arqsIn, fileOut, nBlocos, &fita, segundaFase);
			//sinalizando que agora os arquivos estão na fita de saída
			intercala = out;

			for (int i = 0; i < FITASIN; i++)
				fclose(arqsIn[i]);

			//Limpeza das fitas de entrada
			for (int i = 0; i < FITASIN; i++)
			{
				arqsIn[i] = fopen(filesIn[i], "wt");
				fclose(arqsIn[i]);
			}
		}
		else if (intercala == out)
		{ // intecalação caso os dados estejam no arquivo de saída
			// limpando fitas de entrada
			for (int i = 0; i < FITASIN; i++)
			{
				arqsIn[i] = fopen(filesIn[i], "w");
				fclose(arqsIn[i]);
			}

			//abrindo arqOut para leitura
			arqOut = fopen(fileOut, "r");

			// apenas distribuição dos blocos para as fitas de entrada!!!
			transfOutToIn(filesIn, arqOut, nBlocos, &fita, segundaFase);
			// sinalizando que agora os arquivos estão nas fitas de entrada
			intercala = in;

			fclose(arqOut);
			//Limpeza da fita de saída
			arqOut = fopen(fileOut, "wt");
			fclose(arqOut);
		}

		//soma as blocos em cada fita para obter o total de blocos e zera o array nBlocos
		for (int i = 0; i < FITASIN; i++)
		{
			blocosT += nBlocos[i];
			nBlocos[i] = 0;
		}
	}
	//Fim da analise da segunda fase
	finalizaContagemTempo(segundaFase);
	updateTempo(segundaFase);

	heap_destroyHeap(&heap);

	return intercala == in ? filesIn[fita] : fileOut;
}

//função responsável por criar blocos de entrada ordenados
void criablocosOrdenadosfp1(TipoHeap *heap, const char *filename, int qtd, const char **filesIn, int *nBlocos, Analise *analise)
{
	FILE *arqInicial = fopen(filename, "r");
	if (arqInicial == NULL)
	{
		printf("Erro na abertura do arquivo %s\n", filename);
		exit(1);
	}

	TipoDado dado;
	int fita = 0;

	//leitura e inserção dos dados até qtd
	while (fscanf(arqInicial, "%9s %lf %2[A-Z] %49[A-Z Ã Â À Á Õ Ó Ô Ç Ì Ê É ' -] %29[A-Z Ã Â À Á Õ Ó Ô Ç Ì Ê É ' -]\n", dado.inscricao, &dado.nota, dado.estado, dado.cidade, dado.curso) != EOF && qtd > 0)
	{
		updateTransferencias(analise, 1);
		insereDadofp1(heap, dado, filesIn, &fita, nBlocos, analise);
		qtd--;
	}
	fclose(arqInicial);

	if (heap->nMarked == heap->tam)
	{
		fita += fita != (FITASIN - 1) ? 1 : -fita; //caso eu esteja na última fita, eu volto para a primeira
		heap_reset(heap);
		//atualização da quantidade de blocos da fita
		nBlocos[fita]++;
	}

	FILE *arq = fopen(filesIn[fita], "a+");

	while (heap->tam > 0)
	{
		// limpeza da heap
		TipoItem temp = heap_remove(heap, analise);
		updateTransferencias(analise, 1);
		// inserção dos itens da heap no arquivo
		fprintf(arq, "%s %.1lf %s %s %s\n", temp.chave.inscricao, temp.chave.nota, temp.chave.estado, temp.chave.cidade, temp.chave.curso);

		//verificação se tudo está marcado
		if (heap->nMarked == heap->tam && heap->tam > 0)
		{
			updateTransferencias(analise, 1);
			fprintf(arq, "%c\n", '\0'); // fim de bloco
			fclose(arq);
			// atualização da quantidade de blocos nessa fita
			nBlocos[fita]++;
			fita += fita != (FITASIN - 1) ? 1 : -fita; //caso eu esteja na última fita, eu volto para a primeira
			arq = fopen(filesIn[fita], "a+");
			heap_reset(heap); // faz com que os itens marcados fiquem desmarcados
		}
	}
	updateTransferencias(analise, 1);
	// fim da fita
	fprintf(arq, "%c\n", '\0');
	fclose(arq);
}

//função que insere os dados na heap
void insereDadofp1(TipoHeap *heap, TipoChave dado, const char **filesIn, int *fita, int *nBlocos, Analise *analise)
{
	//verificação se a heap está cheia
	if (heap->tam != FITASIN)
	{
		heap_addReg(heap, dado, false, -1, analise); //não tem fita pois só estou inserindo na heap
	}
	else
	{
		//verificação se todos os itens da heap estão marcados
		if (heap->nMarked == heap->tam)
		{
			FILE *arq = fopen(filesIn[*fita], "a+");
			updateTransferencias(analise, 1);
			fprintf(arq, "%c\n", '\0');
			fclose(arq);
			nBlocos[*fita]++;
			(*fita) += *fita != (FITASIN - 1) ? 1 : -(*fita); //caso eu esteja na última fita, eu volto para a primeira
			heap_reset(heap);
		}

		updateComparacoes(analise, 1);
		// comparação para saber se o menor item do heap é menor que a nota atual
		Bool marcado = heap_minValue(heap).chave.nota > dado.nota ? true : false;
		TipoItem temp = heap_organize(heap, dado, marcado, -1, analise);

		// inserção do item na fita atual
		FILE *arq = fopen(filesIn[*fita], "a+");
		updateTransferencias(analise, 1);
		fprintf(arq, "%s %.1lf %s %s %s\n", temp.chave.inscricao, temp.chave.nota, temp.chave.estado, temp.chave.cidade, temp.chave.curso);
		fclose(arq);
	}
}

// função que intercala os dados dos arquivos de entrada e os transfere em blocos para o arquivo de saída
void intercalafp1(TipoHeap *heap, FILE **arqsIn, const char *fileOut, int *nBlocos, int *fita, Analise *analise)
{
	int numFitas[FITASIN];

	for (int k = 0; k < FITASIN; k++)
		numFitas[k] = 0;

	int i = 0, j = 0;
	TipoDado dado;

	//preenchimento da heap com os dados do arquivo de entrada
	while (heap->tam != FITASIN)
	{
		// checando se é fim de arquivo
		if (fscanf(arqsIn[i], "%s", dado.inscricao) != EOF)
		{
			//checando se é fim de bloco
			updateTransferencias(analise, 1);
			if (strcmp(dado.inscricao, "\0"))
			{
				updateTransferencias(analise, 1);
				fscanf(arqsIn[i], "%lf %2[A-Z a-z] %49[A-Z Ã Â À Õ Ó Ô Ç Ì Ê É ' -] %29[A-Z Ã Â À Õ Ó Ô Ç Ì Ê É ' -]\n", &dado.nota, dado.estado, dado.cidade, dado.curso);
				// adiciono registro no heap como não marcado e fita i+1
				heap_addReg(heap, dado, false, i + 1, analise);

				numFitas[i] = 1;
				j += numFitas[i];
			}
		}

		// caso já não hajam mais dados para serem lidos
		if (i == (FITASIN - 1) && j == 0 && heap->tam != FITASIN)
			break;
		else if (i < FITASIN - 1) // passa para a próxima fita se não estiver na última
			i++;
		else
		{ // se estiver na ultima fita, volta para a primeira
			i = 0;
			j = 0;
		}
	}

	int soma = 0;
	int aux = 0;

	// contando a quantidade de fitas com registros
	for (int i = 0; i < FITASIN; i++)
		soma += numFitas[i];

	int blocosFinalizados[FITASIN], contFinaliz = 0;
	for (int k = 0; k < FITASIN; k++)
		blocosFinalizados[k] = 0;

	TipoItem min;
	FILE *arq, *arqPai;
	while (contFinaliz < soma || !heap_isEmpty(heap))
	{
		// pegando o menor dado da heap
		min = heap_minValue(heap);
		// verifica se há itens no bloco da fita
		if (blocosFinalizados[min.fitaIndicator - 1])
		{ // se o bloco foi finalizado, não há itens no bloco da fita
			//remove o item da heap
			TipoItem temp = heap_remove(heap, analise);
			//insere item retirado no arquivo de saída
			arq = fopen(fileOut, "a+");
			updateTransferencias(analise, 1);
			fprintf(arq, "%s %lf %s %s %s\n", temp.chave.inscricao, temp.chave.nota, temp.chave.estado, temp.chave.cidade, temp.chave.curso);
			fclose(arq);
		}
		else
		{ // há itens no bloco da fita
			arqPai = arqsIn[min.fitaIndicator - 1];
			aux = fscanf(arqPai, "%s", dado.inscricao);
			//verifica se é final de bloco
			if (!strcmp(dado.inscricao, "\0") || aux == -1)
			{
				blocosFinalizados[min.fitaIndicator - 1] = 1;
				contFinaliz++;
				//remoção do ultimo item da fita da heap
				TipoItem temp = heap_remove(heap, analise);
				//insere item retirado no arquivo de saída
				arq = fopen(fileOut, "a+");
				updateTransferencias(analise, 1);
				fprintf(arq, "%s %lf %s %s %s\n", temp.chave.inscricao, temp.chave.nota, temp.chave.estado, temp.chave.cidade, temp.chave.curso);
				fclose(arq);
			}
			else
			{
				updateTransferencias(analise, 1);
				fscanf(arqPai, "%lf %2[A-Z a-z] %49[A-Z Ã Â À Õ Ó Ô Ç Ì Ê É ' -] %29[A-Z Ã Â À Õ Ó Ô Ç Ì Ê É ' -]", &dado.nota, dado.estado, dado.cidade, dado.curso);
				TipoItem temp = heap_organize(heap, dado, false, min.fitaIndicator, analise);
				// inserção do item na fita de saída
				arq = fopen(fileOut, "a+");
				updateTransferencias(analise, 1);
				fprintf(arq, "%s %lf %s %s %s\n", temp.chave.inscricao, temp.chave.nota, temp.chave.estado, temp.chave.cidade, temp.chave.curso);
				fclose(arq);
			}
		}
	}

	//se não houver mais blocos para intercalar
	if (soma == 0)
		return;
	//chamada recursiva para os blocos que faltam
	else if (contFinaliz == soma)
	{
		nBlocos[*fita] += 1;

		arq = fopen(fileOut, "a+");
		updateTransferencias(analise, 1);
		// fim de bloco
		fprintf(arq, "%c\n", '\0');
		fclose(arq);

		//se estiver na ultima fita, volta para a primeira, se não, vai para a próxima
		*fita = *fita != (FITASIN - 1) ? *fita + 1 : 0;
		intercalafp1(heap, arqsIn, fileOut, nBlocos, fita, analise);
	}
}

// função que distribui os blocos de Out nos arquivos de entrada
void transfOutToIn(const char **filesIn, FILE *arqOut, int *nBlocos, int *fita, Analise *analise)
{
	TipoDado dado;

	while (fscanf(arqOut, "%s", dado.inscricao) != EOF)
	{
		//checando se não é fim de bloco
		if (strcmp(dado.inscricao, "\0"))
		{
			fscanf(arqOut, "%lf %2[A-Z] %49[A-Z Ã Â À Á Õ Ó Ô Ç Ì Ê É ' -] %29[A-Z Ã Â À Á Õ Ó Ô Ç Ì Ê É ' -]\n", &dado.nota, dado.estado, dado.cidade, dado.curso);
			FILE *arq = fopen(filesIn[*fita], "a+");
			updateTransferencias(analise, 1);
			fprintf(arq, "%s %lf %s %s %s\n", dado.inscricao, dado.nota, dado.estado, dado.cidade, dado.curso);
			fclose(arq);
		}
		else
		{
			//inserindo fim de bloco
			FILE *arq = fopen(filesIn[*fita], "a+");
			updateTransferencias(analise, 1);
			fprintf(arq, "%c\n", '\0');
			fclose(arq);
			nBlocos[*fita] += 1;
			//se a fita for menor que o total, vou pra próxima, caso contrário, volto para a primeira
			(*fita) += *fita != (FITASIN - 1) ? 1 : -(*fita);
		}
	}
}