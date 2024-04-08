#include "../include/mainwindow.h"
#include "../include/utils.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QList<Element> elements = load_elements_from_json_file(QString(":/data/elements.json"));
    print_elements(elements);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
