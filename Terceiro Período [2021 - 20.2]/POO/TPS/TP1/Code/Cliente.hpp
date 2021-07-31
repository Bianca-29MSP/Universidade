#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>

using namespace std;

class Cliente
{
    int id;
    string nome, endereco;

public:
    Cliente(string = "", string = "");
    ~Cliente();

    void setId();
    void setNome(string);
    void setEndereco(string);
    int getId() const;
    string getNome() const;
    string getEndereco() const;
    friend ostream &operator<<(ostream &, const Cliente &);
};

#endif