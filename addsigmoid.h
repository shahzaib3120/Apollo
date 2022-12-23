#ifndef ADDSIGMOID_H
#define ADDSIGMOID_H

#include <QDialog>

namespace Ui {
class AddSigmoid;
}

class AddSigmoid : public QDialog
{
    Q_OBJECT

public:
    explicit AddSigmoid(QWidget *parent = nullptr);
    ~AddSigmoid();

private:
    Ui::AddSigmoid *ui;
};

#endif // ADDSIGMOID_H
