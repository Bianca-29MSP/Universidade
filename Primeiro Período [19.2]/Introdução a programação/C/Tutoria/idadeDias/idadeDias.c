#include "idadeDias.h"

int idadeDias(int dia, int mes, int ano, int diaAtual, int mesAtual, int anoAtual)
{
	int hoje = (mesAtual * 30) + diaAtual;

	return dia + (mes * 30) + ((anoAtual - ano) * 365) - hoje;
}