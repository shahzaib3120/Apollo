#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Model/Model.h"
#include "Preprocessing/Preprocessing.h"
#include <string>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString email = ui->plainTextEdit->toPlainText();
    int shape[2]= {1,3000};
    auto* model = new Apollo::Model(shape, false);
    model->loadModel("E:/Learning-E/Apollo-backend/Models/spam-100.csv");
    model->compile();
    Eigen::MatrixXd emailMatrix = Apollo::Preprocessing::spamPreprocessing(email.toStdString());
    Eigen::MatrixXd pred = model->predict(emailMatrix);
    double predVal = pred.sum();
    if(predVal>0.3){
        ui->label->setText("Spam " + QString::number(predVal));
    }else{
        ui->label->setText("Not Spam " + QString::number(predVal));
    }
    delete model;
}


void MainWindow::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File")," ",tr("Text Files (*.txt)"));
    std::string filePath = fileName.toStdString();
    // start code here
    ifstream File;
    File.open(filePath);
    std::string email;
    std::string s;
    while(getline(File,s)){
       email+=s;
       email+="\n";
    }
    ui->plainTextEdit->setPlainText(QString::fromStdString(email));
}


void MainWindow::on_pushButton_3_clicked()
{
//    hide();
    trainWindow = new TrainModel(this);
    trainWindow->exec();
}

