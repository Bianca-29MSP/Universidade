#include "../include/FlowImpl.hpp"
#include "../include/System.hpp"

FlowImpl::FlowImpl()
{
    source = NULL;
    target = NULL;
}

FlowImpl::FlowImpl(const FlowImpl* flow)
{
    if (flow == this)
        return;

    name = flow->name;
    currentValue = flow->currentValue;
    source = flow->source;
    target = flow->target;
}

FlowImpl::FlowImpl(string name)
{
    source = NULL;
    target = NULL;
    setName(name);
}

FlowImpl::FlowImpl(string name, System *s, System *t)
{
    source = s;
    target = t;
    setName(name);
}

FlowImpl::~FlowImpl(){}

string FlowImpl::getName() const
{
    return name;
}

void FlowImpl::setName(string name)
{
    this->name = name;
}

double FlowImpl::getCurrentValue() const
{
    return currentValue;
}

void FlowImpl::setCurrentValue(double value)
{
    currentValue = value;
}

System * FlowImpl::getSource(void) const
{
    return source;
}

System * FlowImpl::getTarget(void) const
{
    return target;
}

void FlowImpl::setSource(System * source)
{
    this->source = source;
}

void FlowImpl::setTarget(System * target)
{
    this->target = target;
}

void FlowImpl::connect(System *source, System* target)
{
    setSource(source);
    setTarget(target);
}

FlowImpl* FlowImpl::operator=(const FlowImpl* flow)
{
    if (flow == this)
        return this;

    this->source = flow->source;
    this->target = flow->target;
    this->currentValue = flow->currentValue;

    return this;
}
