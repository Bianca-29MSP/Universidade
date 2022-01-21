#include "Model.hpp"
#include <iostream>

Model::Model() {
    setInitialTime(0);
    setFinalTime(0);
}

Model::Model(int initialTime, int finalTime) {
    setInitialTime(initialTime);
    setFinalTime(finalTime);
}

Model::~Model(){}

void Model::add(Flow * flow) {
    flows.push_back(flow);
}

list<Flow *> Model::getFlows() const
{
    return this->flows;
}

int Model::getInitialTime() const
{
    return this->initialTime;
}

void Model::setInitialTime(int initialTime)
{
    this->initialTime = initialTime;
}

int Model::getFinalTime() const
{
    return this->finalTime;
}

void Model::setFinalTime(int finalTime)
{
    this->finalTime = finalTime;
}

void Model::run() 
{
    double calc = 0;
    vector<double> resultsAux;
    for(int i = getInitialTime(); i < getFinalTime(); i++) 
    { //execução dentro do periodo de tempo informado
        for(Flow *f: getFlows()) 
        { //executa o run de cada flow dentro do model e armazena o valor em resultsAux
            calc = f->run();
            //cout << calc << endl;
            resultsAux.push_back(calc);
        }

        int j = 0;

        for(Flow *f: getFlows()) 
        { //atualiza os valores dos sistemas [entrada, saída] caso exista.
            if(f->getInput() != NULL) 
                f->getInput()->setValue(f->getInput()->getValue() - resultsAux[j]);

            if(f->getOutput() != NULL) 
                f->getOutput()->setValue(f->getOutput()->getValue() + resultsAux[j]);
            j++;
        }
        
        resultsAux.clear();
    }
}

Model& Model::operator=(const Model& model) 
{
    if (&model == this)
        return *this;

    this->flows = model.flows;
    this->initialTime = model.initialTime;
    this->finalTime = model.finalTime;

    return *this;
}

