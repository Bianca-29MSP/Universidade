#include "unit_System.hpp"
#include<iostream>
#include<assert.h>
#include "./utils/mem_usage.hpp"
#include "../../src/System.hpp"

void unit_System_constructor( void)
{
    cout << "[System] - Construtor padrao sem parametro: ";
    ISystem *s1 = new System();
    assert(s1->getValue() == 0);
    cout << "Ok!" << endl;

    cout << "[System] - Construtor com parametro de nome: ";
    ISystem *s2 = new System("S2");
    assert(s2->getValue() == 0);
    assert(s2->getName() == "S2");
    cout << "Ok!" << endl;

    cout << "[System] - Construtor com parametro de nome e valor: ";
    ISystem *s3 = new System("S2", 44);
    assert(s3->getValue() == 44);
    assert(s3->getName() == "S2");
    cout << "Ok!" << endl;

    cout << "[System] - Construtor de copia: ";
    System *s4 = new System("S2", 44);
    System *s5 = new System(s4);
    assert(s5->getValue() == s4->getValue());
    assert(s5->getName() == s4->getName());
    cout << "Ok!" << endl;
}

void unit_System_destructor( void)
{
    cout << "[System] - Destrutor padrao: ";
    double memoryBefore, memoryAfter, rss;

    mem_usage(memoryBefore, rss);

    ISystem* s1 = new System();
    delete s1;

    mem_usage(memoryAfter, rss);

    assert(memoryBefore == memoryAfter);
    cout << "Ok!" << endl;
}

void unit_System_setName( void)
{
    cout << "[System] - Metodo setName() e getName(): ";
    ISystem * s1 = new System();
    s1->setName("S1");
    assert(s1->getName() == "S1");
    cout << "Ok!" << endl;
}

void unit_System_setValue(void)
{
    cout << "[System] - Metodo setValue() e getValue(): ";
    ISystem *s1 = new System();
    s1->setValue(44);
    assert(s1->getValue() == 44);
    cout << "Ok!" << endl;
}

void unit_System_assignmentOperator( void)
{
    cout << "[System] - Metodo da sobrecarga da atribuicao: ";
    System *s1 = new System("Sistema original [S1]");
    s1->setValue(44);
    System *s2 = new System();
    *s2 = *s1;

    s1->setName("Novo nome [S1]");
    s1->setValue(20);

    assert(s1->getName() == "Novo nome [S1]");
    assert(s2->getName() == "Sistema original [S1]");
    
    cout << "Ok!" << endl;
}

void run_unit_tests_System( void )
{
    unit_System_constructor();
    unit_System_destructor();
    unit_System_setName();
    unit_System_setValue();
    unit_System_assignmentOperator();
}

