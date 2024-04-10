#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../include/params.h"
#include "../include/utils.h"
#include <QButtonGroup>
#include <QDesktopServices>
#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QMainWindow>
#include <QMessageBox>

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
    QMenu *helpMenu;
    QAction *aboutAction;
    QList<QButtonGroup *> elementButtons;
    QList<Element> elements;
    QGridLayout *referenceLayout;
    void create_actions();
    void create_menus();
    void set_element_buttons_groups();
    void set_element_buttons_style();
    void set_elements_connections();
    void add_elements_reference();

  private slots:
    void display_element_information(const int &elementIndex);
    void show_about_dialog();
};
#endif // MAINWINDOW_H
