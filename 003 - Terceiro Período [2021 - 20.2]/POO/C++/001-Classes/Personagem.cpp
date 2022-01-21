#include <iostream>
#include <string>

using namespace std;

class Personagem
{
private:
  string nome;
  string classe;
  int idade;
  int vida;
  int forca;
  int mana;

public:
  string getNome() const
  {
    return nome;
  }

  string getClasse() const
  {
    return classe;
  }

  int getIdade() const
  {
    return idade;
  }

  int getVida() const
  {
    return vida;
  }

  int getForca() const
  {
    return forca;
  }

  int getMana() const
  {
    return mana;
  }

  void setNome(string nome)
  {
    this->nome = nome;
  }

  void setClasse(string classe)
  {
    this->classe = classe;
  }

  void setIdade(int idade)
  {
    this->idade = idade;
  }

  void setVida(int vida)
  {
    this->vida = vida;
  }

  void setForca(int forca)
  {
    this->forca = forca;
  }

  void setMana(int mana)
  {
    this->mana = mana;
  }

  void atingido(int dano)
  {
    if (dano > 0)
      setVida(this->vida - dano);
  }

  void curar(int vida)
  {
    if (vida > 0)
      setVida(this->vida + 50);
  }

  int atingir()
  {
    if (mana >= 20)
    {
      setMana(mana - 20);
      return getForca();
    }
    else
    {
      return 0;
    }
  }

  void tomarPotMana()
  {
    setMana(mana + 30);
  }
};

int main()
{
  Personagem danta;
  danta.setNome("Danta");
  danta.setClasse("Feiticeira");
  danta.setIdade(27);
  danta.setVida(500);
  danta.setForca(50);
  danta.setMana(100);

  danta.atingido(50);
  cout << danta.getVida() << "\n";
  return 0;
}