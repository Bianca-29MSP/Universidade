#ifndef  FUNCIONAL_TESTS
#define FUNCIONA_TESTS

#include "../../src/Flow.hpp"

void exponentialFuncionalTest();

void logisticalFuncionalTest();

void complexFuncionalTest();

class FlowExponential : public Flow{
public:
    FlowExponential(string name): Flow(name){}

    double execute(){
        return 0.01 * getSource()->getValue();
    }
};

class FlowLogistic : public Flow{
public:
    FlowLogistic(string name): Flow(name){}

    double execute(){
        return 0.01 * getTarget()->getValue() * (1 - getTarget()->getValue() / 70);
    }
};

class FlowComplexF: public Flow{
public:
    FlowComplexF(string name): Flow(name){}

    double execute(){
        return 0.01 * getSource()->getValue();
    }
};

class FlowComplexG: public Flow{
public:
    FlowComplexG(string name): Flow(name){}

    double execute(){
        return 0.01 * getSource()->getValue();
    }
};

class FlowComplexT: public Flow{
public:
    FlowComplexT(string name): Flow(name){}

    double execute(){
        return 0.01 * getSource()->getValue();
    }
};

class FlowComplexR: public Flow{
public:
    FlowComplexR(string name): Flow(name){}

    double execute(){
        return 0.01 * getSource()->getValue();
    }
};

class FlowComplexU: public Flow{
public:
    FlowComplexU(string name): Flow(name){}

    double execute(){
        return 0.01 * getSource()->getValue();
    }
};

class FlowComplexV: public Flow{
public:
    FlowComplexV(string name): Flow(name){}

    double execute(){
        return 0.01 * getSource()->getValue();
    }
};

#endif