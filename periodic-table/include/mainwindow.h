#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../include/utils.h"
#include <QDialog>
#include <QLabel>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  private:
    Ui::MainWindow *ui;
    QList<Element> elements;

  private slots:
    void display_element_information(int elementIndex);
};
#endif // MAINWINDOW_H
