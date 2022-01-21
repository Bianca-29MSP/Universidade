#include <QMessageBox>
#include "MyMainWindow.h"
#include "ui_ui_MainWindow.h"

MyMainWindow::MyMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyMainWindow)
{
    ui->setupUi(this);
}

MyMainWindow::~MyMainWindow()
{
    delete ui;
}

