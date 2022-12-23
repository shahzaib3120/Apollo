#include "trainmodel.h"
#include "ui_trainmodel.h"
#include <QFileDialog>
TrainModel::TrainModel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TrainModel)
{
    ui->setupUi(this);
    ui->textEdit->setPlainText("0.8");
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
    float split = ui->textEdit->toPlainText().toFloat();
    data = new Apollo::Dataloader(dataFile, split);
    model = new Apollo::Model(data->getTrainDataShape(), false, 0.01, 1);
}


void TrainModel::on_pushButton_2_clicked()
{
    addSig = new AddSigmoid(model, this);
    addSig->exec();
}


void TrainModel::on_pushButton_4_clicked()
{
    // trigger train
    train = new Train(model, data, this);
    train->exec();
}

