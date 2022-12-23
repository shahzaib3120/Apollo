#ifndef ADDSIGMOID_H
#define ADDSIGMOID_H

#include <QDialog>
#include <Apollo.h>
namespace Ui {
class AddSigmoid;
}

class AddSigmoid : public QDialog
{
    Q_OBJECT

public:
    explicit AddSigmoid(QWidget *parent = nullptr);
    AddSigmoid(Apollo::Model*, QWidget *parent = nullptr);
    ~AddSigmoid();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddSigmoid *ui;
    Apollo::Model *model;
    int* lastShape;
};

#endif // ADDSIGMOID_H
