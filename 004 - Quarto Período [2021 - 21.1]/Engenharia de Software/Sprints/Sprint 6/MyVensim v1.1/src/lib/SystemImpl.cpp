#include "../include/SystemImpl.hpp"

SystemBody::SystemBody(){
    setValue(0);
}

// SystemBody::SystemBody(const SystemBody *system)
// {
//     if (system == this)
//         return;
        
//     name = system->name;
//     value = system->value;
// }

SystemBody::SystemBody(string name){
    setValue(0);
    setName(name);
}

SystemBody::SystemBody(string name, double value){
    setName(name);
    setValue(value);
}

SystemBody::~SystemBody(){}

void SystemBody::setValue(double value)
{
    this->value = value;
}

double SystemBody::getValue() const
{
    return value;
}

string SystemBody::getName() const
{
    return name;
}

void SystemBody::setName(string name)
{
    this->name = name;
}

// SystemBody* SystemBody::operator=(const SystemBody* system)
// {
//     if (system == this)
//         return this;

//     name = system->name;
//     value = system->value;

//     return this;
// }
