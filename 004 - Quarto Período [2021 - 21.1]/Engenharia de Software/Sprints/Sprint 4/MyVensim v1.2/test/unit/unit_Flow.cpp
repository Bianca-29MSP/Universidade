#include "unit_Flow.hpp"
#include <iostream>
#include <assert.h>
#include "./utils/mem_usage.hpp"
#include "../../src/Flow.hpp"
#include "../../src/System.hpp"

class FlowTest : public Flow
{
public:
    FlowTest(): Flow(){}
    FlowTest(string name): Flow(name){}
    FlowTest(const FlowTest *flow): Flow(flow){}

    double execute(){
        return 0.1 * getSource()->getValue();
    }
};

void unit_Flow_constructor( void)
{
    cout << "[Flow] - Construtor padrao sem parametro: ";
    FlowTest f1;
    assert(f1.getSource() == NULL);
    assert(f1.getTarget() == NULL);
    cout << "Ok!" << endl;

    cout << "[Flow] - Construtor com parametro de nome: ";
    FlowTest f2("f2");
    assert(f2.getSource() == NULL);
    assert(f2.getTarget() == NULL);
    cout << "Ok!" << endl;
    
    cout << "[Flow] - Construtor de copia: ";
    FlowTest *f3 = new FlowTest("f2");
    FlowTest *f4 = new FlowTest(f3);
    assert(f4->getName() == f3->getName());
    cout << "Ok!" << endl;
}

void unit_Flow_destructor( void)
{
    cout << "[Flow] - Destrutor padrao: ";
    double memoryBefore, memoryAfter, rss;

    mem_usage(memoryBefore, rss);

    FlowTest* f1 = new FlowTest();
    delete f1;

    mem_usage(memoryAfter, rss);

    assert(memoryBefore == memoryAfter);
    cout << "Ok!" << endl;
}

void unit_Flow_setCurrentValue( void)
{
    cout << "[Flow] - Metodo setCurrentValue() e getCurrentValue(): ";
    FlowTest f1 ;
    f1.setCurrentValue(4.4);
    assert(f1.getCurrentValue() == 4.4);
    cout << "Ok!" << endl;
}

void unit_Flow_setName( void)
{
    cout << "[Flow] - Metodo setName() e getName() : ";
    FlowTest f1 ;
    f1.setName("fluxo 1");
    assert(f1.getName() == "fluxo 1");
    cout << "Ok!" << endl;
}

void unit_Flow_setSource( void)
{
    cout << "[Flow] - Metodo setSource() e getSource(): ";
    FlowTest f1;
    System *s1 = new System("System 1", 100);
    f1.setSource(s1);
    assert(f1.getSource() == s1);
    cout << "Ok!" << endl;
}

void unit_Flow_setTarget( void)
{
    cout << "[Flow] - Metodo setTarget() e getTarget(): ";
    FlowTest f1 ;
    System *s1 = new System("System 1", 100);
    f1.setTarget(s1);
    assert(f1.getTarget() == s1);
    cout << "Ok!" << endl;
}

void unit_Flow_connect( void)
{
    cout << "[Flow] - Metodo connect: ";
    FlowTest f1 ;
    System *s1 = new System("System 1", 100);
    System *s2 = new System("System 2", 0);
    f1.connect(s1, s2);
    assert(f1.getSource() == s1);
    assert(f1.getTarget() == s2);
    cout << "Ok!" << endl;

}

void unit_Flow_execute( void ) 
{
    cout << "[Flow] - Metodo execute: ";
    FlowTest f1;
    System *s1 = new System("System 1", 100);
    f1.setSource(s1);
    assert(f1.execute() == 10);
    cout << "Ok!" << endl;
}

void unit_Flow_assignmentOperator(void)
{
    cout << "[Flow] - Metodo da sobrecarga da atribuicao: ";
    FlowTest f1("Flow 1 [Original]");
    FlowTest f2;
    f2 = f1;
    assert(f2.getName() == f1.getName());
    cout << "Ok!" << endl;

    cout << "[Flow] - Metodo da sobrecarga da atribuicao com alteracao de valor: ";
    FlowTest f3("Flow 1 [Original]");
    FlowTest f4;
    f4 = f3;
    f3.setName("Flow 1 [Novo nome]");
    assert(f4.getName() == "Flow 1 [Original]");
    cout << "Ok!" << endl;
}

void run_unit_tests_Flow( void )
{
    unit_Flow_constructor();
    unit_Flow_destructor();
    unit_Flow_setCurrentValue();
    unit_Flow_setName();
    unit_Flow_setSource();
    unit_Flow_setTarget();
    unit_Flow_connect();
    unit_Flow_execute();
    unit_Flow_assignmentOperator();
}
