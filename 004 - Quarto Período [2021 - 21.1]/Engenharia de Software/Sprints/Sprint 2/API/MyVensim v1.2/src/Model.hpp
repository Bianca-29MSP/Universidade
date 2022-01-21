#ifndef MODEL_HPP
#define MODEL_HPP

#include "Flow.hpp"
#include <list>

using namespace std;

class Model {
private:
    double time;
    list<Flow *> flows;
    list<System *> systems;

    Model* operator=(const Model* model){}
protected:
public:
    Model() {
        setTime(0);
    }

    virtual ~Model(){}

    void add(Flow * flow = NULL) {
        flows.push_back(flow);
    }

    void add(System * system = NULL) {
        systems.push_back(system);
    }

    list<Flow *> getFlows() const
    {
        return flows;
    }

    list<System *> getSystems() const
    {
        return systems;
    }

    void setTime(double time) {
        this->time = time;
    }

    double getTime() const{
        return time;
    }

    void incrementTime(double increment = 1) {
        time += increment;
    }

    void run(double start = 0, double end = 0, double increment = 0)
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
};

#endif