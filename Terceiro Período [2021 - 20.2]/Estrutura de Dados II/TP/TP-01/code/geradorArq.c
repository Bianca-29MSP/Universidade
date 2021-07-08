#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "geradorArq.h"
#include "dados.h"

// typedef struct
// {
//   int chave;
//   long int dado1;
//   char dado2[500], dado3[3000];
// } Dados;

void geradorString(Dados *dado)
{
  char list_str500[5][500];
  char list_str3000[2][3000];

  strcpy(list_str500[0], "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam aliquet elit et magna venenatis convallis. Vivamus sagittis, nulla ut auctor molestie, lorem dolor ornare leo, vel vulputate leo felis vel arcu. Nulla tincidunt sit amet nibh lacinia feugiat. Nulla facilisi. Sed pharetra sit amet lorem id semper. Cras vestibulum nulla vel turpis fermentum feugiat. Etiam facilisis accumsan risus, quis elementum lorem consequat non. Curabitur accumsan orci lectus, varius sollicitudin ex commodo.");
  strcpy(list_str500[1], "Donec tortor urna, scelerisque in metus vel, lacinia egestas purus. Nullam purus tortor, pellentesque et urna ut, eleifend convallis purus. Nunc at lobortis augue. Aenean sit amet nunc vel ante rutrum lacinia. Quisque a tempor lorem. Phasellus posuere eget massa vitae euismod. Maecenas mattis mattis dignissim. Proin vitae feugiat purus. Nulla facilisi. Proin pulvinar purus erat.Mauris cursus sodales pharetra.");
  strcpy(list_str500[2], "Curabitur eget libero sodales, hendrerit urna vulputate, tempus. Aliquam scelerisque rhoncus risus ut congue.Ut rutrum massa odio, ut scelerisque velit vehicula non.Donec quis ultrices sapien, ut elementum risus.Aliquam erat volutpat.Cras malesuada lacus urna, et pellentesque leo malesuada ut.Maecenas eleifend lobortis ornare.Mauris cursus sodales pharetra. Nullam purus tortor, pellentesque et urna ut, eleifend convallis purus. Quisque a tempor lorem. Phasellus posuere eget massa vitae euismod.");
  strcpy(list_str500[3], "Donec id cursus turpis. Nulla commodo lacus iaculis, elementum nulla in, tincidunt nunc. Quisque pretium scelerisque ipsum, vel suscipit dui. Phasellus in mi ac libero dictum lacinia. Integer non lectus turpis. Proin ultrices at nulla ac lacinia. Donec porttitor egestas lorem, a posuere libero mollis malesuada. Proin vitae feugiat purus. Nulla facilisi. Proin pulvinar purus erat.");
  strcpy(list_str500[4], "Curabitur ullamcorper nunc ex, id consectetur lorem feugiat et. Suspendisse potenti. Cras pretium lectus sit amet ullamcorper tincidunt. Duis sapien leo, ultrices vitae tristique id, varius sed quam. Vivamus at ex mi. Nam risus odio, vehicula ac malesuada nec, imperdiet eget dolor. Duis luctus interdum urna, quis condimentum ipsum elementum ac. Sed commodo sed justo quis tempor. Integer vel elit turpis. Nam commodo accumsan felis id commodo. Maecenas id fermentum justo, at condimentum tellus.");

  strcpy(list_str3000[0], "Sed vestibulum congue purus, eu viverra nulla porta sed. Etiam et neque vitae mi aliquet vestibulum. Vestibulum faucibus et lacus volutpat facilisis. Donec mauris massa, dignissim in lorem vitae, volutpat facilisis metus. Etiam vehicula ante in enim egestas efficitur. Nunc est erat, molestie eget ante id, feugiat lobortis massa. Phasellus porttitor massa vitae elit bibendum, sit amet luctus velit rutrum. Fusce tincidunt tempor magna, eget malesuada ex egestas vel. Curabitur ac lorem pharetra, tristique erat non, imperdiet erat. Donec elementum tortor quis metus placerat gravida. Aliquam nec cursus diam. Nunc eu sodales urna, vel commodo augue. Cras in pretium ante. Etiam nec augue congue nunc pellentesque gravida a ac nunc. Sed a dui et dolor suscipit vulputate. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae. Fusce viverra ligula at porta commodo. Duis ut maximus ligula, sed dapibus ante. Donec ornare augue sed feugiat luctus. Donec quis neque massa. Nulla sodales nisi vitae nunc pellentesque finibus. Quisque vestibulum arcu lorem, sed venenatis diam consectetur sit amet. Vestibulum facilisis magna gravida sapien interdum ultrices. Sed vel viverra turpis. Morbi sodales iaculis mauris a mattis. Fusce quis elit a libero tristique elementum. Mauris eget elementum massa. Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec gravida aliquam egestas. Nulla facilisi. Vestibulum non urna pulvinar, facilisis nulla eget, porta odio. Duis ut dui at tortor auctor fermentum nec at sapien. Mauris mattis vestibulum elit non egestas. Donec nec odio tincidunt, rhoncus massa vel, semper massa. Mauris orci dui, pretium vitae tincidunt volutpat, interdum sit amet nibh. Ut fermentum volutpat lorem at rutrum. Phasellus scelerisque non lectus eget sagittis. Mauris varius nibh eget sapien dapibus consectetur. Phasellus felis nulla, interdum quis odio sit amet, aliquet efficitur dui. Ut quis neque aliquet, molestie eros eu, mattis odio. Ut eu tortor sit amet risus eleifend suscipit. Pellentesque tincidunt diam vitae mi pulvinar malesuada. Proin malesuada finibus enim, ac pulvinar mauris feugiat sit amet. Curabitur in tellus a erat sollicitudin viverra nec vitae mauris. Mauris ultricies lectus ac volutpat posuere. Curabitur non lectus a nunc maximus tincidunt ut vitae urna.");
  strcpy(list_str3000[1], "Nullam imperdiet arcu eget accumsan accumsan. Sed a elit vel massa pharetra lacinia suscipit vitae massa. Nulla eget massa consectetur, ullamcorper sem in, porttitor nisi. Cras efficitur elit eu lacus luctus, dictum ultrices ligula placerat. Nunc iaculis ut nibh eu sollicitudin. Etiam sit amet ultricies metus. Vestibulum ac massa feugiat, rhoncus nisl id, fringilla arcu. Sed porta ullamcorper mauris et lacinia. Pellentesque malesuada tortor in ultrices scelerisque. Nullam dapibus nibh sed hendrerit luctus. In id ante imperdiet, tempus dui et, faucibus nunc. Morbi rhoncus et mi non volutpat. Fusce vel ipsum volutpat, aliquam eros sed, faucibus tortor. Morbi sit amet nunc molestie, placerat elit nec, ultricies nibh. Sed nec accumsan est. Aliquam vel lorem iaculis, molestie nulla vel, tristique ex. Duis hendrerit volutpat augue, in pretium turpis gravida vel. Nam lobortis luctus porttitor. Nullam luctus tortor ut quam pellentesque tincidunt sed a nibh. Suspendisse condimentum libero non libero lobortis dictum. Donec sit amet aliquam libero, in tempus erat. Ut sed nisl diam. Maecenas feugiat dignissim lacus, in lacinia ligula venenatis quis. Suspendisse lorem sem, egestas quis pellentesque mattis, porta sed augue. Aliquam odio odio, tincidunt sed ultricies id, tempor volutpat enim. Praesent ac ullamcorper quam, ac congue elit. Suspendisse varius magna nec mollis volutpat. Ut finibus orci a quam ullamcorper, in aliquet ipsum sagittis. Proin quam urna, vulputate eu ante efficitur, condimentum elementum purus.  Sed ut mauris vel risus mollis rhoncus. Sed pulvinar neque scelerisque ex dictum, et suscipit eros faucibus. Etiam quis congue risus. Cras vel ex in massa consectetur vehicula. Fusce bibendum augue risus, vel rhoncus risus lobortis sit amet. Proin imperdiet, neque in lobortis egestas, nulla ipsum commodo nunc, in facilisis ligula quam nec nibh. Nunc maximus sed sapien at laoreet. Phasellus pharetra, lorem eu commodo iaculis, purus odio vehicula ligula, a cursus nulla nisl at odio. Integer rutrum condimentum enim, semper pharetra velit dignissim sit amet. Suspendisse elit purus, ultricies aliquet porttitor sit amet, molestie a tortor. Cras cursus sollicitudin est, eu convallis lacus posuere non. Sed at velit nec urna eleifend faucibus. Aliquam eros felis, bibendum eget lacus vel, pulvinar consectetur lacus. Aliquam gravida eget dolor non auctor. Praesent lectus magna, pretium eu ornare et, efficitur et quam. Integer sagittis gravida pellentesque. Vivamus quis massa blandit, vulputate enim sit amet, iaculis enim. In hac habitasse platea dictumst. Donec porta in dui a iaculis. Donec quis urna nec metus lacinia faucibus quis at magna. Mauris ut massa non massa pretium aliquam. Aenean viverra lacus et tellus porttitor malesuada. Etiam efficitur mauris sodales lacus ultrices gravida.");

  dados_setDado2(dado, list_str500[rand() % 5]);
  dados_setDado3(dado, list_str3000[rand() % 2]);
}

void geradorArq(int tam, int op)
{
  srand(time(NULL));
  Dados dado;

  FILE *arq = fopen("data.bin", "wb");
  if (arq == NULL)
  {
    printf("Não foi possivel criar o arquivo.\n");
    exit(1);
  }

  for (int i = 1; i <= tam; i++)
  {
    if (op == 1)
      dados_setChave(&dado, (i + 2));
    else if (op == 2)
      dados_setChave(&dado, (tam - i + 2));
    else
      dados_setChave(&dado, rand() % tam + i + 1);

    dados_setDado1(&dado, rand() + 100);
    geradorString(&dado);

    fwrite(&dado, sizeof(dado), 1, arq);
  }

  fclose(arq);
}
