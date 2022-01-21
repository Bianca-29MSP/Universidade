#ifndef FLOWIMPLEMENTATION_HPP
#define FLOWIMPLEMENTATION_HPP

#include "FlowInterface.hpp"

class FlowImplementation {
private:
    string name;
    double currentValue;
    SystemImplementation *source;
    SystemImplementation *target;
public:
    FlowImplementation();

    FlowImplementation(const FlowImplementation* flow);
    
    FlowImplementation(string name);

    virtual ~FlowImplementation();

    string getName();

    void setName(string name);

    double getCurrentValue() const;

    void setCurrentValue(double value);

    SystemImplementation * getSource(void) const;

    SystemImplementation * getTarget(void) const;

    void setSource(SystemImplementation * source);

    void setTarget(SystemImplementation * target);

    void connect(SystemImplementation *source = NULL, SystemImplementation* target = NULL);

    virtual double execute() = 0;

    FlowImplementation* operator=(const FlowImplementation* flow);
};

#endif
