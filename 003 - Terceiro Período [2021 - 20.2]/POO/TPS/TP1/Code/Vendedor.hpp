#ifndef VENDEDOR_H
#define VENDEDOR_H

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

#include "Usuario.hpp"
#include "Cliente.hpp"
#include "Produto.hpp"
#include "Servico.hpp"
#include "OrdemServico.hpp"
#include "Login.hpp"
#include "Venda.hpp"

using namespace std;

class Vendedor : virtual public Usuario
{
public:
  Vendedor(string = "", string = "", string = "", float = 0.0);
  ~Vendedor();

  Cliente getClienteById(vector<Cliente> &, int, bool &);
  void visualizarCliente(vector<Cliente> &);
  void visualizarProdutos(vector<Produto> &);
  bool cadastrarCliente(vector<Cliente> &, Cliente &);
  bool realizarVenda(vector<Produto> &, vector<Venda> &, int, int);
  bool realizarOrdemServico(vector<OrdemServico> &, vector<Venda> &, Servico &, OrdemServico &);
  Vendedor &verificarLogin(vector<Vendedor> &, string, string);
};

#endif