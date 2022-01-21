#include "unit_Model.hpp"
#include <iostream>
#include <assert.h>
#include "..\..\src\Model.hpp"

void unit_Model_constructor( void)
{
    cout << "[Model] - Construtor padrao sem parametro: ";
    Model m1;
    assert(m1.getInitialTime() == 0);
    assert(m1.getFinalTime() == 0);
    cout << "Ok!" << endl;

    cout << "[Model] - Construtor com parametro de valor inicial e valor final: ";
    Model m2(0, 100);
    assert(m2.getInitialTime() == 0);
    assert(m2.getFinalTime() == 100);
    cout << "Ok!" << endl;
}

void unit_Model_destructor( void)
{}

void unit_Model_add( void)
{
    cout << "[Model] - Metodo add(): ";
    Model m2(0, 100);
    Flow *f1 = new Flow("F1");
    m2.add(f1);
    assert(m2.getFlows().size() == 1);
    cout << "Ok!" << endl;
}

void unit_Model_setInitialTime( void)
{
    cout << "[Model] - Metodo setInitialTime() e getInitialTime(): ";
    Model m1;
    m1.setFinalTime(100);
    assert(m1.getInitialTime() == 0);
    cout << "Ok!" << endl;
}

void unit_Model_setFinalTime( void)
{
    cout << "[Model] - Metodo setFinalTime() e getFinalTime(): ";
    Model m1;
    m1.setFinalTime(100);
    assert(m1.getFinalTime() == 100);
    cout << "Ok!" << endl;
}

void unit_Model_run( void )
{
    cout << "[Model] - Metodo run(): ";
    Model m1(0, 1);
    Flow *f1 = new Flow("F1");
    System *s1 = new System("S1");
    f1->setOutput(s1);
    f1->setEquation(0.1, "S1");
    s1->setValue(2);
    m1.add(f1);
    m1.run();

    assert(s1->getValue() == 2.2);
    cout << "Ok!" << endl;
}

void unit_Model_assignmentOperator( void)
{
    cout << "[Model] - Metodo da sobrecarga da atribuicao: ";
    Model m1(0, 10);
    Model m2;
    m2 = m1;

    m1.setInitialTime(1);
    m1.setFinalTime(50);

    assert(m1.getInitialTime() == 1);
    assert(m1.getFinalTime() == 50);
    assert(m2.getInitialTime() == 0);
    assert(m2.getFinalTime() == 10);
    cout << "Ok!" << endl;
}

void run_unit_tests_Model( void )
{
    unit_Model_constructor();
    unit_Model_destructor();
    unit_Model_add();
    unit_Model_setInitialTime();
    unit_Model_setFinalTime();
    unit_Model_run();
    unit_Model_assignmentOperator();
}
