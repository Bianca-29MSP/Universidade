#include <iostream>
#include <string>

using namespace std;

class Circulo
{
private:
  double x, y, raio;

public:
  Circulo()
  {
    setPonto(0.0, 0.0);
    setRaio(0.0);
  }

  Circulo(double raio)
  {
    setPonto(0.0, 0.0);
    setRaio(raio);
  }

  Circulo(double x, double y)
  {
    setPonto(x, y);
    setRaio(0.0);
  }

  ~Circulo(){};

  void setPonto(double x, double y)
  {
    this->x = x;
    this->y = y;
  }

  void setRaio(double raio)
  {
    this->raio = raio;
  }

  void mover(double delta_x, double delta_y)
  {
    this->x = delta_x;
    this->y = delta_y;
  }

  void aumentar(double delta_r)
  {
    this->raio = delta_r;
  }

  void mostrar()
  {
    cout << "(" << x << ", " << y << ")" << endl
         << "r: " << raio << endl;
  }
};

int main()
{
  Circulo A, B(10), C(3, 5);
  A.mostrar();
  B.mostrar();
  C.mostrar();
  cin.get();
  return 0;
}