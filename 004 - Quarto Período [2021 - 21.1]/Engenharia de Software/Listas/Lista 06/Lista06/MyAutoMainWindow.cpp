#include "MyAutoMainWindow.h"
#include "ui_MainWindow.h"
#include <QDoubleSpinBox>

MyAutoMainWindow::MyAutoMainWindow(QWidget *parent) : QMainWindow(parent)
{
    setupUi(this);
    // A linha de codigo comentada abaixo n�o � necess�ria
    //connect( execButton, SIGNAL( clicked() ), this, SLOT( operacao() ));
}

void MyAutoMainWindow::on_execButton_clicked( void ){

     // F�cil acessar widgets e auto-conectado

     float parcela1 = doubleSpinBox1->value();
     float parcela2 = doubleSpinBox2->value();


     float result = 0;
     if( radioButtonSoma->isChecked() ) result = parcela1+ parcela2;
     else
     if( radioButtonSub->isChecked() ) result = parcela1 - parcela2;
     else
     if( radioButtonMult->isChecked() ) result = parcela1 * parcela2;
     else
     if( radioButtonDiv->isChecked() ) result = parcela1 / parcela2;

     QString resultStr;
     resultStr.setNum( result );
     textEditResult->setText( resultStr );

}
