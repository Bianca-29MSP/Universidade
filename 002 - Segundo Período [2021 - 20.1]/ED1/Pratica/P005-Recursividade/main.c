#include "recursividade.h"

int main()
{

  int op = 0;
  int op_interno = 0;

  int n;
  int qtd_chamada = 0;

  int *arr;

  long long n_long;
  int qtd = 0;

  int result03;

  int elemento;

  while (op != -100)
  {
    scanf("%d", &op);
    switch (op)
    {
    case 1:
      scanf("%d", &n);
      n = fibonacci(n, &qtd_chamada);
      printf("%d %d\n", n, qtd_chamada);
      qtd_chamada = 0;
      break;

    case 2:
      n = 0;
      scanf("%d", &n);
      arr = (int *)malloc(sizeof(int *) * n);
      for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
      arrayInverso(arr, (n - 1));
      free(arr);
      break;

    case 3:
      scanf("%lld", &n_long);
      result03 = grau9(n_long, &qtd);
      printf("%d\n", result03);
      break;

    case 4:
      n = 0;
      printf("Incompleto\n");

      scanf("%d", &n);

      arr = (int *)malloc(sizeof(int *) * n);

      for (int i = 0; i < n; i++)
      {
        scanf("%d", &arr[i]);
      }

      scanf("%d", &elemento);
      printf("%d\n", buscaBinaria(arr, 0, (n - 1), elemento));

      break;

    default:
      break;
    }
  }
  free(arr);
  return 0;
}
