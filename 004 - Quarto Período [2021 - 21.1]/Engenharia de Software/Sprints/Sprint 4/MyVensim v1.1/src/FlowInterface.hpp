#ifndef FLOWINTERFACE_HPP
#define FLOWINTERFACE_HPP

#include "string"

using namespace std;

class SystemImplementation;

class FlowInterface {
public:
    virtual ~FlowInterface(){};

    virtual string getName() = 0;

    virtual void setName(string name) = 0;

    virtual double getCurrentValue() const = 0;

    virtual void setCurrentValue(double value) = 0;

    virtual SystemImplementation * getSource(void) const = 0;

    virtual SystemImplementation * getTarget(void) const = 0;

    virtual void setSource(SystemImplementation * source) = 0;

    virtual void setTarget(SystemImplementation * target) = 0;

    virtual void connect(SystemImplementation *source = NULL, SystemImplementation* target = NULL);

    virtual double execute() = 0;
};

#endif
