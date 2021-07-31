#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Produto
{
    int id, quantidade;
    float valor;
    string nome;
    string animal;

public:
    Produto(int = 0, float = 0.0, string = "", string = "");
    ~Produto();

    void setId();
    void setQuantidade(int);
    void setValor(float);
    void setNome(string);
    void setAnimal(string);

    int getId() const;
    int getQuantidade() const;
    float getValor() const;

    string getNome() const;
    string getAnimal() const;

    bool atualizarQuantidade(int);

    friend ostream &operator<<(ostream &out, const Produto &produto);
};

#endif