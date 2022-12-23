#include "addsigmoid.h"
#include "ui_addsigmoid.h"

AddSigmoid::AddSigmoid(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSigmoid)
{
    ui->setupUi(this);
}

AddSigmoid::~AddSigmoid()
{
    delete ui;
}
