#include "DataHorario.hpp"
#include <ctime>

DataHorario::DataHorario(int dia, int mes, int ano, int hora, int minuto)
{
    setDia(dia);
    setMes(mes);
    setAno(ano);
    setHora(hora);
    setMinuto(minuto);
};

DataHorario ::~DataHorario(){};

void DataHorario::setDia(int dia)
{   //Validação do dia
    if (dia > 31)
        this->dia = 31;
    else
        this->dia = dia;
}

void DataHorario::setMes(int mes)
{   //Validação do mês
    if (mes > 12)
        this->mes = 12;
    else
        this->mes = mes;
}

void DataHorario::setAno(int ano)
{   
    //Validação do ano com base no ano atual
    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);
    int anoAtual = (1900 + local_time->tm_year);
    if (ano < anoAtual)
        this->ano = anoAtual;
    else
        this->ano = ano;
}

void DataHorario::setHora(int hora)
{   //Validação da hora
    if (hora > 23)
        this->hora = 0;
    else
        this->hora = hora;
}

void DataHorario::setMinuto(int minuto)
{   //Validação do minuto
    if (minuto > 59)
        this->minuto = 59;
    else
        this->minuto = minuto;
}

int DataHorario::getDia() const
{
    return dia;
}

int DataHorario::getMes() const
{
    return mes;
}

int DataHorario::getAno() const
{
    return ano;
}

int DataHorario::getHora() const
{
    return hora;
}

int DataHorario::getMinuto() const
{
    return minuto;
}

ostream &operator<<(ostream &out, const DataHorario &dataHorario)
{
    if (dataHorario.getDia() == 0 && dataHorario.getMes() == 0 && dataHorario.getHora() == 0 && dataHorario.getMinuto() == 0)
    {
        out << "Data ainda não registrada.";
    }
    else
    {
        out << dataHorario.getDia() << "/"
            << dataHorario.getMes() << "/"
            << dataHorario.getAno() << "  "
            << dataHorario.getHora() << ":"
            << dataHorario.getMinuto();
    }
    return out;
}
