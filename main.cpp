#include "mainwindow.h"
#include <QApplication>
#include <Apollo.h>
using namespace Apollo;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Spam e-mail Classifier");
    w.show();
    return a.exec();
}
