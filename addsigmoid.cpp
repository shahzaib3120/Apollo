#include "addsigmoid.h"
#include "ui_addsigmoid.h"
#include <QMessageBox>
AddSigmoid::AddSigmoid(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSigmoid)
{
    ui->setupUi(this);
}
AddSigmoid::AddSigmoid(Apollo::Model* model,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSigmoid)
{
    ui->setupUi(this);
    this->model = model;
    if(model->getLastLayerOutputShape()[0] == 0 && this->model->getLastLayerOutputShape()[1] == 0){
        lastShape[0]=0;
        lastShape[1]=0;
        QMessageBox::critical(this,"Invalid Layer Shape", "Last layer has output shape of 0 x 0!\nPotential Error: No Dense Layer added");
    }else{
        lastShape = this->model->getLastLayerOutputShape();
    }
    ui->inputs->setPlainText(QString::number(lastShape[0]));
    ui->outputs->setPlainText(QString::number(lastShape[1]));

}
AddSigmoid::~AddSigmoid()
{
    delete ui;
}

void AddSigmoid::on_pushButton_clicked()
{
    int numInputs = ui->inputs->toPlainText().toInt();
    int numOutputs = ui->outputs->toPlainText().toInt();
    int shape[2]={numInputs, numOutputs};
    Apollo::MultiType sig = Apollo::Sigmoid(shape);
    model->addLayer(&sig);
    close();
}


void AddSigmoid::on_pushButton_2_clicked()
{
    if(model->getLastLayerOutputShape()[0] == 0 && this->model->getLastLayerOutputShape()[1] == 0){
        QMessageBox::critical(this,"Invalid Layer Shape", "Last layer has output shape of 0 x 0!\nPotential Error: No Dense Layer added");
    }else{
        lastShape = this->model->getLastLayerOutputShape();
    }
}

