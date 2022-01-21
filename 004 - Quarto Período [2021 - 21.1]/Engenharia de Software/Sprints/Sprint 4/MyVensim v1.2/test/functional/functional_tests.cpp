#include "functional_tests.hpp"
#include <iostream>
#include <assert.h> 
#include <cmath>

#include "../../src/Model.hpp"
#include "../../src/System.hpp"
#include "../../src/Flow.hpp"

//Equações dos flows
class FlowExponential : public Flow
{
public:
    FlowExponential(string name): Flow(name){}

    double execute(){
        return 0.01 * getSource()->getValue();
    }
};

class FlowLogistic : public Flow
{
public:
    FlowLogistic(string name): Flow(name){}

    double execute(){
        return 0.01 * getTarget()->getValue() * (1 - getTarget()->getValue() / 70);
    }
};

class FlowComplexF: public Flow
{
public:
    FlowComplexF(string name): Flow(name){}

    double execute(){
        return 0.01 * getSource()->getValue();
    }
};

class FlowComplexG: public Flow
{
public:
    FlowComplexG(string name): Flow(name){}

    double execute(){
        return 0.01 * getSource()->getValue();
    }
};

class FlowComplexT: public Flow
{
public:
    FlowComplexT(string name): Flow(name){}

    double execute(){
        return 0.01 * getSource()->getValue();
    }
};

class FlowComplexR: public Flow
{
public:
    FlowComplexR(string name): Flow(name){}

    double execute(){
        return 0.01 * getSource()->getValue();
    }
};

class FlowComplexU: public Flow
{
public:
    FlowComplexU(string name): Flow(name){}

    double execute(){
        return 0.01 * getSource()->getValue();
    }
};

class FlowComplexV: public Flow
{
public:
    FlowComplexV(string name): Flow(name){}

    double execute(){
        return 0.01 * getSource()->getValue();
    }
};

void exponentialFuncionalTest()
{
    cout << "Teste Exponencial [INICIADO]" << endl;
    IModel *m1 = new Model;
    System *pop1 = new System("pop1", 100);
    System *pop2 = new System("pop2", 0);
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
    IModel *m1 = new Model;
    System *p1 = new System("p1", 100);
    System *p2 = new System("p2", 10);
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
    IModel *m1 = new Model;
    System *q1 = new System("q1", 100);
    System *q2 = new System("q2", 0);
    System *q3 = new System("q3", 100);
    System *q4 = new System("q4", 0);
    System *q5 = new System("q5", 0);
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
