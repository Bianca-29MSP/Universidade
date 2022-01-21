#include "functional_tests.hpp"
#include <iostream>
#include <assert.h> 
#include <cmath>

#include "../../src/ModelImplementation.hpp"
#include "../../src/SystemImplementation.hpp"
#include "../../src/FlowImplementation.hpp"

//Equações dos flows
class FlowExponential : public FlowImplementation
{
public:
    FlowExponential(string name): FlowImplementation(name){}

    double execute(){
        return 0.01 * getSource()->getValue();
    }
};

class FlowLogistic : public FlowImplementation
{
public:
    FlowLogistic(string name): FlowImplementation(name){}

    double execute(){
        return 0.01 * getTarget()->getValue() * (1 - getTarget()->getValue() / 70);
    }
};

class FlowComplexF: public FlowImplementation
{
public:
    FlowComplexF(string name): FlowImplementation(name){}

    double execute(){
        return 0.01 * getSource()->getValue();
    }
};

class FlowComplexG: public FlowImplementation
{
public:
    FlowComplexG(string name): FlowImplementation(name){}

    double execute(){
        return 0.01 * getSource()->getValue();
    }
};

class FlowComplexT: public FlowImplementation
{
public:
    FlowComplexT(string name): FlowImplementation(name){}

    double execute(){
        return 0.01 * getSource()->getValue();
    }
};

class FlowComplexR: public FlowImplementation
{
public:
    FlowComplexR(string name): FlowImplementation(name){}

    double execute(){
        return 0.01 * getSource()->getValue();
    }
};

class FlowComplexU: public FlowImplementation
{
public:
    FlowComplexU(string name): FlowImplementation(name){}

    double execute(){
        return 0.01 * getSource()->getValue();
    }
};

class FlowComplexV: public FlowImplementation
{
public:
    FlowComplexV(string name): FlowImplementation(name){}

    double execute(){
        return 0.01 * getSource()->getValue();
    }
};

void exponentialFuncionalTest()
{
    cout << "Teste Exponencial [INICIADO]" << endl;
    ModelImplementation *m1 = new ModelImplementation;
    SystemImplementation *pop1 = new SystemImplementation("pop1", 100);
    SystemImplementation *pop2 = new SystemImplementation("pop2", 0);
    FlowExponential *exponencial = new FlowExponential("exponencial");

    exponencial->connect(pop1, pop2);
    m1->add(pop1);
    m1->add(pop2);
    m1->add(exponencial);
    m1->run(0, 100, 1);

    cout << "$ ("<< pop1->getName() << ") "  << pop1->getValue() << endl;
    cout << "$ ("<< pop2->getName() << ") "  << pop2->getValue() << endl;

    assert(abs((pop1->getValue() - 36.6032)) < 0.0001);
    assert(abs((pop2->getValue() - 63.3968)) < 0.0001);

    cout << "Teste Exponencial [FINALIZADO]: Ok!" << endl;
}

void logisticalFuncionalTest()
{
    cout << "Teste Logistico [INICIADO]" << endl;
    ModelImplementation *m1 = new ModelImplementation;
    SystemImplementation *p1 = new SystemImplementation("p1", 100);
    SystemImplementation *p2 = new SystemImplementation("p2", 10);
    FlowLogistic *logistic = new FlowLogistic("logistic");

    logistic->connect(p1, p2);
    m1->add(p1);
    m1->add(p2);
    m1->add(logistic);
    m1->run(0, 100, 1);

    cout << "$ ("<< p1->getName() << ") " << p1->getValue() << endl;
    cout << "$ ("<< p2->getName() << ") "  << p2->getValue() << endl;
    
    assert(abs((p1->getValue() - 88.2167)) < 0.0001);
    assert(abs((p2->getValue() - 21.7833)) < 0.0001);

    cout << "Teste Logistico [FINALIZADO]: Ok!" << endl;
}

void complexFuncionalTest()
{
    cout << "Teste Complexo [INICIADO]" << endl;
    ModelImplementation *m1 = new ModelImplementation;
    SystemImplementation *q1 = new SystemImplementation("q1", 100);
    SystemImplementation *q2 = new SystemImplementation("q2", 0);
    SystemImplementation *q3 = new SystemImplementation("q3", 100);
    SystemImplementation *q4 = new SystemImplementation("q4", 0);
    SystemImplementation *q5 = new SystemImplementation("q5", 0);
    FlowComplexF *f = new FlowComplexF("f");
    FlowComplexG *g = new FlowComplexG("g");
    FlowComplexT *t = new FlowComplexT("t");
    FlowComplexR *r = new FlowComplexR("r");
    FlowComplexU *u = new FlowComplexU("u");
    FlowComplexV *v = new FlowComplexV("v");

    f->connect(q1, q2);
    g->connect(q1, q3);
    t->connect(q2, q3);
    r->connect(q2, q5);
    u->connect(q3, q4);
    v->connect(q4, q1);

    m1->add(q1);
    m1->add(q2);
    m1->add(q3);
    m1->add(q4);
    m1->add(q5);
    
    m1->add(f);
    m1->add(g);
    m1->add(t);
    m1->add(r);
    m1->add(u);
    m1->add(v);

    m1->run(0, 100, 1);

    cout << "$ ("<< q1->getName() << ") "  << q1->getValue() << endl;
    cout << "$ ("<< q1->getName() << ") "  << q2->getValue() << endl;
    cout << "$ ("<< q3->getName() << ") "  << q3->getValue() << endl;
    cout << "$ ("<< q3->getName() << ") "  << q4->getValue() << endl;
    cout << "$ ("<< q5->getName() << ") "  << q5->getValue() << endl;

    assert(abs((q1->getValue() - 31.8513)) < 0.0001);
    assert(abs((q2->getValue() - 18.4003)) < 0.0001);
    assert(abs((q3->getValue() - 77.1143)) < 0.0001);
    assert(abs((q4->getValue() - 56.1728)) < 0.0001);
    assert(abs((q5->getValue() - 16.4612)) < 0.0001);

    cout << "Teste Complexo [FINALIZADO]: Ok!" << endl;
}
