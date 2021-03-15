#include <stdio.h>

int main(){
  int op = 1, i = 0, numAlunos, chapa1 = 0, chapa2 = 0, nulo = 0;
  scanf("%d", &numAlunos);

  while(i < numAlunos){
    printf("1 - Chapa 1 \n2 - Chapa 2 \n3 - Voto em branco ou nulo\n");
    scanf("%d", &op);
    if(op == 1 || op == 2 || op == 3){
        i++;
        switch (op) {
          case 1:
            chapa1++;
            break;
          case 2:
            chapa2 ++;
            break;
          case 3:
            nulo ++;
            break;
    }
    }else
      printf("Opcao invalida\n");
  }
    printf("Chapa 1: %d voto(s)\n", chapa1);
    printf("Chapa 2: %d voto(s)\n", chapa2);
    printf("Voto(s) em branco(s) ou nulo(s): %d voto(s)\n", nulo);
    if(chapa1 == chapa2)
      printf("Votacao empatada!\n");
    else if(chapa1 > chapa2)
      printf("Chapa 1 ganhou!\n");
    else
      printf("Chapa 2 ganhou!\n");

    return 0;
}
