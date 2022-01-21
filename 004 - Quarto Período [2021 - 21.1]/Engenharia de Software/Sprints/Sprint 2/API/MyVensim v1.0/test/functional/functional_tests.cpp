#include "functional_tests.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 
#include <cmath>

#define ENTRADA 1
#define SAIDA 0

#include "..\..\src\Model.hpp"

void exponentialFuncionalTest()
{
    cout << "Teste Exponencial [INICIADO]" << endl;
    Model m1(0, 10);
    System *pop2 = new System;
    System *pop1 = new System;
    Flow *exponencial = new Flow;

    pop1->setValue(100);
    pop2->setValue(0);
    exponencial->setInput(pop1);
    exponencial->setOutput(pop2);
    exponencial->setEquation(0.01, ENTRADA);
    m1.add(exponencial);
    m1.run();

    cout << "$ (1) " << pop1->getValue() << endl;
    cout << "$ (2) " << pop2->getValue() << endl;

    assert(abs((pop1->getValue() - 90.4382)) < 0.0001);
    assert(abs((pop2->getValue() - 9.56179)) < 0.0001);

    cout << "Teste Exponencial [FINALIZADO]" << endl;
}

void logisticalFuncionalTest()
{
    cout << "Teste Logistico [INICIADO]" << endl;
    int PMax = 70;
    Model m1(0, 10);
    System *p1 = new System;
    System *p2 = new System;
    Flow *logistica = new Flow;

    p1->setValue(100);
    p2->setValue(10);
    logistica->setInput(p1);
    logistica->setOutput(p2);
    logistica->setEquation(0.01, SAIDA, PMax);
    m1.add(logistica);
    m1.run();

    cout << "$ (1) " << p1->getValue() << endl;
    cout << "$ (2) " << p2->getValue() << endl;
    
    assert(abs((p1->getValue() - 99.1151)) < 0.0001);
    assert(abs((p2->getValue() - 10.8849)) < 0.0001);

    cout << "Teste Logistico [FINALIZADO]" << endl;
}

void complexFuncionalTest()
{
    cout << "Teste Complexo [INICIADO]" << endl;
    Model m1(0, 10);
    System *q1 = new System;
    System *q2 = new System;
    System *q3 = new System;
    System *q4 = new System;
    System *q5 = new System;
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
    f->setEquation(0.01, ENTRADA);

    g->setInput(q1);
    g->setOutput(q3);
    g->setEquation(0.01, ENTRADA);

    t->setInput(q2);
    t->setOutput(q3);
    t->setEquation(0.01, ENTRADA);

    r->setInput(q2);
    r->setOutput(q5);
    r->setEquation(0.01, ENTRADA);

    u->setInput(q3);
    u->setOutput(q4);
    u->setEquation(0.01, ENTRADA);

    v->setInput(q4);
    v->setOutput(q1);
    v->setEquation(0.01, ENTRADA);

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

    assert(abs((q1->getValue() - 82.1225)) < 0.0001);
    assert(abs((q2->getValue() - 8.34847)) < 0.0001);
    assert(abs((q3->getValue() - 99.574)) < 0.0001);
    assert(abs((q4->getValue() - 9.55041)) < 0.0001);
    assert(abs((q5->getValue() - 0.404639)) < 0.0001);

    cout << "Teste Complexo [FINALIZADO]" << endl;
}
