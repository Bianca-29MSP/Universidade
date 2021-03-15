#include <stdio.h>

int main(){
 int n, i = 0;
 int quant;
 char tipo; //R:Rato S:Sapo C:Coelho
 int quantR = 0, quantS = 0, quantC = 0;
 scanf("%d", &n);
 while(i < n){
   scanf("%d %c", &quant, &tipo);
   if(tipo ==  'R')
    quantR+= quant;
   else if(tipo == 'S')
    quantS+= quant;
   else if(tipo == 'C')
    quantC+= quant;
  i++;
 }
 int total = quantC + quantR + quantS;
 double percentualC = (quantC * 100.00) / total;
 double percentualR = (quantR * 100.00) / total;
 double percentualS = (quantS * 100.00) / total;

 printf("Total: %d cobaias\n", total);
 printf("Total de coelhos: %d\n", quantC);
 printf("Total de ratos: %d\n", quantR);
 printf("Total de sapos: %d\n", quantS);
 printf("Percentual de coelhos: %.2lf %%\n", percentualC);
 printf("Percentual de ratos: %.2lf %%\n", percentualR);
 printf("Percentual de sapos: %.2lf %%\n", percentualS);
  return 0;
}
