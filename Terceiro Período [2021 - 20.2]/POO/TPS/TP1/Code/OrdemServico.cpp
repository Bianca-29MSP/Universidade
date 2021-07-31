#include "OrdemServico.hpp"
#include "Estilos.hpp"

static int _id = 0;
//Constructor para quando o cliente possui cadastro
OrdemServico::OrdemServico(Servico &servico, DataHorario &datatime, Cliente &cliente, string animal)
    : servico(servico), datatime(datatime), cliente(cliente), animal(animal)
{
  setId();
  setNomeCliente("-");
};
//Constructor para quando o cliente não possui cadastro
OrdemServico::OrdemServico(Servico &servico, DataHorario &datatime, string nomeCliente, string animal)
    : servico(servico), datatime(datatime), nomeCliente(nomeCliente), animal(animal)
{
  setId();
};

OrdemServico::~OrdemServico(){};

int OrdemServico::getId() const
{
  return this->id;
}

string OrdemServico::getAnimal() const
{
  return this->animal;
}

DataHorario OrdemServico::getDatatime() const
{
  return this->datatime;
}

Cliente OrdemServico::getCliente() const
{
  return this->cliente;
}

Servico OrdemServico::getServico() const
{
  return this->servico;
}

string OrdemServico::getRelatorio() const
{
  return this->relatorio;
}

string OrdemServico::getNomeCliente() const
{
  return this->nomeCliente;
}

void OrdemServico::setId()
{
  this->id = _id++;
}

void OrdemServico::setServico(Servico &servico)
{
  this->servico = servico;
}

void OrdemServico::setAnimal(string animal)
{
  this->animal = animal;
}

void OrdemServico::setDatatime(DataHorario &datatime)
{
  this->datatime = datatime;
}

void OrdemServico::setRelatorio(string relatorio)
{
  this->relatorio = relatorio;
}

void OrdemServico::setNomeCliente(string nomeCliente)
{
  this->nomeCliente = nomeCliente;
}

bool OrdemServico::realizarVenda()
{
  return true;
}

bool OrdemServico::realizarOrdemServico()
{
  return true;
}

ostream &operator<<(ostream &out, const OrdemServico &ordemServico)
{

  if (ordemServico.getNomeCliente() == "-")
  { //saída para quando o cliente possui cadastro
    out << "ID: " << ordemServico.getId() << endl
        << FONT_COLOR_PRIMARY << "Cliente\n"
        << RESET_COLOR
        << ordemServico.getCliente() << endl
        << FONT_COLOR_PRIMARY << "Serviço\n"
        << RESET_COLOR
        << ordemServico.getServico() << endl
        << "Animal: " << ordemServico.getAnimal() << endl
        << "Data: " << ordemServico.getDatatime() << endl
        << "Relatório: " << ordemServico.getRelatorio();
  }
  else
  { //saída para quando o cliente não possui cadastro
    out << "ID: " << ordemServico.getId() << endl
        << FONT_COLOR_PRIMARY << "Cliente\n"
        << RESET_COLOR
        << ordemServico.getNomeCliente() << endl
        << FONT_COLOR_PRIMARY << "Serviço\n"
        << RESET_COLOR
        << ordemServico.getServico() << endl
        << "Animal: " << ordemServico.getAnimal() << endl
        << "Data: " << ordemServico.getDatatime() << endl
        << "Relatório: " << ordemServico.getRelatorio();
  }

  return out;
}
