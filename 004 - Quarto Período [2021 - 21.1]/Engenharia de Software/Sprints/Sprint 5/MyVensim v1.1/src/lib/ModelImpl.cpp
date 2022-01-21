#include "../include/ModelImpl.hpp"
#include "../include/SystemImpl.hpp"

list<Model *> ModelImpl::models;

ModelImpl::ModelImpl(){
    setTime(0);
};

ModelImpl::ModelImpl(string name){
    setTime(0);
    setName(name);
}

ModelImpl::~ModelImpl(){}

void ModelImpl::add(Flow * flow) {
    flows.push_back(flow);
}

void ModelImpl::add(System * system) {
    systems.push_back(system);
}

ModelImpl::iteratorFlow ModelImpl::beginFlows()
{
  return flows.begin();
}

ModelImpl::iteratorFlow ModelImpl::endFlows()
{
  return flows.end();
}

ModelImpl::iteratorSystem ModelImpl::beginSystems()
{
  return systems.begin();
}

ModelImpl::iteratorSystem ModelImpl::endSystems()
{
  return systems.end();
}

void ModelImpl::setTime(double time) {
    this->time = time;
}

double ModelImpl::getTime() const{
    return time;
}

void ModelImpl::setName(string name) {
    this->name = name;
}

string ModelImpl::getName() const {
    return name;
}

void ModelImpl::incrementTime(double increment) {
    time += increment;
}

void ModelImpl::run(double start, double end, double increment)
{
    for(double i = start; i < end; i+=increment) 
    {
        for(auto it = beginFlows(); it != endFlows(); it++)
        {
            (*it)->setCurrentValue((*it)->execute());
        }    

        for(auto it = beginFlows(); it != endFlows(); it++)
        {
            System *source = (*it)->getSource();
            System *target = (*it)->getTarget();
            if(source != NULL)
            {
                source->setValue(source->getValue() - (*it)->getCurrentValue());
            }

            if(target != NULL) 
            {
                target->setValue(target->getValue() + (*it)->getCurrentValue());
            }
        }
        
        incrementTime(increment);
    }
}

System* ModelImpl::createSystem(string name, double value) {
    System *s = new SystemImpl(name, value);
    add(s);
    return s;
}

Model * Model::createModel(string name) {
    return ModelImpl::createModel(name);
}

Model * ModelImpl::createModel(string name) {
    Model * m = new ModelImpl(name);
    models.push_back(m);
    return m;
}

