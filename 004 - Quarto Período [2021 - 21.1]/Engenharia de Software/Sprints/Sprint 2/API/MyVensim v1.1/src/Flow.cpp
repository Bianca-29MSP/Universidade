#include "Flow.hpp"

#include <iostream>
#include <bits/stdc++.h>
#include "System.hpp"

using namespace std;

Flow::Flow(){
    this->input = NULL;
    this->output = NULL;
}

Flow::Flow(string name){
    this->input = NULL;
    this->output = NULL;
    setName(name);
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

void Flow::setEquation(double constant, string observedSystem) 
{
    this->equation.constant = constant;
    this->equation.observedSystem = observedSystem;
    this->equation.PMax = INT_MIN;
}

void Flow::setEquation(double constant, string observedSystem, int PMax) 
{
    this->equation.constant = constant;
    this->equation.observedSystem = observedSystem;
    this->equation.PMax = PMax;
}

string Flow::getName()
{
    return this->name;
}

void Flow::setName(string name)
{
    this->name = name;
}

double Flow::getConstant() 
{
    return this->equation.constant; 
}

string Flow::getObservedSystem() 
{
    return this->equation.observedSystem; 
}

int Flow::getPMax() 
{
    return this->equation.PMax; 
}

double Flow::run()
{
    System *s = NULL;
    if(getObservedSystem() == getInput()->getName()) s = getInput();
    else if(getObservedSystem() == getOutput()->getName())  s = getOutput();

    if(s == NULL)
        return getConstant();

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
    return (getConstant() * P);
}

double Flow::logistical(System * sys) 
{
    double P = sys->getValue();
    return (getConstant() * P) * (1 - P/ getPMax());
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