#include <iostream>
#include "Ponto.h"

using namespace std;

int main()
{
  Ponto P(2, 3), P2(P), P3;
  P.print();
  P++;
  P.print();
  P3 = P + P2;
  P3.print();
  P3 = P;
  if (P3 == P)
    cout << "Iguais" << endl;
  else
    cout << "Dififerentes" << endl;
  return 0;
}