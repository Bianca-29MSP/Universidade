/********************************************************************************
** Form generated from reading ui file 'CalculadoraWnd.ui'
**
** Created: Mon May 3 16:49:51 2010
**      by: Qt User Interface Compiler version 4.3.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Abrir;
    QAction *action_Salvar;
    QAction *actionSai_r;
    QAction *action_Copia;
    QWidget *centralwidget;
    QLabel *label_2;
    QLabel *label_3;
    QTextEdit *textEditResult;
    QLabel *label_4;
    QPushButton *exitButton;
    QLabel *label;
    QPushButton *execButton;
    QGroupBox *groupBox;
    QRadioButton *radioButtonMult;
    QRadioButton *radioButtonSoma;
    QRadioButton *radioButtonSub;
    QRadioButton *radioButtonDiv;
    QDoubleSpinBox *doubleSpinBox2;
    QDoubleSpinBox *doubleSpinBox1;
    QMenuBar *menubar;
    QMenu *menuE_xit;
    QMenu *menu_Arquivo;
    QMenu *menuEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(545, 354);
        action_Abrir = new QAction(MainWindow);
        action_Abrir->setObjectName(QStringLiteral("action_Abrir"));
        action_Salvar = new QAction(MainWindow);
        action_Salvar->setObjectName(QStringLiteral("action_Salvar"));
        actionSai_r = new QAction(MainWindow);
        actionSai_r->setObjectName(QStringLiteral("actionSai_r"));
        action_Copia = new QAction(MainWindow);
        action_Copia->setObjectName(QStringLiteral("action_Copia"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 40, 46, 14));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 110, 46, 14));
        textEditResult = new QTextEdit(centralwidget);
        textEditResult->setObjectName(QStringLiteral("textEditResult"));
        textEditResult->setEnabled(true);
        textEditResult->setGeometry(QRect(80, 180, 431, 64));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 210, 52, 16));
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(440, 250, 75, 23));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(98, 250, 321, 30));
        label->setLayoutDirection(Qt::RightToLeft);
        label->setAlignment(Qt::AlignCenter);
        execButton = new QPushButton(centralwidget);
        execButton->setObjectName(QStringLiteral("execButton"));
        execButton->setGeometry(QRect(10, 250, 75, 23));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(360, 10, 151, 151));
        radioButtonMult = new QRadioButton(groupBox);
        radioButtonMult->setObjectName(QStringLiteral("radioButtonMult"));
        radioButtonMult->setGeometry(QRect(10, 90, 83, 18));
        radioButtonMult->setChecked(false);
        radioButtonSoma = new QRadioButton(groupBox);
        radioButtonSoma->setObjectName(QStringLiteral("radioButtonSoma"));
        radioButtonSoma->setGeometry(QRect(10, 30, 83, 18));
        radioButtonSoma->setChecked(true);
        radioButtonSub = new QRadioButton(groupBox);
        radioButtonSub->setObjectName(QStringLiteral("radioButtonSub"));
        radioButtonSub->setGeometry(QRect(10, 60, 83, 18));
        radioButtonDiv = new QRadioButton(groupBox);
        radioButtonDiv->setObjectName(QStringLiteral("radioButtonDiv"));
        radioButtonDiv->setGeometry(QRect(10, 120, 83, 18));
        doubleSpinBox2 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox2->setObjectName(QStringLiteral("doubleSpinBox2"));
        doubleSpinBox2->setGeometry(QRect(80, 90, 261, 61));
        doubleSpinBox1 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox1->setObjectName(QStringLiteral("doubleSpinBox1"));
        doubleSpinBox1->setGeometry(QRect(80, 20, 261, 61));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 545, 21));
        menuE_xit = new QMenu(menubar);
        menuE_xit->setObjectName(QStringLiteral("menuE_xit"));
        menu_Arquivo = new QMenu(menubar);
        menu_Arquivo->setObjectName(QStringLiteral("menu_Arquivo"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
#ifndef QT_NO_SHORTCUT
        label_4->setBuddy(textEditResult);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(textEditResult, radioButtonSoma);
        QWidget::setTabOrder(radioButtonSoma, radioButtonSub);
        QWidget::setTabOrder(radioButtonSub, radioButtonMult);
        QWidget::setTabOrder(radioButtonMult, radioButtonDiv);
        QWidget::setTabOrder(radioButtonDiv, execButton);
        QWidget::setTabOrder(execButton, exitButton);

        menubar->addAction(menu_Arquivo->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuE_xit->menuAction());
        menu_Arquivo->addAction(action_Abrir);
        menu_Arquivo->addAction(action_Salvar);
        menu_Arquivo->addSeparator();
        menu_Arquivo->addAction(actionSai_r);
        menuEdit->addAction(action_Copia);

        retranslateUi(MainWindow);
        QObject::connect(exitButton, SIGNAL(clicked()), MainWindow, SLOT(close()));
        QObject::connect(radioButtonSoma, SIGNAL(toggled(bool)), execButton, SLOT(click()));
        QObject::connect(radioButtonSub, SIGNAL(toggled(bool)), execButton, SLOT(click()));
        QObject::connect(radioButtonMult, SIGNAL(toggled(bool)), execButton, SLOT(click()));
        QObject::connect(radioButtonDiv, SIGNAL(toggled(bool)), execButton, SLOT(click()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Minha Calculadora", nullptr));
        action_Abrir->setText(QApplication::translate("MainWindow", "&Abrir", nullptr));
        action_Salvar->setText(QApplication::translate("MainWindow", "&Salvar", nullptr));
        actionSai_r->setText(QApplication::translate("MainWindow", "Sai&r", nullptr));
        action_Copia->setText(QApplication::translate("MainWindow", "&Copia", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Parcela 1:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Parcela 2:", nullptr));
        textEditResult->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">0</span></p></body></html>", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Resultado:", nullptr));
        exitButton->setText(QApplication::translate("MainWindow", "Sair", nullptr));
        label->setText(QApplication::translate("MainWindow", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal; text-decoration:none;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt; font-weight:600;\">C A L C U L A D O R A</span></p></body></html>", nullptr));
        execButton->setText(QApplication::translate("MainWindow", "Executar", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Opera\303\247\303\265es", nullptr));
        radioButtonMult->setText(QApplication::translate("MainWindow", "Multipilica\303\247\303\243o", nullptr));
        radioButtonSoma->setText(QApplication::translate("MainWindow", "Soma", nullptr));
        radioButtonSub->setText(QApplication::translate("MainWindow", "Subtra\303\247\303\243o", nullptr));
        radioButtonDiv->setText(QApplication::translate("MainWindow", "Divis\303\243o", nullptr));
        menuE_xit->setTitle(QApplication::translate("MainWindow", "E&xit", nullptr));
        menu_Arquivo->setTitle(QApplication::translate("MainWindow", "&Arquivo", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "&Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
