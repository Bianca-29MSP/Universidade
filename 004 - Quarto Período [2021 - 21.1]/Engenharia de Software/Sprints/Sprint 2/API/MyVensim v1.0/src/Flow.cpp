#include "Flow.hpp"

#include <iostream>
#include <bits/stdc++.h>
#include "System.hpp"

using namespace std;

Flow::Flow(){
    this->input = NULL;
    this->output = NULL;
}

Flow::~Flow(){}

void Flow::setInput(System * input)
{
    this->input = input;
}

System * Flow::getInput()
{
    return this->input;
}

void Flow::setOutput(System * output)
{
    this->output = output;
}

System * Flow::getOutput(void)
{
    return this->output;
}

void Flow::setEquation(double constante, int type) 
{
    this->equation.constante = constante;
    this->equation.type = type;
    this->equation.PMax = INT_MIN;
}

void Flow::setEquation(double constante, int type, int PMax) 
{
    this->equation.constante = constante;
    this->equation.type = type;
    this->equation.PMax = PMax;
}

double Flow::getConstante() 
{
    return this->equation.constante; 
}

int Flow::getConnection() 
{
    return this->equation.type; 
}

int Flow::getPMax() 
{
    return this->equation.PMax; 
}

double Flow::run()
{
    System *s = NULL;
    s = getConnection() ? getInput(): getOutput(); //verifica qual dos sistemas o flow tem "acesso" ao valor

    if(s == NULL)
        return getConstante();

    double calc;

    if(getPMax() != INT_MIN) { //Caso seja tenha um valor máximo para atingir
        calc = logistical(s);
    } else {
        calc = exponential(s);
    }
    return calc;
}

double Flow::exponential(System * sys) 
{
    double P = sys->getValue();
    return (getConstante() * P);
}

double Flow::logistical(System * sys) 
{
    double P = sys->getValue();
    return (getConstante() * P) * (1 - P/ getPMax());
}

Flow& Flow::operator=(const Flow& flow) 
{
    if (&flow == this)
        return *this;

    this->input = flow.input;
    this->output = flow.output;
    this->equation = flow.equation;

    return *this;
}