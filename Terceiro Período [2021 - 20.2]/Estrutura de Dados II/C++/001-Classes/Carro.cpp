/*
Carro
----------------
- placa: string
- velocidade: int
----------------
+ acelerar():void
+ freiar():void
+ set(plac: string, velo:int):void
+ mostrarVelocidade():void
*/
#include <iostream>
#include <string>

using namespace std;

class Carro
{
  //Ppor padrão se nn definir como public, será private
  string placa;
  int velocidade;

public:
  void acelerar()
  {
    velocidade += 10;
  }

  void freiar()
  {
    velocidade -= 10;
  }

  void setPlaca(string mplaca)
  {
    placa = mplaca;
  }

  void setVelocidade(int mvelo)
  {
    if (mvelo >= 0)
      velocidade = mvelo;
  }

  string getPlaca() const //const -> não permite operações de escrita nos atributos desse metodo
  {
    return placa;
  }

  int getVelocidade() const
  {
    return velocidade;
  }

  void mostrarVelocidade()
  {
    cout << getVelocidade() << "Km/h. \n";
  }
};

int main()
{
  //Instanciando um objeto da classe Carro
  Carro herbie; //Objeto
  herbie.setPlaca("GDH-5621");
  herbie.setVelocidade(20);
  herbie.acelerar();
  herbie.mostrarVelocidade();
  herbie.acelerar();
  herbie.mostrarVelocidade();
  herbie.freiar();
  herbie.mostrarVelocidade();
  cout << herbie.getPlaca() << "\n";
  return 0;
}
