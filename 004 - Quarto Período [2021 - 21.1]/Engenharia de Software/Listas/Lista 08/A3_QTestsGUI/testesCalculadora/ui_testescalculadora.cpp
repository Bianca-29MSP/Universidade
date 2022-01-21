#include "ui_testescalculadora.h"
#include "ui_ui_testescalculadora.h"

ui_testesCalculadora::ui_testesCalculadora(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ui_testesCalculadora)
{
    ui->setupUi(this);
}

ui_testesCalculadora::~ui_testesCalculadora()
{
    delete ui;
}
