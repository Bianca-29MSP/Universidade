#include "Funcionario.h"

Funcionario::Funcionario(string nome, double salario) : nome(nome), salario(salario){};

Funcionario::~Funcionario(){};

string Funcionario::getNome() const
{
  return nome;
}

void Funcionario::setNome(string nome)
{
  this->nome = nome;
}

float Funcionario::getSalario() const
{
  return salario;
}

void Funcionario::setSalario(float salario)
{
  if (salario > 0)
    this->salario = salario;
  else
    this->salario = 0.0;
}

double Funcionario::calculaBonificacao()
{
  return getSalario() * 0.1;
}

ostream &operator<<(ostream &out, const Funcionario &funcionario)
{
  out << "\n nome:" << funcionario.nome
      << "\n salario:" << fixed
      << setprecision(2) << funcionario.salario;
  return out;
}
