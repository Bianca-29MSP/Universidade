#ifndef MODEL_HPP
#define MODEL_HPP

#include <list>

using namespace std;

class Flow;
class System;

class Model {
private:
    double time;
    list<Flow *> flows;
    list<System *> systems;

    Model* operator=(const Model* model);
    Model(const Model* model);
public:
    typedef list<Flow *>::iterator iteratorFlow;
    typedef list<System *>::iterator iteratorSystem;

    Model();

    virtual ~Model();

    void add(Flow * flow = NULL);

    void add(System * system = NULL);
    
    iteratorFlow beginFlows();

    iteratorFlow endFlows();

    iteratorSystem beginSystems();

    iteratorSystem endSystems();

    void setTime(double time);
    
    double getTime() const;

    void incrementTime(double increment = 1);

    void run(double start = 0, double end = 0, double increment = 0);
};

#endif
