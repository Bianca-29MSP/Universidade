#include "FlowImplementation.hpp"
#include "SystemImplementation.hpp"

FlowImplementation::FlowImplementation()
{
    source = NULL;
    target = NULL;
}

FlowImplementation::FlowImplementation(const FlowImplementation* flow)
{
    if (flow == this)
        return;

    name = flow->name;
    currentValue = flow->currentValue;
    source = flow->source;
    target = flow->target;
}

FlowImplementation::FlowImplementation(string name)
{
    source = NULL;
    target = NULL;
    setName(name);
}

FlowImplementation::~FlowImplementation(){}

string FlowImplementation::getName()
{
    return name;
}

void FlowImplementation::setName(string name)
{
    this->name = name;
}

double FlowImplementation::getCurrentValue() const
{
    return currentValue;
}

void FlowImplementation::setCurrentValue(double value)
{
    currentValue = value;
}

SystemImplementation * FlowImplementation::getSource(void) const
{
    return source;
}

SystemImplementation * FlowImplementation::getTarget(void) const
{
    return target;
}

void FlowImplementation::setSource(SystemImplementation * source)
{
    this->source = source;
}

void FlowImplementation::setTarget(SystemImplementation * target)
{
    this->target = target;
}

void FlowImplementation::connect(SystemImplementation *source, SystemImplementation* target)
{
    setSource(source);
    setTarget(target);
}

FlowImplementation* FlowImplementation::operator=(const FlowImplementation* flow)
{
    if (flow == this)
        return this;

    this->source = flow->source;
    this->target = flow->target;
    this->currentValue = flow->currentValue;

    return this;
}
