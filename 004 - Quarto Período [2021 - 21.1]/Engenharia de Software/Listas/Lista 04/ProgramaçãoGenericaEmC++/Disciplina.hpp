#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <iostream>

using namespace std;

class Disciplina {
    private:
        string departamento;
        string nome;
        string codigo;
        int vagasTotal;
        int vagasDisponiveis;
        int vagasOcupadas;

    public:
        Disciplina(void);
        Disciplina(string departamento, string nome, string codigo, int vagasTotal, int vagasOcupadas);
        string getDepartamento() const;
        void setDepartamento(string departamento);
        string getNome() const;
        void setNome(string nome);
        string getCodigo() const;
        void setCodigo(string codigo);
        int getVagasTotal() const;
        void setVagasTotal(int vagasTotal);
        int getVagasDisponiveis() const;
        void setVagasDisponiveis(int vagasDisponiveis);
        int getVagasOcupadas() const;
        void setVagasOcupadas(int vagasOcupadas);
        float operator+(Disciplina aux);
        float operator+(int n);
        float operator+(float n);
        bool operator==(string str);
};

Disciplina::Disciplina(void){}

Disciplina::Disciplina(string departamento, string nome, string codigo, int vagasTotal, int vagasOcupadas){
    setDepartamento(departamento);
    setNome(nome);
    setCodigo(codigo);
    setVagasTotal(vagasTotal);
    setVagasOcupadas(vagasOcupadas);
    setVagasDisponiveis(vagasTotal - vagasOcupadas);
}

string Disciplina::getDepartamento() const
{
    return this->departamento;
}

void Disciplina::setDepartamento(string departamento)
{
    this->departamento = departamento;
}

string Disciplina::getNome() const
{
    return this->nome;
}

void Disciplina::setNome(string nome)
{
    this->nome = nome;
}

string Disciplina::getCodigo() const
{
    return this->codigo;
}

void Disciplina::setCodigo(string codigo)
{
    this->codigo = codigo;
}

int Disciplina::getVagasTotal() const
{
    return this->vagasTotal;
}

void Disciplina::setVagasTotal(int vagasTotal)
{
    this->vagasTotal = vagasTotal;
}

int Disciplina::getVagasDisponiveis() const
{
    return this->vagasDisponiveis;
}

void Disciplina::setVagasDisponiveis(int vagasDisponiveis)
{
    this->vagasDisponiveis = vagasDisponiveis;
}

int Disciplina::getVagasOcupadas() const
{
    return this->vagasOcupadas;
}

void Disciplina::setVagasOcupadas(int vagasOcupadas)
{
    this->vagasOcupadas = vagasOcupadas;
}

float Disciplina::operator+(Disciplina aux){
    return this->vagasDisponiveis + aux.vagasDisponiveis;
}

float Disciplina::operator+(int n){
    return this->vagasDisponiveis + n;
}

float Disciplina::operator+(float n){
    return this->vagasDisponiveis + n;
}

bool Disciplina::operator==(string str){
    return (this->codigo == str || this->nome == str || this->departamento == str);
}

#endif
