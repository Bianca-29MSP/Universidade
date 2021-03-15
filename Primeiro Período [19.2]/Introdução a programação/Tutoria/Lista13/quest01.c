#include <stdio.h>

int main(){
   char escrita[100];
   FILE *arq = fopen("arq.txt", "w");
   fgets(escrita, 100, stdin);
   fprintf(arq, "%s\n", escrita);
   fclose(arq);
   return 0;
}
