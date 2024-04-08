#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../include/params.h"
#include "../include/utils.h"
#include <QButtonGroup>
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
    QList<QButtonGroup *> elementButtons;
    QList<Element> elements;
    void set_element_buttons_style();

  private slots:
    void display_element_information(int elementIndex);
};
#endif // MAINWINDOW_H
