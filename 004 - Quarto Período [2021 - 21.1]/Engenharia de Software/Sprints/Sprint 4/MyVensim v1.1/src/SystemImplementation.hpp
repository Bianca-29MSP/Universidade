#ifndef SYSTEMIMPLEMENTATION_HPP
#define SYSTEMIMPLEMENTATION_HPP

#include "SystemInterface.hpp"

using namespace std;

class SystemImplementation : public SystemInterface {
private:
    string name;
    double value;
public:
    SystemImplementation();

    SystemImplementation(const SystemImplementation *system);

    SystemImplementation(string name);

    SystemImplementation(string name, double value);

    virtual ~SystemImplementation();

    void setValue(double value);

    double getValue() const;

    string getName() const;

    void setName(string name);

    SystemImplementation* operator=(const SystemImplementation* system);
};

#endif
