#ifndef SYSTEMINTERFACE_HPP
#define SYSTEMINTERFACE_HPP

#include"string"

using namespace std;

class SystemInterface {
public:
    virtual ~SystemInterface(){};

    virtual void setValue(double value) = 0;

    virtual double getValue() const = 0;

    virtual string getName() const = 0;

    virtual void setName(string name) = 0;
};

#endif
