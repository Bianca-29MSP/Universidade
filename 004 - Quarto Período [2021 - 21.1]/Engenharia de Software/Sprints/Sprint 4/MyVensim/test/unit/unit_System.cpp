#include "unit_System.hpp"
#include <iostream>
#include <assert.h>
#include "..\..\src\System.hpp"

void unit_System_constructor( void)
{
    cout << "[System] - Construtor padrao sem parametro: ";
    System s1;
    assert(s1.getValue() == 0);
    cout << "Ok!" << endl;

    cout << "[System] - Construtor com parametro de nome: ";
    System s2("S2");
    assert(s2.getValue() == 0);
    assert(s2.getName() == "S2");
    cout << "Ok!" << endl;
}

void unit_System_destructor( void)
{}

void unit_System_setName( void)
{
    cout << "[System] - Metodo setName() e getName(): ";
    System s1;
    s1.setName("S1");
    assert(s1.getName() == "S1");
    cout << "Ok!" << endl;
}

void unit_System_setValue( void)
{
    cout << "[System] - Metodo setValue() e getValue(): ";
    System s1;
    s1.setValue(44);
    assert(s1.getValue() == 44);
    cout << "Ok!" << endl;
}

void unit_System_assignmentOperator( void)
{
    cout << "[System] - Metodo da sobrecarga da atribuicao: ";
    System s1("Sistema original [S1]");
    s1.setValue(44);
    System s2;
    s2 = s1;

    s1.setName("Novo nome [S1]");
    s1.setValue(20);

    assert(s1.getName() == "Novo nome [S1]");
    assert(s2.getName() == "Sistema original [S1]");
    
    cout << "Ok!" << endl;
}

void run_unit_tests_System( void )
{
    unit_System_constructor();
    unit_System_setName();
    unit_System_setValue();
    unit_System_assignmentOperator();
}

