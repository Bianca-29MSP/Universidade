#ifndef UI_TESTESCALCULADORA_H
#define UI_TESTESCALCULADORA_H

#include <QDialog>

namespace Ui {
class ui_testesCalculadora;
}

class ui_testesCalculadora : public QDialog
{
    Q_OBJECT

public:
    explicit ui_testesCalculadora(QWidget *parent = nullptr);
    ~ui_testesCalculadora();

private:
    Ui::ui_testesCalculadora *ui;
};

#endif // UI_TESTESCALCULADORA_H
