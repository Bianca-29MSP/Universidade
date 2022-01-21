#include "unit_Flow.hpp"
#include <iostream>
#include <assert.h>
#include "../../src/FlowImplementation.hpp"

class FlowTest : public FlowImplementation
{
public:
    FlowTest(): FlowImplementation(){}
    FlowTest(string name): FlowImplementation(name){}
    FlowTest(const FlowTest *flow): FlowImplementation(flow){}

    double execute(){
        return 5 * (9 / 3) + 4;
    }
};

void unit_Flow_constructor( void)
{
    cout << "[Flow] - Construtor padrao sem parametro: ";
    FlowTest f1;
    assert(f1.getSource() == NULL);
    assert(f1.getTarget() == NULL);
    cout << "✔️ Ok!" << endl;

    cout << "[Flow] - Construtor com parametro de nome: ";
    FlowTest f2("f2");
    assert(f2.getSource() == NULL);
    assert(f2.getTarget() == NULL);
    cout << "✔️ Ok!" << endl;
    
    cout << "[Flow] - Construtor de copia: ";
    FlowTest *f3 = new FlowTest("f2");
    FlowTest *f4 = new FlowTest(f3);
    assert(f4->getName() == f3->getName());
    cout << "✔️ Ok!" << endl;
}

void unit_Flow_destructor( void)
{}

void unit_Flow_setCurrentValue( void)
{
    cout << "[Flow] - Metodo setCurrentValue() e getCurrentValue(): ";
    FlowTest f1 ;
    f1.setCurrentValue(4.4);
    assert(f1.getCurrentValue() == 4.4);
    cout << "✔️ Ok!" << endl;
}

void unit_Flow_setSource( void)
{
    cout << "[Flow] - Metodo setSource() e getSource(): ";
    FlowTest f1 ;
    f1.setSource(NULL);
    assert(f1.getSource() == NULL);
    cout << "✔️ Ok!" << endl;
}

void unit_Flow_setTarget( void)
{
    cout << "[Flow] - Metodo setTarget() e getTarget(): ";
    FlowTest f1 ;
    f1.setTarget(NULL);
    assert(f1.getTarget() == NULL);
    cout << "✔️ Ok!" << endl;
}

void unit_Flow_connect( void)
{
    cout << "[Flow] - Metodo connect: ";
    FlowTest f1 ;
    f1.connect(NULL, NULL);
    assert(f1.getSource() == NULL);
    assert(f1.getTarget() == NULL);
    cout << "✔️ Ok!" << endl;

}

void unit_Flow_setName( void)
{
    cout << "[Flow] - Metodo setName() e getName() : ";
    FlowTest f1 ;
    f1.setName("fluxo 1");
    assert(f1.getName() == "fluxo 1");
    cout << "✔️ Ok!" << endl;
}

void unit_Flow_execute( void ) 
{
    cout << "[Flow] - Metodo execute: ";
    FlowTest f1 ;
    assert(f1.execute() == 19);
    cout << "✔️ Ok!" << endl;
}

void unit_Flow_assignmentOperator( void)
{
    cout << "[Flow] - Metodo da sobrecarga da atribuicao: ";
   
    cout << "✔️ Ok!" << endl;
}

void run_unit_tests_Flow( void )
{
    unit_Flow_constructor();
    unit_Flow_destructor();
    unit_Flow_setSource();
    unit_Flow_setCurrentValue();
    unit_Flow_setTarget();
    unit_Flow_connect();
    unit_Flow_setName();
    unit_Flow_execute();
    unit_Flow_assignmentOperator();
}
