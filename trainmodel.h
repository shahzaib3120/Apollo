#ifndef TRAINMODEL_H
#define TRAINMODEL_H

#include <QDialog>
#include <Apollo.h>
#include "adddense.h"
#include "addsigmoid.h"
#include "train.h"
namespace Ui {
class TrainModel;
}

class TrainModel : public QDialog
{
    Q_OBJECT

public:
    explicit TrainModel(QWidget *parent = nullptr);
    ~TrainModel();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

protected:
    Apollo::Model* model;
    Apollo::Dataloader* data;
    AddSigmoid* addSig;
    AddDense* addDense;
    Train* train;
private:
    Ui::TrainModel *ui;

};

#endif // TRAINMODEL_H
