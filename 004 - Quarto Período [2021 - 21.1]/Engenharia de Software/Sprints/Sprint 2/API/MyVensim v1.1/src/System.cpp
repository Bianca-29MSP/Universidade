#include "System.hpp"

#include <iostream>

System::System(){}

System::System(string name){
    setName(name);
}

System::~System(){}

void System::setValue(double value)
{
    this->value = value;
}

double System::getValue()
{
    return this->value;
}

string System::getName()
{
    return this->name;
}

void System::setName(string name)
{
    this->name = name;
}

System& System::operator=(const System& system)
{
    if (&system == this)
        return *this;

    this->value = system.value;

    return *this;
}
