#include <stdio.h>

void bubbleSort(int *arr, int n);

void selectionSort(int *arr, int n);

void insertionSort(int *arr, int n);

void printArray(int *arr, int n, int pass);

void preencheArray(int *arr);

void pause();

int main()
{
  int array[6];
  int n = 6;

  preencheArray(array);

  printf("BUBBLESORT:\n");
  bubbleSort(array, n);
  printf("\n");
  pause();

  preencheArray(array);

  printf("SELECTIONSORT:\n");
  selectionSort(array, n);
  printf("\n");
  pause();

  preencheArray(array);

  printf("INSERTIONSORT:\n");
  insertionSort(array, n);
  printf("\n");

  return 0;
}

void bubbleSort(int *arr, int n)
{
  int troca;
  for (int i = 0; i < n; i++)
  {
    troca = 0;
    for (int j = 1; j < (n - i); j++)
    {
      if (arr[j] < arr[j - 1])
      {
        int aux = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = aux;
        troca += 1;
      }
    }
    if (troca == 0)
      break;
    printArray(arr, n, i);
  }
}

void selectionSort(int *arr, int n)
{
  int min;
  for (int i = 0; i < n; i++)
  {
    min = i;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[min])
        min = j;
    }
    if (i != min)
    {
      int aux = arr[i];
      arr[i] = arr[min];
      arr[min] = aux;
    }
    printArray(arr, n, i);
  }
}

void insertionSort(int *arr, int n)
{
  int aux, j;
  for (int i = 1; i < n; i++)
  {
    aux = arr[i];
    j = i - 1;
    while (j >= 0 && aux < arr[j])
    {
      arr[j + 1] = arr[j];
      j -= 1;
    }
    arr[j + 1] = aux;
    printArray(arr, n, i - 1);
  }
}

void printArray(int *arr, int n, int pass)
{
  printf("Passo %d: ", pass);
  pass += 1;

  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void preencheArray(int *arr)
{
  arr[0] = 4;
  arr[1] = 7;
  arr[2] = 6;
  arr[3] = 2;
  arr[4] = 10;
  arr[5] = 0;
}

void pause()
{
  printf("Press Any Key to Continue\n");
  getchar();
}
