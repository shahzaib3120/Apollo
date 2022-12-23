#include "train.h"
#include "ui_train.h"
#include <QFileDialog>
Train::Train(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Train)
{
    ui->setupUi(this);
}
Train::Train(Apollo::Model* model,Apollo::Dataloader* data, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Train)
{
    ui->setupUi(this);
    ui->threshold->setEnabled(false);
    ui->filename->setEnabled(false);
    this->model=model;
    this->data = data;
    ui->progressBar->setValue(0);
}
Train::~Train()
{
    delete ui;
}



void Train::on_trainBtn_clicked()
{
    // start training
    numEpochs = ui->numEpochs->toPlainText().toInt();
    int threshold = ui->threshold->toPlainText().toInt();
    filePath = ui->filename->toPlainText().toStdString();
    bool verbose=false;
    bool saveEpoch = ui->saveEpoch->checkState();
    bool earlyStopping = ui->earlyStopping->checkState();
    ui->numEpochs->setEnabled(false);
    ui->threshold->setEnabled(false);
    ui->filename->setEnabled(false);
    model->fit(data->getTrainData(), data->getTrainLabels(), data->getValData(), data->getValLabels(),numEpochs, Apollo::BCE, verbose,saveEpoch,filePath,earlyStopping,threshold, ui->progressBar);
    ui->numEpochs->setEnabled(true);
    ui->threshold->setEnabled(true);
    ui->filename->setEnabled(true);
}


void Train::on_numEpochs_textChanged()
{
    numEpochs = ui->numEpochs->toPlainText().toInt();
    ui->progressBar->setMaximum(numEpochs);
    ui->progressBar->setMinimum(0);
}


void Train::on_browseBtn_clicked()
{
    // set save filePath
    filePath = (QFileDialog::getOpenFileName(this, tr("Open File")," ",tr("CSV Files (*.csv)"))).toStdString();
    ui->filename->setPlainText(QString::fromStdString(filePath));
}


void Train::on_earlyStopping_toggled(bool checked)
{
    cout << ui->earlyStopping->checkState() << endl;
}

