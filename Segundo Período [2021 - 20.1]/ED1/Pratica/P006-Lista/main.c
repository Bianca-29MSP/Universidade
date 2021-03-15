#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
  int op = 0;
  int value;
  int count = 0;
  Lista *l = lst_cria();

  while (op != -1)
  {
    scanf("%d", &op);
    switch (op)
    {
    case 2:
      scanf("%d", &value);
      lst_insere_ordenado(l, value);
      break;
    case 3:
      scanf("%d", &value);
      lst_retira(l, value);
      break;
    case 4:
      scanf("%d", &value);
      printf("%d\n", lst_pertence(l, value));
      break;
    case 5:
      lst_imprime(l);
      break;
    case 6:
      lst_liberar(&l);
      count++;
      break;
    default:
      op = -1;
      break;
    }
  }

  if (count == 0) //Garantindo o free
    lst_liberar(&l);
  return 0;
}