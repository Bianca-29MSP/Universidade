/********************************************************************************
** Form generated from reading UI file 'loginWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QTextEdit *nomeTextEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QTextEdit *senhaTextEdit;
    QSpacerItem *verticalSpacer_2;
    QPushButton *continueButton;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QStringLiteral("LoginWindow"));
        LoginWindow->resize(388, 316);
        centralWidget = new QWidget(LoginWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(50, 20, 301, 166));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        nomeTextEdit = new QTextEdit(verticalLayoutWidget);
        nomeTextEdit->setObjectName(QStringLiteral("nomeTextEdit"));

        horizontalLayout_2->addWidget(nomeTextEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        senhaTextEdit = new QTextEdit(verticalLayoutWidget);
        senhaTextEdit->setObjectName(QStringLiteral("senhaTextEdit"));

        horizontalLayout_3->addWidget(senhaTextEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        continueButton = new QPushButton(centralWidget);
        continueButton->setObjectName(QStringLiteral("continueButton"));
        continueButton->setGeometry(QRect(260, 230, 75, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(180, 230, 75, 23));
        LoginWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LoginWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 388, 21));
        LoginWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LoginWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        LoginWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(LoginWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        LoginWindow->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
        label->setBuddy(nomeTextEdit);
        label_2->setBuddy(senhaTextEdit);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(nomeTextEdit, senhaTextEdit);
        QWidget::setTabOrder(senhaTextEdit, continueButton);
        QWidget::setTabOrder(continueButton, pushButton_2);

        retranslateUi(LoginWindow);
        QObject::connect(pushButton_2, SIGNAL(clicked()), LoginWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("LoginWindow", "&Nome:", nullptr));
        label_2->setText(QApplication::translate("LoginWindow", "&Senha:", nullptr));
        continueButton->setText(QApplication::translate("LoginWindow", "&continuar", nullptr));
        pushButton_2->setText(QApplication::translate("LoginWindow", "&sair", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
