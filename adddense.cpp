#include "adddense.h"
#include "ui_adddense.h"

AddDense::AddDense(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDense)
{
    ui->setupUi(this);
}
AddDense::AddDense(Apollo::Dataloader* data, Apollo::Model* model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDense)
{
    ui->setupUi(this);
    this->data = data;
    this->model = model;
    if(model->getLastLayerOutputShape()[0] == 0 && this->model->getLastLayerOutputShape()[1] == 0){
        lastShape = this->data->getTrainDataShape();
    }else{
        lastShape = this->model->getLastLayerOutputShape();
    }
    ui->inputs->setPlainText(QString::number(lastShape[0]));
    ui->outputs->setPlainText(QString::number(lastShape[1]));
//    cout<<this->model->getLastLayerOutputShape()[0]<< " " << this->model->getLastLayerOutputShape()[1] << endl;
}

AddDense::~AddDense()
{
    delete ui;
}

void AddDense::on_pushButton_clicked()
{
    int numNeurons =  ui->neurons->toPlainText().toInt();
    int numInputs = ui->inputs->toPlainText().toInt();
    int numOutputs = ui->outputs->toPlainText().toInt();
    int shape[2]={numInputs, numOutputs};
    Apollo::MultiType Dense =  Apollo::Dense(numNeurons, shape);
    this->model->addLayer(&Dense);
    close();
//    cout<<this->model->getLastLayerOutputShape()[0]<< " " << this->model->getLastLayerOutputShape()[1] << endl;
}


void AddDense::on_pushButton_2_clicked()
{
    if(model->getLastLayerOutputShape()[0] == 0 and this->model->getLastLayerOutputShape()[1]){
        lastShape = this->data->getTrainDataShape();
    }else{
        lastShape = this->model->getLastLayerOutputShape();
    }
    ui->inputs->setPlainText(QString::number(lastShape[0]));
    ui->outputs->setPlainText(QString::number(lastShape[1]));
}

