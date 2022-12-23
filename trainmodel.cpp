#include "trainmodel.h"
#include "ui_trainmodel.h"
#include <QFileDialog>
TrainModel::TrainModel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TrainModel)
{
    ui->setupUi(this);
}

TrainModel::~TrainModel()
{
    delete ui;
}

void TrainModel::on_pushButton_clicked()
{
    addDense = new AddDense(data, model, this);
    addDense->exec();
}


void TrainModel::on_pushButton_3_clicked()
{
    std::string dataFile = (QFileDialog::getOpenFileName(this, tr("Open File"),"E:/Learning-E/Apollo-backend/Dataset",tr("CSV Files (*.csv)"))).toStdString();
    data = new Apollo::Dataloader(dataFile, 0.8);
    model = new Apollo::Model(data->getTrainDataShape(), false, 0.01, 1);
}

