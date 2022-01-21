#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "string"

using namespace std;

class System {
private:
    string name;
    double value;
public:
    System();

    System(const System *system);

    System(string name);

    System(string name, double value);

    virtual ~System();

    void setValue(double value);

    double getValue() const;

    string getName() const;

    void setName(string name);

    System* operator=(const System* system);
};

#endif
