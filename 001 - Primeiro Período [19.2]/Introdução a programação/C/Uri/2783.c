#include <stdio.h>

int main(){
    int n, c, m, i, j, cont = 0;
    scanf("%d %d %d", &n, &c, &m);  //  número de figurinhas (e espaços) do álbum, o número de figurinhas carimbadas do álbum e o número de figurinhas já compradas
    int numc[n], numm[m];
    for(i = 0; i < c; i++){
      scanf("%d", &numc[i]);
    }
    for(j = 0; j < c; j++){
      scanf("%d", &numm[j]);
    }
    for(i = 0; i < c; i++){
      for(j = 0; j < m; j++){
        if(numc[i] == numm[j]){
          cont++;
        }
      }
    }

   if(cont != c)
      printf("%d\n", c - cont);
    else
      printf("0\n");


    return 0;
}
