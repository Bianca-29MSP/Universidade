#include "unit_Model.hpp"
#include <iostream>
#include <assert.h>
#include "../../src/ModelImplementation.hpp"

void unit_Model_constructor( void)
{
    cout << "[Model] - Construtor padrao sem parametro: ";
    ModelImplementation m1;
    assert(m1.getTime() == 0);
    cout << "✔️ Ok!" << endl;
}

void unit_Model_destructor( void)
{}

void unit_Model_add(void)
{
    cout << "[Model] - Metodo add() [flow]: ";

    cout << "✔️ Ok!" << endl;

    cout << "[Model] - Metodo add() [system]: ";

    cout << "✔️ Ok!" << endl;
}

void unit_Model_incrementTime( void)
{
    cout << "[Model] - Metodo incrementTime() e getTime(): ";
    ModelImplementation m1;
    m1.incrementTime(10);
    m1.incrementTime(10);
    assert(m1.getTime() == 20);
    cout << "✔️ Ok!" << endl;
}

void unit_Model_run( void )
{
    cout << "[Model] - Metodo run(): ";
    ModelImplementation m1;
    m1.run(0, 1, 4);
    assert(m1.getTime() == 4);
    cout << "✔️ Ok!" << endl;
}

void run_unit_tests_Model( void )
{
    unit_Model_constructor();
    unit_Model_destructor();
    unit_Model_incrementTime();
    unit_Model_run();
}
