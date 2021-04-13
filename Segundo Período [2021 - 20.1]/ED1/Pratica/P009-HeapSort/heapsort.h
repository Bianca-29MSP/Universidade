
// typedef struct heap Heap;

typedef int TItem;

void heapRefaz(TItem *v, int esq, int dir, int *comp, int *mov);

void heapConstroi(TItem *v, int n, int *comp, int *mov);

void heapSort(TItem *v, int n, int *comp, int *mov);