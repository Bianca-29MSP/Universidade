#ifndef ESTUDANTE_H
#define ESTUDANTE_H

#include <iostream>

using namespace std;

class Estudante {
    private:
        string nome;
        string curso;
        int matricula;
        float coeficiente;

    public:
    Estudante(void);
    Estudante(string nome, string curso, int matricula, float coeficiente = 0);

    string getNome() const;
    void setNome(string nome);
    string getCurso() const;
    void setCurso(string curso);
    int getMatricula() const;
    void setMatricula(int matricula);
    int getCoeficiente() const;
    void setCoeficiente(int coeficiente);
    float operator+(Estudante aux);
    float operator+(float n);
    bool operator==(string str);
    bool operator==(int matricula);
    bool operator==(float coef);
};


Estudante::Estudante(void){}

Estudante::Estudante(string nome, string curso, int matricula, float coeficiente){
    setNome(nome);
    setCurso(curso);
    setMatricula(matricula);
    setCoeficiente(coeficiente);
}

string Estudante::getNome() const
{
    return this->nome;
}


void Estudante::setNome(string nome)
{
    this->nome = nome;
}


string Estudante::getCurso() const
{
    return this->curso;
}


void Estudante::setCurso(string curso)
{
    this->curso = curso;
}


int Estudante::getMatricula() const
{
    return this->matricula;
}


void Estudante::setMatricula(int matricula)
{
    this->matricula = matricula;
}

int Estudante::getCoeficiente() const
{
    return this->coeficiente;
}


void Estudante::setCoeficiente(int coeficiente)
{
    this->coeficiente = coeficiente;
}

float Estudante::operator+(Estudante aux){
    return this->coeficiente + aux.coeficiente;
}

float Estudante::operator+(float n){
    return this->coeficiente + n;
}

bool Estudante::operator==(string str){
    return (this->nome == str || this->curso == str);
}

bool Estudante::operator==(int matricula){
    return this->matricula == matricula;
}

bool Estudante::operator==(float coef){
    return this->coeficiente == coef;
}

#endif
