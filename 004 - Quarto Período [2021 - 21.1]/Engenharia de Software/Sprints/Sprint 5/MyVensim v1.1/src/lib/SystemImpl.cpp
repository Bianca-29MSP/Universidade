#include "../include/SystemImpl.hpp"

SystemImpl::SystemImpl(){
    setValue(0);
}

SystemImpl::SystemImpl(const SystemImpl *system)
{
    if (system == this)
        return;
        
    name = system->name;
    value = system->value;
}

SystemImpl::SystemImpl(string name){
    setValue(0);
    setName(name);
}

SystemImpl::SystemImpl(string name, double value){
    setName(name);
    setValue(value);
}

SystemImpl::~SystemImpl(){}

void SystemImpl::setValue(double value)
{
    this->value = value;
}

double SystemImpl::getValue() const
{
    return value;
}

string SystemImpl::getName() const
{
    return name;
}

void SystemImpl::setName(string name)
{
    this->name = name;
}

SystemImpl* SystemImpl::operator=(const SystemImpl* system)
{
    if (system == this)
        return this;

    name = system->name;
    value = system->value;

    return this;
}
