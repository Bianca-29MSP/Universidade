#ifndef FLOW_HPP
#define FLOW_HPP

#include "System.hpp"
#include "string"

using namespace std;

class Flow {
private:
    string name;
    double currentValue;
    System *source; //entrada
    System *target; //saida
public:
    Flow(){
        this->source = NULL;
        this->target = NULL;
    }
    
    Flow(string name){
        this->source = NULL;
        this->target = NULL;
        setName(name);
    }

    virtual ~Flow(){}

    string getName()
    {
        return name;
    }

    void setName(string name)
    {
        this->name = name;
    }

    double getCurrentValue() const
    {
        return currentValue;
    }

    void setCurrentValue(double value)
    {
        currentValue = value;
    }

    System * getSource(void) const
    {
        return source;
    }

    System * getTarget(void) const
    {
        return target;
    }

    void setSource(System * source)
    {
        this->source = source;
    }

    void setTarget(System * target)
    {
        this->target = target;
    }

    void connect(System *source = NULL, System* target = NULL)
    {
        setSource(source);
        setTarget(target);
    }

    virtual double execute() = 0;

    Flow* operator=(const Flow* flow)
    {
        if (flow == this)
            return this;

        this->source = flow->source;
        this->target = flow->target;
        this->currentValue = flow->currentValue;

        return this;
    }
};

#endif
