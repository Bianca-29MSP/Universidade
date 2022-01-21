#include "functional_tests.hpp"
#include <iostream>
#include <assert.h> 
#include <cmath>

#include "..\..\src\Model.hpp"

void exponentialFuncionalTest()
{
    cout << "Teste Exponencial [INICIADO]" << endl;
    Model m1(0, 100);
    System *pop1 = new System("pop1");
    System *pop2 = new System("pop2");
    Flow *exponencial = new Flow;

    pop1->setValue(100);
    pop2->setValue(0);
    exponencial->setInput(pop1);
    exponencial->setOutput(pop2);
    exponencial->setEquation(0.01, "pop1");
    m1.add(exponencial);
    m1.run();

    cout << "$ (1) " << pop1->getValue() << endl;
    cout << "$ (2) " << pop2->getValue() << endl;

    assert(abs((pop1->getValue() - 36.6032)) < 0.0001);
    assert(abs((pop2->getValue() - 63.3968)) < 0.0001);

    cout << "Teste Exponencial [FINALIZADO]" << endl;
}

void logisticalFuncionalTest()
{
    cout << "Teste Logistico [INICIADO]" << endl;
    int PMax = 70;
    Model m1(0, 100);
    System *p1 = new System("p1");
    System *p2 = new System("p2");
    Flow *logistica = new Flow;

    p1->setValue(100);
    p2->setValue(10);
    logistica->setInput(p1);
    logistica->setOutput(p2);
    logistica->setEquation(0.01, "p2", PMax);
    m1.add(logistica);
    m1.run();

    cout << "$ (1) " << p1->getValue() << endl;
    cout << "$ (2) " << p2->getValue() << endl;
    
    assert(abs((p1->getValue() - 88.2167)) < 0.0001);
    assert(abs((p2->getValue() - 21.7833)) < 0.0001);

    cout << "Teste Logistico [FINALIZADO]" << endl;
}

void complexFuncionalTest()
{
    cout << "Teste Complexo [INICIADO]" << endl;
    Model m1(0, 100);
    System *q1 = new System("q1");
    System *q2 = new System("q2");
    System *q3 = new System("q3");
    System *q4 = new System("q4");
    System *q5 = new System("q5");
    Flow *f = new Flow;//f
    Flow *g = new Flow;//g
    Flow *t = new Flow;//t
    Flow *r = new Flow;//r
    Flow *u = new Flow;//u
    Flow *v = new Flow;//v

    q1->setValue(100.0);
    q2->setValue(0);
    q3->setValue(100.0);
    q4->setValue(0);
    q5->setValue(0);

    f->setInput(q1);
    f->setOutput(q2);
    f->setEquation(0.01, "q1");

    g->setInput(q1);
    g->setOutput(q3);
    g->setEquation(0.01, "q1");

    t->setInput(q2);
    t->setOutput(q3);
    t->setEquation(0.01, "q2");

    r->setInput(q2);
    r->setOutput(q5);
    r->setEquation(0.01, "q2");

    u->setInput(q3);
    u->setOutput(q4);
    u->setEquation(0.01, "q3");

    v->setInput(q4);
    v->setOutput(q1);
    v->setEquation(0.01, "q4");

    m1.add(f);
    m1.add(g);
    m1.add(t);
    m1.add(r);
    m1.add(u);
    m1.add(v);

    m1.run();

    cout << "$ (Q1) " << q1->getValue() << endl;
    cout << "$ (Q2) " << q2->getValue() << endl;
    cout << "$ (Q3) " << q3->getValue() << endl;
    cout << "$ (Q4) " << q4->getValue() << endl;
    cout << "$ (Q5) " << q5->getValue() << endl;

    assert(abs((q1->getValue() - 31.8513)) < 0.0001);
    assert(abs((q2->getValue() - 18.4003)) < 0.0001);
    assert(abs((q3->getValue() - 77.1143)) < 0.0001);
    assert(abs((q4->getValue() - 56.1728)) < 0.0001);
    assert(abs((q5->getValue() - 16.4612)) < 0.0001);

    cout << "Teste Complexo [FINALIZADO]" << endl;
}
