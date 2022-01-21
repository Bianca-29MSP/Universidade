#include "System.hpp"

#include <iostream>

System::System(){}

System::~System(){}

void System::setValue(double value)
{
    this->value = value;
}

double System::getValue()
{
    return this->value;
}

System& System::operator=(const System& system)
{
    if (&system == this)
        return *this;

    this->value = system.value;

    return *this;
}
