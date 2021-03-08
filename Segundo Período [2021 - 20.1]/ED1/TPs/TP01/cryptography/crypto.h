#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void crypto(char *word);

bool isLetter(char letter);

void swap(char *a, char *b);

void firstStep(char *word, int length);

void secondyStep(char *word, int left, int right);

void lastStep(char *word, int length, int n);
