#include "ModelImplementation.hpp"
#include "SystemImplementation.hpp"
#include "FlowImplementation.hpp"

ModelImplementation::ModelImplementation(){
    setTime(0);
};

ModelImplementation::~ModelImplementation(){}

void ModelImplementation::add(FlowImplementation * flow) {
    flows.push_back(flow);
}

void ModelImplementation::add(SystemImplementation * system) {
    systems.push_back(system);
}

ModelImplementation::iteratorFlow ModelImplementation::beginFlows()
{
  return flows.begin();
}

ModelImplementation::iteratorFlow ModelImplementation::endFlows()
{
  return flows.end();
}

ModelImplementation::iteratorSystem ModelImplementation::beginSystems()
{
  return systems.begin();
}

ModelImplementation::iteratorSystem ModelImplementation::endSystems()
{
  return systems.end();
}

void ModelImplementation::setTime(double time) {
    this->time = time;
}

double ModelImplementation::getTime() const{
    return time;
}

void ModelImplementation::incrementTime(double increment) {
    time += increment;
}


void ModelImplementation::run(double start, double end, double increment)
{
    for(double i = start; i < end; i+=increment) 
    {
        for(auto it = beginFlows(); it != endFlows(); it++)
        {
            (*it)->setCurrentValue((*it)->execute());
        }    

        for(auto it = beginFlows(); it != endFlows(); it++)
        {
            SystemImplementation *source = (*it)->getSource();
            SystemImplementation *target = (*it)->getTarget();
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
