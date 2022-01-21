#include "SystemImplementation.hpp"

SystemImplementation::SystemImplementation(){}

SystemImplementation::SystemImplementation(const SystemImplementation *system)
{
    if (system == this)
        return;
        
    name = system->name;
    value = system->value;
}

SystemImplementation::SystemImplementation(string name){
    setName(name);
}

SystemImplementation::SystemImplementation(string name, double value){
    setName(name);
    setValue(value);
}

SystemImplementation::~SystemImplementation(){}

void SystemImplementation::setValue(double value)
{
    this->value = value;
}

double SystemImplementation::getValue() const
{
    return value;
}

string SystemImplementation::getName() const
{
    return name;
}

void SystemImplementation::setName(string name)
{
    this->name = name;
}

SystemImplementation* SystemImplementation::operator=(const SystemImplementation* system)
{
    if (system == this)
        return this;

    name = system->name;
    value = system->value;

    return this;
}
