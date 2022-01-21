#include <stdio.h>
#include <string.h>
#define TOTAL 5

int main(){
  char resposta[4], sexo[10];
  int contResposta = 0, contSexo = 0;

  for(int i = 0; i < TOTAL; i++){
    scanf("%s %s", resposta, sexo);
    if(strcmp(resposta, "s") == 0)
        contResposta++;
    if(strcmp(sexo, "f") == 0)
        contSexo++;
  }
  printf("Responderam sim: %d\n", contResposta);
  printf("Responderam nao: %d\n", TOTAL-contResposta);
  printf("Porcentagem do sexo feminino: %d%%\n", contSexo*100/TOTAL);
  printf("Porcentagem do sexo masculino: %d%%\n", (TOTAL-contSexo)*100/TOTAL);

  return 0;
}
