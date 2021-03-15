#include <stdio.h>

int main()
{
  int gremio, inter;
  int Vgremio = 0, Vinter = 0, op = 1, cont = 0, empate = 0;
  while (op == 1) {
    scanf("%d %d", &inter, &gremio);
    printf("Novo grenal (1-sim 2-nao)\n");
    scanf("%d", &op);
    if(inter == gremio)
      empate++;
    else if(inter > gremio)
      Vinter++;
    else if(gremio > inter)
      Vgremio++;
    cont++;
  }

  printf("%d grenais\n", cont);
  printf("Inter:%d\n", Vinter);
  printf("Gremio:%d\n", Vgremio);
  printf("Empates:%d\n", empate);
  if(Vgremio > Vinter)
    printf("Gremio venceu mais\n");
  else
    printf("Inter venceu mais\n");

  return 0;
}
