#include "testescalculadora.h"

testesCalculadora::testesCalculadora(QWidget *parent)
    : QObject(parent){
}

testesCalculadora::~testesCalculadora(){
}

void testesCalculadora::testesOp(){
    // Ouput
    QString aux;

    // Input
    QTest::addColumn<QString>("parcela1");
    QTest::addColumn<QString>("parcela2");
    QTest::addColumn<QRadioButton*>("buttonRadio");
    QTest::addColumn<QPushButton*>("buttonPush");

    // Testing subtraction
    QTest::newRow("test sub 1") << "10" << "30" << w.ui->radioButtonSub << w.ui->execButton;
    aux = w.ui->plainTextEditResult->toPlainText();
    QCOMPARE(QString(aux), "-20");

    QTest::newRow("test sub 2") << "-5" << "20" << w.ui->radioButtonSub << w.ui->execButton;
    aux = w.ui->plainTextEditResult->toPlainText();
    QCOMPARE(QString(aux), "-25");

    QTest::newRow("test sub 3") << "10" << "-200" << w.ui->radioButtonSub << w.ui->execButton;
    aux = w.ui->plainTextEditResult->toPlainText();
    QCOMPARE(QString(aux), "210");

    QTest::newRow("test sub 4") << "-10" << "-20" << w.ui->radioButtonSub << w.ui->execButton;
    aux = w.ui->plainTextEditResult->toPlainText();
    QCOMPARE(QString(aux), "10");

    // Testing sum
    QTest::newRow("test sum 1") << "10" << "20" << w.ui->radioButtonSoma << w.ui->execButton;
    aux = w.ui->plainTextEditResult->toPlainText();
    QCOMPARE(QString(aux), "30");

    QTest::newRow("test sum 2") << "-10" << "20" << w.ui->radioButtonSoma << w.ui->execButton;
    aux = w.ui->plainTextEditResult->toPlainText();
    QCOMPARE(QString(aux), "10");

    QTest::newRow("test sum 3") << "10" << "-20" << w.ui->radioButtonSoma << w.ui->execButton;
    aux = w.ui->plainTextEditResult->toPlainText();
    QCOMPARE(QString(aux), "-10");

    QTest::newRow("test sum 4") << "-10" << "-20" << w.ui->radioButtonSoma << w.ui->execButton;
    aux = w.ui->plainTextEditResult->toPlainText();
    QCOMPARE(QString(aux), "-30");

    // Testing multiplication
    QTest::newRow("test multi 1") << "10" << "20" << w.ui->radioButtonMult << w.ui->execButton;
    aux = w.ui->plainTextEditResult->toPlainText();
    QCOMPARE(QString(aux), "200");

    QTest::newRow("test multi 2") << "0" << "20" << w.ui->radioButtonMult << w.ui->execButton;
    aux = w.ui->plainTextEditResult->toPlainText();
    QCOMPARE(QString(aux), "0");

    QTest::newRow("test multi 3") << "1" << "20" << w.ui->radioButtonMult << w.ui->execButton;
    aux = w.ui->plainTextEditResult->toPlainText();
    QCOMPARE(QString(aux), "20");

    QTest::newRow("test multi 4") << "-10" << "20" << w.ui->radioButtonMult << w.ui->execButton;
    aux = w.ui->plainTextEditResult->toPlainText();
    QCOMPARE(QString(aux), "-20");

    // Testing division
    QTest::newRow("test divi 1") << "2" << "100" << w.ui->radioButtonDiv << w.ui->execButton;
    aux = w.ui->plainTextEditResult->toPlainText();
    QCOMPARE(QString(aux), "0.02");

    QTest::newRow("test divi 2") << "10" << "0" << w.ui->radioButtonDiv << w.ui->execButton;
    aux = w.ui->plainTextEditResult->toPlainText();
    QCOMPARE(QString(aux), "inf");

    QTest::newRow("test divi 3") << "10" << "1" << w.ui->radioButtonDiv << w.ui->execButton;
    aux = w.ui->plainTextEditResult->toPlainText();
    QCOMPARE(QString(aux), "1");

    QTest::newRow("test divi 4") << "40" << "-4" << w.ui->radioButtonDiv << w.ui->execButton;
    aux = w.ui->plainTextEditResult->toPlainText();
    QCOMPARE(QString(aux), "-10");

    // Testing the exit button
    QTest::newRow("exit button") << "" << "" << w.ui->radioButtonSoma << w.ui->exitButton;
    QTest::newRow("exit button") << "" << "" << w.ui->radioButtonSub << w.ui->exitButton;
    QTest::newRow("exit button") << "" << "" << w.ui->radioButtonMult << w.ui->exitButton;
    QTest::newRow("exit button ") << "" << "" << w.ui->radioButtonDiv << w.ui->exitButton;
}
