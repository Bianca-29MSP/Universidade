#include "../include/FlowImpl.hpp"
#include "../include/System.hpp"

FlowBody::FlowBody()
{
    source = NULL;
    target = NULL;
}

// FlowBody::FlowBody(const FlowBody* flow)
// {
//     if (flow == this)
//         return;

//     name = flow->name;
//     currentValue = flow->currentValue;
//     source = flow->source;
//     target = flow->target;
// }

FlowBody::FlowBody(string name, System *s, System *t)
{
    source = s;
    target = t;
    setName(name);
}

FlowBody::~FlowBody(){}

string FlowBody::getName() const
{
    return name;
}

void FlowBody::setName(string name)
{
    this->name = name;
}

double FlowBody::getCurrentValue() const
{
    return currentValue;
}

void FlowBody::setCurrentValue(double value)
{
    currentValue = value;
}

System * FlowBody::getSource(void) const
{
    return source;
}

System * FlowBody::getTarget(void) const
{
    return target;
}

void FlowBody::setSource(System * source)
{
    this->source = source;
}

void FlowBody::setTarget(System * target)
{
    this->target = target;
}

void FlowBody::connect(System *source, System* target)
{
    setSource(source);
    setTarget(target);
}

// FlowBody* FlowBody::operator=(const FlowBody* flow)
// {
//     if (flow == this)
//         return this;

//     this->source = flow->source;
//     this->target = flow->target;
//     this->currentValue = flow->currentValue;

//     return this;
// }
