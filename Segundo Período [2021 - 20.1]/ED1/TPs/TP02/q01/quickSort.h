typedef int ITEMQUICK;

void quicksortAndInsetionsort(ITEMQUICK *v, int n, int min, int *count);

void quicksort(ITEMQUICK *v, int l, int r, int min);

int partition(ITEMQUICK *v, int l, int r);

int pivo(ITEMQUICK *v, int l, int r);