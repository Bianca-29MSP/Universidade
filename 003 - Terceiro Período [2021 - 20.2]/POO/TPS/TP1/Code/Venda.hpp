#ifndef VENDA_HPP
#define VENDA_HPP

#include <iostream>
#include <string>
#include <iomanip>

#include "Produto.hpp"
#include "Servico.hpp"

using namespace std;

class Venda
{
  int id;
  Produto produto;
  Servico servico;
  bool isProduto;
  float valor;
  int idVendedor;

public:
  Venda(Produto &, float = 0.0, int = 0);
  Venda(Servico &, float = 0.0, int = 0);
  ~Venda();

  void setId();
  void setIsProduto(bool);
  void setValor(float);
  void setIdVendedor(int);
  void setProduto(Produto &);
  void setServico(Servico &);

  int getId() const;
  bool getIsProduto() const;
  float getValor() const;
  int getIdVendedor() const;
  Produto getProduto() const;
  Servico getServico() const;

  friend ostream &operator<<(ostream &, const Venda &);
};

#endif