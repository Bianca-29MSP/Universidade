#include "Flow.hpp"
#include "System.hpp"

Flow::Flow()
{
    source = NULL;
    target = NULL;
}

Flow::Flow(const Flow* flow)
{
    if (flow == this)
        return;

    name = flow->name;
    currentValue = flow->currentValue;
    source = flow->source;
    target = flow->target;
}

Flow::Flow(string name)
{
    source = NULL;
    target = NULL;
    setName(name);
}

Flow::~Flow(){}

string Flow::getName()
{
    return name;
}

void Flow::setName(string name)
{
    this->name = name;
}

double Flow::getCurrentValue() const
{
    return currentValue;
}

void Flow::setCurrentValue(double value)
{
    currentValue = value;
}

System * Flow::getSource(void) const
{
    return source;
}

System * Flow::getTarget(void) const
{
    return target;
}

void Flow::setSource(System * source)
{
    this->source = source;
}

void Flow::setTarget(System * target)
{
    this->target = target;
}

void Flow::connect(System *source, System* target)
{
    setSource(source);
    setTarget(target);
}

Flow* Flow::operator=(const Flow* flow)
{
    if (flow == this)
        return this;

    this->source = flow->source;
    this->target = flow->target;
    this->currentValue = flow->currentValue;

    return this;
}
