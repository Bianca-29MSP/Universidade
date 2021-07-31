#ifndef CONTA_H
#define CONTA_H

#include <iostream>
#include <string>
#include <iomanip>

#include "DataHorario.hpp"

using namespace std;

class Conta
{
    DataHorario dataVenc, dataPagto;
    string descricao;
    float valor;
    int id;
    bool estaPaga;

public:
    Conta(DataHorario &, string = "", float = 0.0);
    ~Conta();

    void setId();
    void setDataVenc(DataHorario);
    void setDataPagto();
    void setDescricao(string);
    void setValor(float);
    void setEstaPaga();

    int getId() const;
    DataHorario getDataVenc() const;
    DataHorario getDataPagto() const;
    string getDescricao() const;
    float getValor() const;
    bool getEstaPaga() const;

    friend ostream &operator<<(ostream &out, const Conta &conta);
};

#endif