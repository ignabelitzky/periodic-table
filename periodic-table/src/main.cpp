#include "../include/element.h"
#include "../include/mainwindow.h"

#include <QApplication>
#include "../include/utils.h"
#include "../include/element.h"

int main(int argc, char *argv[])
{
    QList<Element> elements = load_elements_from_json_file(QString("../../resources/elements.json"));
    print_elements(elements);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
