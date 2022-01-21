#include "../include/ModelImpl.hpp"
#include "../include/SystemImpl.hpp"

#define DEBUGING
#ifdef DEBUGING
    int numHandleCreated = 0;
	int numHandleDeleted = 0;
	int numBodyCreated = 0;
	int numBodyDeleted = 0;
#endif


list<Model *> ModelBody::models;

ModelBody::ModelBody(){
    setTime(0);
};

ModelBody::ModelBody(string name){
    setTime(0);
    setName(name);
}

ModelBody::~ModelBody(){}

void ModelBody::add(Flow * flow) {
    flows.push_back(flow);
}

void ModelBody::add(System * system) {
    systems.push_back(system);
}

ModelBody::iteratorFlow ModelBody::beginFlows()
{
  return flows.begin();
}

ModelBody::iteratorFlow ModelBody::endFlows()
{
  return flows.end();
}

ModelBody::iteratorSystem ModelBody::beginSystems()
{
  return systems.begin();
}

ModelBody::iteratorSystem ModelBody::endSystems()
{
  return systems.end();
}

void ModelBody::setTime(double time) {
    this->time = time;
}

double ModelBody::getTime() const{
    return time;
}

void ModelBody::setName(string name) {
    this->name = name;
}

string ModelBody::getName() const {
    return name;
}

void ModelBody::incrementTime(double increment) {
    time += increment;
}

void ModelBody::run(double start, double end, double increment)
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

System* ModelBody::createSystem(string name, double value) {
    System *s = new SystemHandle(name, value);
    add(s);
    return s;
}

Model * Model::createModel(string name) {
    return ModelHandle::createModel(name);
}

Model * ModelBody::createModel(string name) {
    Model * m = new ModelHandle(name);
    models.push_back(m);
    return m;
}

