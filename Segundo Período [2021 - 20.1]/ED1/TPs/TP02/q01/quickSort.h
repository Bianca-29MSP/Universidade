typedef int ITEMQUICK;

void quicksort(ITEMQUICK *v, int l, int r, int *movQ, int *compQ, int *movI, int *compI);

int partition(ITEMQUICK *v, int l, int r, int *mov, int *comp);

int pivo(ITEMQUICK *v, int l, int r, int *mov, int *comp);