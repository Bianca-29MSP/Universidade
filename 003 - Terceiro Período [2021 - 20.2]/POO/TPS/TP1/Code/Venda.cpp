#include "Venda.hpp"

static int _id = 0;

Venda::Venda(Produto &produto, float valor, int idVendedor) : produto(produto), isProduto(true), idVendedor(idVendedor)
{
  setId();
};

Venda::Venda(Servico &servico, float valor, int idVendedor) : servico(servico), isProduto(false), idVendedor(idVendedor)
{
  setId();
};

Venda::~Venda(){};

void Venda::setId()
{
  this->id = _id++;
}

void Venda::setIsProduto(bool isProduto)
{
  this->isProduto = isProduto;
}

void Venda::setValor(float valor)
{
  this->valor = valor;
}

void Venda::setIdVendedor(int idVendedor)
{
  this->idVendedor = idVendedor;
}

void Venda::setProduto(Produto &produto)
{
  this->produto = produto;
}

void Venda::setServico(Servico &servico)
{
  this->servico = servico;
}

int Venda::getId() const
{
  return id;
}

bool Venda::getIsProduto() const
{
  return isProduto;
}

float Venda::getValor() const
{
  return valor;
}

int Venda::getIdVendedor() const
{
  return idVendedor;
}

Produto Venda::getProduto() const
{
  return produto;
}

Servico Venda::getServico() const
{
  return servico;
}

ostream &operator<<(ostream &out, const Venda &venda)
{
  if (venda.getIsProduto())
  { //Saída para quando o cliente comprar algum produto
    out << "ID: " << venda.getId() << endl
        << "Produto" << endl
        << venda.getProduto() << endl
        << "ID vendedor: " << venda.getIdVendedor() << endl
        << "Valor: " << fixed << setprecision(2) << venda.getValor() << endl;
  }
  else
  { //Saída para quando o cliente quiser algum dos serviços ofertados (Banho e tosa ou Consulta)
    out << "ID: " << venda.getId() << endl
        << "Servico" << endl
        << venda.getServico() << endl
        << "ID vendedor: " << venda.getIdVendedor() << endl
        << "Valor: " << fixed << setprecision(2) << venda.getValor() << endl;
  }

  return out;
}
