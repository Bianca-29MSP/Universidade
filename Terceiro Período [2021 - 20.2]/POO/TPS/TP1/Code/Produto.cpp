#include "Produto.hpp"

static int _id = 0;

Produto::Produto(int quantidade, float valor, string nome, string animal)
    : quantidade(quantidade), valor(valor), nome(nome), animal(animal)
{
    setId();
};

Produto::~Produto(){};

void Produto::setId()
{
    this->id = _id++;
}

void Produto::setQuantidade(int quantidade)
{
    this->quantidade = quantidade;
}

void Produto::setValor(float valor)
{
    this->valor = valor;
}

void Produto::setNome(string nome)
{
    this->nome = nome;
}

void Produto::setAnimal(string animal)
{
    this->animal = animal;
}

int Produto::getId() const
{
    return id;
}

int Produto::getQuantidade() const
{
    return quantidade;
}

float Produto::getValor() const
{
    return valor;
}

string Produto::getNome() const
{
    return nome;
}

string Produto::getAnimal() const
{
    return animal;
}

bool Produto::atualizarQuantidade(int quantidade)
{
    if ((getQuantidade() - quantidade) >= 0)
    { //verifica se a nova quantidade no produto não será negativo
        setQuantidade(getQuantidade() - quantidade);
        return true;
    }
    else
        return false;
}

ostream &operator<<(ostream &out, const Produto &produto)
{
    out << "ID: " << produto.getId() << "  |  "
        << "Nome: " << produto.getNome() << "  |  "
        << "Quantidade: " << produto.getQuantidade() << "  |  "
        << "Valor: " << fixed << setprecision(2) << produto.getValor();
    return out;
}
