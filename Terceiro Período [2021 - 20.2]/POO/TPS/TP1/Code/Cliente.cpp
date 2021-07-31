#include "Cliente.hpp"

static int _id = 0;

Cliente::Cliente(string nome, string endereco) : nome(nome), endereco(endereco)
{
    setId();
}

Cliente ::~Cliente(){};

void Cliente::setId()
{
    this->id = _id++;
}

void Cliente::setNome(string nome)
{
    this->nome = nome;
}

void Cliente::setEndereco(string endereco)
{
    this->endereco = endereco;
}

int Cliente::getId() const
{
    return id;
}

string Cliente::getNome() const
{
    return nome;
}

string Cliente::getEndereco() const
{
    return endereco;
}

ostream &operator<<(ostream &out, const Cliente &cliente)
{
    out << "ID: " << cliente.getId() << endl
        << "Nome: " << cliente.getNome() << endl
        << "Endereço: " << cliente.getEndereco();
    return out;
}
