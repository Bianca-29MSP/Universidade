#include <stdio.h>
#include <string.h>

int main(){
   char leituraArq[100];
   int cont = 0;
   FILE *arq = fopen("arq.txt", "r");
   fgets(leituraArq, 100 , arq);
   int numLetras = strlen(leituraArq);
   for(int i = 0; i < numLetras; i++){
     if(leituraArq[i] == ' ')
        cont++;
   }
   printf("O texto do arquivo """arq.txt"" possui %d espaços.\n", cont);
   fclose(arq);
   return 0;
}
