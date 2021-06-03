#include <iostream>
#include <string>

using namespace std;

class Retangulo
{
private:
  double altura;
  double base;

public:
  void setAltura(double m_altura)
  {
    altura = m_altura;
  }

  void setBase(double m_base)
  {
    base = m_base;
  }

  double getAltura() const
  {
    return altura;
  }

  double getBase() const
  {
    return base;
  }

  double calcularArea()
  {
    return getAltura() * getBase();
  }

  double calcularPerimetro()
  {
    return 2 * getAltura() + 2 * getBase();
  }
};

int main()
{
  Retangulo R;
  double m_base, m_altura;
  cout << "Digite a base e a altura do retangulo: ";
  cin >> m_base >> m_altura;
  R.setBase(m_base);
  R.setAltura(m_altura);
  cout << "Area: " << R.calcularArea() << endl;
  cout << "Perimetro: " << R.calcularPerimetro() << endl;
  return 0;
}