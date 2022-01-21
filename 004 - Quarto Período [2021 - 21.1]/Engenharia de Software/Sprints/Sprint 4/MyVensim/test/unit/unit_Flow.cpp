#include "unit_Flow.hpp"
#include <iostream>
#include <assert.h>
#include "..\..\src\Flow.hpp"

void unit_Flow_constructor( void)
{
    cout << "[Flow] - Construtor padrao sem parametro: ";
    Flow f1;
    assert(f1.getInput() == NULL);
    assert(f1.getOutput() == NULL);
    cout << "Ok!" << endl;

    cout << "[Flow] - Construtor com parametro de nome: ";
    Flow f2("F2");
    assert(f2.getName() == "F2");
    assert(f2.getInput() == NULL);
    assert(f2.getOutput() == NULL);
    cout << "Ok!" << endl;
}

void unit_Flow_destructor( void)
{}

void unit_Flow_setInput( void)
{
    cout << "[Flow] - Metodo setInput() e getInput(): ";
    Flow f1("F1");
    System *s2 = new System("Sistema de entrada do F1");
    f1.setInput(s2);
    assert(s2 == f1.getInput());
    assert(f1.getInput()->getName() == s2->getName());
    cout << "Ok!" << endl;
}

void unit_Flow_setOutput( void)
{
    cout << "[Flow] - Metodo setOutput() e getOutput(): ";
    Flow f1("F1");
    System *s2 = new System("Sistema de saida do F1");
    f1.setOutput(s2);
    assert(s2 == f1.getOutput());
    assert(f1.getOutput()->getName() == s2->getName());
    cout << "Ok!" << endl;
}

void unit_Flow_setEquation( void)
{
    cout << "[Flow] - Metodo setEquation() sem PMax : ";
    Flow f1("F1");
    f1.setEquation(0.4, "");
    assert(f1.getConstant() == 0.4);
    assert(f1.getObservedSystem() == "");
    cout << "Ok!" << endl;

    cout << "[Flow] - Metodo setEquation() com PMax : ";
    Flow f2("F2");
    f2.setEquation(0.4, "", 8);
    assert(f2.getConstant() == 0.4);
    assert(f2.getObservedSystem() == "");
    assert(f2.getPMax() == 8);
    cout << "Ok!" << endl;
}

void unit_Flow_setName( void)
{
    cout << "[Flow] - Metodo setName() e getName() : ";
    Flow f1;
    f1.setName("Nome F1");
    assert(f1.getName() == "Nome F1");
    cout << "Ok!" << endl;
}

void unit_Flow_run_exponencial( void)
{
    cout << "[Flow] - Metodo exponencial : ";
    Flow f1;
    System *s1 = new System("S1");
    assert(f1.exponential(s1) == 0);
    cout << "Ok!" << endl;
}

void unit_Flow_run_logistical( void)
{
    cout << "[Flow] - Metodo logistico com PMax padrao [0]: ";
    Flow f1;
    System *s1 = new System("S1");
    assert(f1.logistical(s1) == -1);
    cout << "Ok!" << endl;

    cout << "[Flow] - Metodo logistico com PMax setado: ";
    Flow f2;
    System *s2 = new System("S2");
    f2.setEquation(0, "S2", 1);
    assert(f2.logistical(s2) == 0);
    cout << "Ok!" << endl;
}

void unit_Flow_run( void ) 
{
    cout << "[Flow] - Metodo run: ";
    Flow f1("F1");
    assert(f1.run() == 0);
    cout << "Ok!" << endl;
}

void unit_Flow_assignmentOperator( void)
{
    cout << "[Flow] - Metodo da sobrecarga da atribuicao: ";
    Flow f1("Flow original [P1]");
    Flow f2;
    f2 = f1;

    f1.setName("Novo nome [P1]");

    assert(f1.getName() == "Novo nome [P1]");
    assert(f2.getName() == "Flow original [P1]");
    cout << "Ok!" << endl;
}

void run_unit_tests_Flow( void )
{
    unit_Flow_constructor();
    unit_Flow_setInput();
    unit_Flow_setOutput();
    unit_Flow_setEquation();
    unit_Flow_setName();
    unit_Flow_run_exponencial();
    unit_Flow_run_logistical();
    unit_Flow_run();
    unit_Flow_assignmentOperator();
}
