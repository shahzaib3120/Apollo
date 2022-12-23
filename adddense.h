#ifndef ADDDENSE_H
#define ADDDENSE_H

#include <QDialog>
#include <Apollo.h>
namespace Ui {
class AddDense;
}

class AddDense : public QDialog
{
    Q_OBJECT

public:
    explicit AddDense(QWidget *parent = nullptr);
    AddDense( Apollo::Dataloader*, Apollo::Model*, QWidget* parent = nullptr);
    ~AddDense();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddDense *ui;
    Apollo::Model* model;
    Apollo::Dataloader* data;
    int* lastShape;
};

#endif // ADDDENSE_H
