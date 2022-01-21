#include "Model.hpp"

Model::Model(){
    setTime(0);
};

Model::~Model(){
    for (System* system : systems) {
        delete (system);
    }

    for (Flow* flow : flows) {
        delete (flow);
    }
}

void Model::add(Flow * flow) {
    flows.push_back(flow);
}

void Model::add(System * system) {
    systems.push_back(system);
}

list<Flow *> Model::getFlows() const
{
    return flows;
}

list<System *> Model::getSystems() const
{
    return systems;
}

void Model::setTime(double time) {
    this->time = time;
}

double Model::getTime() const{
    return time;
}

void Model::incrementTime(double increment) {
    time += increment;
}

void Model::run(double start, double end, double increment)
{
    for(double i = start; i < end; i+=increment) 
    {
        for(Flow *f: getFlows()) 
        {
            f->setCurrentValue(f->execute());
        }

        for(Flow *f: getFlows()) 
        {
            System *source = f->getSource();
            System *target = f->getTarget();
            if(source != NULL)
            {
                source->setValue(source->getValue() - f->getCurrentValue());
            }

            if(target != NULL) 
            {
                target->setValue(target->getValue() + f->getCurrentValue());
            }
        }
        
        incrementTime(increment);
    }
}
