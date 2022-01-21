#ifndef MODELINTERFACE_HPP
#define MODELINTERFACE_HPP

#include <list>

using namespace std;

class FlowImplementation;
class SystemImplementation;

class ModelInterface {
public:
    typedef list<FlowImplementation *>::iterator iteratorFlow;
    typedef list<SystemImplementation *>::iterator iteratorSystem;

    virtual ~ModelInterface(){};

    virtual void add(FlowImplementation * flow = NULL) = 0;

    virtual void add(SystemImplementation * system = NULL) = 0;
    
    virtual iteratorFlow beginFlows() = 0;

    virtual iteratorFlow endFlows() = 0;

    virtual iteratorSystem beginSystems() = 0;

    virtual iteratorSystem endSystems() = 0;

    virtual void setTime(double time) = 0;
    
    virtual double getTime() const = 0;

    virtual void incrementTime(double increment = 1) = 0;

    virtual void run(double start = 0, double end = 0, double increment = 0) = 0;
};

#endif
