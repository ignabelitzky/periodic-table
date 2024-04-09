#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../include/params.h"
#include "../include/utils.h"
#include <QButtonGroup>
#include <QDialog>
#include <QGridLayout>
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
    QGridLayout *referenceLayout;
    void set_element_buttons_groups();
    void set_element_buttons_style();
    void set_elements_connections();
    void add_elements_reference();

  private slots:
    void display_element_information(const int &elementIndex);
};
#endif // MAINWINDOW_H
