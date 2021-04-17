
typedef struct
{
  int movInsertion;
  int compInsertion;
  int movQuick;
  int compQuick;
} Contador;

typedef int Item;

void hybridsortInicia(Item *v, int n, Contador *count);

void hybridsort(Item *v, int l, int r);

int partition(Item *v, int l, int r);

int pivo(Item *v, int l, int r);

void insertionsort(Item *arr, int l, int r);