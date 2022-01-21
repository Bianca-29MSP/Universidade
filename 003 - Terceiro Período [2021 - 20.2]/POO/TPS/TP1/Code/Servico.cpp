#include "Servico.hpp"

static int _id = 0;

Servico::Servico(string nome, float valor) : nome(nome), valor(valor)
{
  setId();
};

Servico::~Servico(){};

int Servico::getId() const
{
  return id;
}

string Servico::getNome() const
{
  return nome;
}

float Servico::getValor() const
{
  return valor;
}

void Servico::setId()
{
  this->id = _id++;
}

void Servico::setNome(string nome)
{
  this->nome = nome;
}

void Servico::setValor(float valor)
{
  this->valor = valor;
}

ostream &operator<<(ostream &out, const Servico &servico)
{
  out << "ID: " << servico.getId() << "  |  "
      << "Nome: " << servico.getNome() << "  |  "
      << "Valor: " << fixed << setprecision(2) << servico.getValor();
  return out;
}
