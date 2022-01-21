#ifndef SERVICO_H
#define SERVICO_H

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Servico
{
private:
  int id;
  string nome;
  float valor;

public:
  Servico(string = "", float = 0.0);
  ~Servico();

  int getId() const;
  string getNome() const;
  float getValor() const;

  void setId();
  void setNome(string);
  void setValor(float);
  friend ostream &operator<<(ostream &, const Servico &);
};

#endif