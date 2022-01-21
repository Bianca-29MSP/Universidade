#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <vector>
#include "string"

using namespace std;

class System {
private:
    string name;
    double value;
protected:
public:
    System(){}

    System(string name){
        setName(name);
    }

    System(string name, double value){
        setName(name);
        setValue(value);
    }

    virtual ~System(){}

    void setValue(double value)
    {
        this->value = value;
    }

    double getValue() const
    {
        return value;
    }

    string getName() const
    {
        return name;
    }

    void setName(string name)
    {
        this->name = name;
    }

    System* operator=(const System* system)
    {
        if (system == this)
            return this;

        name = system->name;
        value = system->value;

        return this;
    }
};

#endif
