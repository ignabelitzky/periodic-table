#include "../include/mainwindow.h"
#include "../include/params.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setStyleSheet(QString("background-color: %1;").arg(BACKGROUND_COLOR));
    w.show();
    return a.exec();
}
