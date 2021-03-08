
#include "vetor_util.h"

int main(void)
{
  // ------------------------1 & 2----------------------------- //

  //int vetor[8] = {2,4,5,6,7,8,10,9};
  //int vetor[4] = {-1, 0, 3, 5};
  //int vetor[4] = {1, 2, 3, 4};
  //int vetor[8] = {2, 4, 5, 6, 7, 8, 9, 10};
  int vetor[0] = {};

  int n;
  int elemento;
  int resultado;

  printf("n = ");
  scanf("%d", &n);

  printf("elemento = ");
  scanf("%d", &elemento);

  //resultado = buscaSequencial(vetor, n ,elemento);
  resultado = buscaBinaria(vetor, n, elemento);

  printf("%d\n", resultado);

  // ----------------------------3------------------------- //

  // int nums1[4] = {1,3,5,7};
  // int nums2[4] = {0,2,4,6};

  // int nums1Tam = 4;
  // int nums2Tam = 4;

  // int nums1[0] = {};
  // int nums2[2] = {1,2};

  // int nums1Tam = 0;
  // int nums2Tam = 2;

  // int numsTam = nums1Tam + nums2Tam;
  // int * vetor = (int *) malloc(numsTam * sizeof(int));

  // vetor = intercalaVetoresOrdenados(nums1, nums1Tam, nums2, nums2Tam);

  // for (int i = 0; i < numsTam; i++)
  // 	printf("%d ", vetor[i]);
  // printf("\n");

  //free(vetor);

  // -------------------------------4---------------------- //

  // int nums1[4] = {1,3,5,7};
  // int nums1Tam = 4;
  // int nums2[3] = {1,3,5};
  // int nums2Tam = 3;

  // int nums1[0] = {};
  // int nums1Tam = 0;
  // int nums2[0] = {};
  // int nums2Tam = 0;

  // int r = comparaVetores(nums1, nums2, nums1Tam, nums2Tam);
  // printf("%d\n", r);

  return 0;
}