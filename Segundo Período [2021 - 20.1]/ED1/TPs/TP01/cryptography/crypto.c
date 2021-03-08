#include "crypto.h"

void crypto(char *word)
{
  int stringLength = strlen(word) - 1;
  firstStep(word, stringLength);
  secondyStep(word, 0, stringLength);
  lastStep(word, stringLength, ((stringLength + 1) / 2));
}

bool isLetter(char letter)
{
  if (((int)letter >= 97 && (int)letter <= 122) ||
      ((int)letter >= 65 && (int)letter <= 90))
    return true;
  return false;
}

void swap(char *a, char *b)
{
  char aux = *a;
  *a = *b;
  *b = aux;
}

void firstStep(char *word, int length) //O(n)
{
  if (length >= 0)
  {
    if (!isLetter(word[length]))
      firstStep(word, length - 1);
    else
    {
      word[length] = word[length] + 3;
      firstStep(word, length - 1);
    }
  }
}

//['h', 'e', 'l', 'l', 'o']

void secondyStep(char *word, int left, int right) //O(n)
{
  if (left < right)
  {
    swap(&word[left], &word[right]);
    secondyStep(word, left + 1, right - 1);
  }
}

void lastStep(char *word, int length, int n) //O(n)
{
  if (n <= length)
  {
    word[n] = word[n] - 1;
    lastStep(word, length, (n + 1));
  }
}