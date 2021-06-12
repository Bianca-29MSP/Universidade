#include <iostream>
#include <string>

using namespace std;

class Rec
{
private:
  static int n;

public:
  Rec() { n++; }
  ~Rec() { n--; }

  int getRec()
  {
    return n;
  }
};

int Rec::n = 0; //Inicializando o atributo estático da classe

int main()
{
  Rec r1, r2, r3;
  cout << r1.getRec() << endl;
  {
    //somente existe dentro desse bloco
    Rec r4, r5, r6;
    cout << r1.getRec() << endl;
  }
  cout << r1.getRec() << endl;
  return 0;
}