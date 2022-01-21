#include "unit_System.hpp"
#include <iostream>
#include <assert.h>
#include "../../src/SystemImplementation.hpp"

void unit_System_constructor( void)
{
    cout << "[System] - Construtor padrao sem parametro: ";
    SystemImplementation s1 = new SystemImplementation();
    assert(s1.getValue() == 0);
    cout << "✔️ Ok!" << endl;

    cout << "[System] - Construtor com parametro de nome: ";
    SystemImplementation s2 = new SystemImplementation("S2");
    assert(s2.getValue() == 0);
    assert(s2.getName() == "S2");
    cout << "✔️ Ok!" << endl;

    cout << "[System] - Construtor com parametro de nome e valor: ";
    SystemImplementation s3 = new SystemImplementation("S2", 44);
    assert(s3.getValue() == 44);
    assert(s3.getName() == "S2");
    cout << "✔️ Ok!" << endl;

    cout << "[System] - Construtor de copia: ";
    SystemImplementation s4 = new SystemImplementation("S2", 44);
    SystemImplementation s5 = new SystemImplementation(s4);
    assert(s5.getValue() == s4.getValue());
    assert(s5.getName() == s4.getName());
    cout << "✔️ Ok!" << endl;
}

void unit_System_destructor( void)
{}

void unit_System_setName( void)
{
    cout << "[System] - Metodo setName() e getName(): ";
    SystemImplementation s1 = new SystemImplementation();
    s1.setName("S1");
    assert(s1.getName() == "S1");
    cout << "✔️ Ok!" << endl;
}

void unit_System_setValue( void)
{
    cout << "[System] - Metodo setValue() e getValue(): ";
    SystemImplementation s1 = new SystemImplementation();
    s1.setValue(44);
    assert(s1.getValue() == 44);
    cout << "✔️ Ok!" << endl;
}

void unit_System_assignmentOperator( void)
{
    cout << "[System] - Metodo da sobrecarga da atribuicao: ";
    SystemImplementation s1 = new SystemImplementation("Sistema original [S1]");
    s1.setValue(44);
    SystemImplementation s2 = new SystemImplementation();
    s2 = s1;

    s1.setName("Novo nome [S1]");
    s1.setValue(20);

    assert(s1.getName() == "Novo nome [S1]");
    assert(s2.getName() == "Sistema original [S1]");
    
    cout << "✔️ Ok!" << endl;
}

void run_unit_tests_System( void )
{
    unit_System_constructor();
    unit_System_setName();
    unit_System_setValue();
    unit_System_assignmentOperator();
}

