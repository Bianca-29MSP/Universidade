#ifndef DATAHORARIO_H
#define DATAHORARIO_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class DataHorario
{
    int dia, mes, ano, hora, minuto;

public:
    DataHorario(int = 0, int = 0, int = 0, int = 0, int = 0);
    ~DataHorario();

    void setDia(int);
    void setMes(int);
    void setAno(int);
    void setHora(int);
    void setMinuto(int);
    int getDia() const;
    int getMes() const;
    int getAno() const;
    int getHora() const;
    int getMinuto() const;

    friend ostream &operator<<(ostream &, const DataHorario &);
};

#endif