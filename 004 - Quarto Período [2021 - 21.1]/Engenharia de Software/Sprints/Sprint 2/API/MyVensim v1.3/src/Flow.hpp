#ifndef FLOW_HPP
#define FLOW_HPP

#include "string"

using namespace std;

class System;

class Flow {
private:
    string name;
    double currentValue;
    System *source;
    System *target;
public:
    Flow();

    Flow(const Flow* flow);
    
    Flow(string name);

    virtual ~Flow();

    string getName();

    void setName(string name);

    double getCurrentValue() const;

    void setCurrentValue(double value);

    System * getSource(void) const;

    System * getTarget(void) const;

    void setSource(System * source);

    void setTarget(System * target);

    void connect(System *source = NULL, System* target = NULL);

    virtual double execute() = 0;

    Flow* operator=(const Flow* flow);
};

#endif
