#ifndef ORDEMSERVICO_H
#define ORDEMSERVICO_H

#include <string>
#include <iostream>
#include <iomanip>
#include "Servico.hpp"
#include "DataHorario.hpp"
#include "Cliente.hpp"

using namespace std;

class OrdemServico
{
private:
  int id;
  Servico servico;
  DataHorario datatime;
  Cliente cliente;
  string nomeCliente;
  string animal;
  string relatorio;

public:
  OrdemServico(Servico &, DataHorario &, Cliente &, string = "");
  OrdemServico(Servico &, DataHorario &, string = "", string = "");
  ~OrdemServico();
  int getId() const;

  string getAnimal() const;
  DataHorario getDatatime() const;
  Servico getServico() const;
  Cliente getCliente() const;
  string getRelatorio() const;
  string getNomeCliente() const;

  void setId();
  void setServico(Servico &);
  void setAnimal(string animal);
  void setDatatime(DataHorario &);
  void setRelatorio(string relatorio);
  void setNomeCliente(string nomeCliente);

  bool realizarVenda();
  bool realizarOrdemServico();

  friend ostream &operator<<(ostream &, const OrdemServico &);
};

#endif