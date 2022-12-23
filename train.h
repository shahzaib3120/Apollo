#ifndef TRAIN_H
#define TRAIN_H

#include <Apollo.h>
#include <QDialog>

namespace Ui {
class Train;
}

class Train : public QDialog
{
    Q_OBJECT

public:
    explicit Train(QWidget *parent = nullptr);
    Train(Apollo::Model*,Apollo::Dataloader* , QWidget *parent = nullptr);
    ~Train();

private slots:

    void on_trainBtn_clicked();

    void on_numEpochs_textChanged();

    void on_browseBtn_clicked();

    void on_earlyStopping_toggled(bool checked);

private:
    Ui::Train *ui;
    Apollo::Model* model;
    Apollo::Dataloader* data;
    int numEpochs;
    int counter=0;
    std::string filePath;
};

#endif // TRAIN_H
