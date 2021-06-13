#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Funcionario
{
  string nome;
  float salario;

public:
  Funcionario(string = "", double = 0.0);
  ~Funcionario();
  string getNome() const;
  void setNome(string);
  float getSalario() const;
  void setSalario(float);
  double calculaBonificacao();
  friend ostream &operator<<(ostream &, const Funcionario &);
};

#endif
