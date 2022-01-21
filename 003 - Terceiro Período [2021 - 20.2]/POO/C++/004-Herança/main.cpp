#include <iostream>
#include "Gerente.h"

using namespace std;

int main()
{
  Gerente gerente("Geraldo Sion", 30000.00, "gsion", "senh4");
  cout << gerente;
  cout << "\n Bonificacao: " << gerente.calculaBonificacao() << endl;
  return 0;
}