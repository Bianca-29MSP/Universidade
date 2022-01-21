
#include "vetor_util.h"

int buscaSequencial(int *vetor, int n, int elemento)
{
  for (int i = 0; i < n; i++)
  {
    if (vetor[i] == elemento)
      return i;
  }
  return -1;
};

int buscaBinaria(int *vetor, int n, int elemento)
{
  int metade = n / 2;
  int vetorMetade = vetor[metade];
  int final = n;

  while (elemento != vetorMetade && metade > 0 && metade < (n - 1))
  {
    if (elemento < vetorMetade)
    {
      final = metade;
      metade = metade / 2;
    }
    else if (elemento > vetorMetade)
      metade += (final - metade) / 2;

    vetorMetade = vetor[metade];
  }

  if ((metade <= 0 && elemento != vetorMetade) ||
      (metade >= (n - 1) && elemento != vetorMetade))
    return -1;
  else
    return metade;
};

int *intercalaVetoresOrdenados(int *nums1, int nums1Tam, int *nums2, int nums2Tam)
{
  int numsTam = nums1Tam + nums2Tam;
  int *vetor = (int *)malloc(numsTam * sizeof(int));

  int minVetTam = nums1Tam <= nums2Tam ? nums1Tam : nums2Tam;

  int j = 0;
  for (int i = 0; i < numsTam; i += 2)
  {
    if (j < minVetTam)
    {
      if (nums1[j] < nums2[j])
      {
        vetor[i] = nums1[j];
        vetor[i + 1] = nums2[j];
      }
      else if (nums1[j] > nums2[j])
      {
        vetor[i] = nums2[j];
        vetor[i + 1] = nums1[j];
      }
      else
      {
        vetor[i] = nums1[j];
        vetor[i + 1] = nums2[j];
      }
    }
    else
    {
      if (nums1Tam >= nums2Tam)
      {
        vetor[i] = nums1[j];
        vetor[i + 1] = nums1[j + 1];
      }
      else
      {
        vetor[i] = nums2[j];
        vetor[i + 1] = nums2[j + 1];
      }
    }
    j++;
  }

  return vetor;
};

int comparaVetores(int *nums1, int *nums2, int nums1Tam, int nums2Tam)
{
  if (nums1Tam != nums2Tam)
    return 0;

  if (nums1Tam == 0 && nums2Tam == 0)
    return 1;

  int count = 0;

  for (int i = 0; i < nums1Tam; i++)
      if (nums1[i] == nums2[i])
        count++;

  if (count == nums1Tam)
    return 1;

  return 0;
};