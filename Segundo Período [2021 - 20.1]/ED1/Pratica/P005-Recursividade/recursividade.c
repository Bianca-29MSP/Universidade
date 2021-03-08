#include "recursividade.h"

int fibonacci(int n, int *qtd)
{
  if (n <= 1)
    return n;

  *qtd += 2;
  return fibonacci(n - 1, qtd) + fibonacci(n - 2, qtd);
}

void arrayInverso(int *arr, int n)
{
  if (n == 0)
    printf("%d\n", arr[n]);
  else if (n > 0)
  {
    printf("%d ", arr[n]);
    arrayInverso(arr, n - 1);
  }
}

int grau9(long long n, int *count)
{
  if (n < 9)
  {
    return *count = 0;
  }
  else if (n == 9)
    return *count + 1;

  int soma = somaDigitos(n, 0);
  *count += 1;
  grau9(soma, count);
  return *count;
}

int somaDigitos(long long n, int count)
{
  if (n < 10)
    return count + (n % 10);
  else
  {
    count += n % 10;
    somaDigitos(n / 10, count);
  }
}

int buscaBinaria(int *vetor, int inicio, int final, int elemento)
{
  int metade = (final + inicio) / 2;

  if (vetor[metade] == elemento)
    return metade;

  else if (elemento < vetor[inicio] || elemento > vetor[final])
    return -1;

  else if (elemento < vetor[metade])
    buscaBinaria(vetor, inicio, (metade - 1), elemento);

  else if (elemento > vetor[metade])
    buscaBinaria(vetor, (metade + 1), final, elemento);
};