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
  //Por padrão se nn definir como public, será private
  //Atributos
  string placa;
  int velocidade;

public:
  //Construtores
  Carro()
  {
    placa = "";
    velocidade = 0;
  }

  Carro(string placa, int velocidade)
  {
    this->placa = placa;
    this->velocidade = velocidade;
  }

  /*
    Exemplos:
      Ponto(){ x = y = 0.0; }
      Ponto(){ this->x = 0.0; this->y = 0.0;}
      Ponto(): x(0.0), y(0.0){}

      Vendas(int p = -1, float v = -1.0) { // Valores por default
        valor = v;
        pecas = p;
      }
  */

  //Destrutores
  ~Carro(){};

  //Métodos
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

  void mostrarDados()
  {
    cout << "Placa: " << getVelocidade() << endl
         << "Velocidade: " << getVelocidade() << "Km/h. \n";
  }
};

int main()
{
  //Instanciando um objeto da classe Carro
  Carro herbie, herbie2("HTS-5882", 50); //Objeto
  herbie.mostrarDados();
  herbie2.mostrarDados();
  // herbie.setPlaca("GDH-5621");
  // herbie.setVelocidade(20);
  // herbie.acelerar();
  // herbie.mostrarVelocidade();
  // herbie.acelerar();
  // herbie.mostrarVelocidade();
  // herbie.freiar();
  // herbie.mostrarVelocidade();
  // cout << herbie.getPlaca() << "\n";
  return 0;
}
