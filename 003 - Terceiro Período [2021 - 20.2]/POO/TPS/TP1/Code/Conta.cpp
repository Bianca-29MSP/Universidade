#include "Conta.hpp"
#include <ctime>

static int _id = 0;

Conta::Conta(DataHorario &dataVenc, string descricao, float valor) : dataVenc(dataVenc), descricao(descricao), valor(valor)
{
    this->setId();
    this->estaPaga = false;
}
Conta::~Conta(){};

void Conta::setId()
{
    this->id = _id++;
}

void Conta::setDescricao(string descricao)
{
    this->descricao = descricao;
}

void Conta::setValor(float valor)
{
    this->valor = valor;
}

void Conta::setEstaPaga()
{
    this->estaPaga = true;
}

int Conta::getId() const
{
    return id;
}

//Define a hora de pagamento tendo como base a hora atual
void Conta::setDataPagto()
{
    //set Hora atual
    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);

    DataHorario dataPagto(local_time->tm_mday, (1 + local_time->tm_mon), (1900 + local_time->tm_year), (local_time->tm_hour), (local_time->tm_min));
    this->dataPagto = dataPagto;
}

void Conta::setDataVenc(DataHorario dataVenc)
{
    this->dataVenc = dataVenc;
}

string Conta::getDescricao() const
{
    return this->descricao;
}

DataHorario Conta::getDataVenc() const
{
    return this->dataVenc;
}

DataHorario Conta::getDataPagto() const
{
    return this->dataPagto;
}

float Conta::getValor() const
{
    return this->valor;
}

bool Conta::getEstaPaga() const
{
    return this->estaPaga;
}

ostream &operator<<(ostream &out, const Conta &conta)
{
    out << "ID: " << conta.getId() << endl
        << "Descrição: " << conta.getDescricao() << endl
        << "Data de Pagamento: " << conta.getDataPagto() << endl
        << "Data de vencimento: " << conta.getDataVenc() << endl
        << "Valor: " << fixed << setprecision(2) << conta.getValor() << endl
        << "Situacao atual: " << (conta.getEstaPaga() ? "Paga" : "À pagar");
    return out;
}
