#ifndef TESTESCALCULADORA_H
#define TESTESCALCULADORA_H

#include <QMainWindow>
#include <QtTest/QtTest>
#include <QtDebug>
#include <QMessageBox>
#include <QTimer>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QString>
#include <QRadioButton>
#include <iostream>
#include "../QuartaWidgetApp/MyAutoMainWindow.h"
#include "ui_testescalculadora.h"

class testesCalculadora : public QObject
{
    Q_OBJECT

public:
    testesCalculadora(QWidget *parent = nullptr);
    ~testesCalculadora();

private slots:
    void testesOp();

private:
    MyAutoMainWindow w;
    QString resultadoString;
    QTextEdit resultadoText;
};
#endif
