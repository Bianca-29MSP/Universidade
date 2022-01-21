#ifndef MODELIMPLEMENTATION_HPP
#define MODELIMPLEMENTATION_HPP

#include "ModelInterface.hpp"

class ModelImplementation : public ModelInterface {
private:
    double time;
    list<FlowImplementation *> flows;
    list<SystemImplementation *> systems;

    ModelImplementation* operator=(const ModelImplementation* model);
    ModelImplementation(const ModelImplementation* model);
public:
    typedef list<FlowImplementation *>::iterator iteratorFlow;
    typedef list<SystemImplementation *>::iterator iteratorSystem;

    ModelImplementation();

    virtual ~ModelImplementation();

    void add(FlowImplementation * flow = NULL);

    void add(SystemImplementation * system = NULL);
    
    iteratorFlow beginFlows();

    iteratorFlow endFlows();

    iteratorSystem beginSystems();

    iteratorSystem endSystems();

    void setTime(double time);
    
    double getTime() const;

    void incrementTime(double increment = 1);

    void run(double start = 0, double end = 0, double increment = 0);
};

#endif
