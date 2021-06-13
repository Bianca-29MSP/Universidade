#include "Gerente.h"

Gerente::Gerente(string nome, double salario, string usuario, string senha) : Funcionario(nome, salario), usuario(usuario), senha(senha) {}
Gerente::~Gerente() {}

string Gerente::getUsuario() const
{
  return usuario;
}

void Gerente::setUsuario(string usuario)
{
  this->usuario = usuario;
}

string Gerente::getSenha() const
{
  return senha;
}

void Gerente::setSenha(string senha)
{
  this->senha = senha;
}

double Gerente::calculaBonificacao()
{
  return getSalario() * 0.6 + 100;
}

ostream &operator<<(ostream &out, const Gerente &gerente)
{
  out << "\n nome: " << gerente.getNome()
      << "\n salario: " << gerente.getSalario()
      << "\n usuario: " << gerente.usuario;
  return out;
}