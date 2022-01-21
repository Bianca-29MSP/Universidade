#include "System.hpp"

#include <iostream>

System::System(){
    setValue(0);
}

System::System(string name){
    setValue(0);
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
    this->name = system.name;

    return *this;
}
