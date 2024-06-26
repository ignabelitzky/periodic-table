#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../include/params.h"
#include "../include/utils.h"
#include <QButtonGroup>
#include <QCompleter>
#include <QDesktopServices>
#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QMessageBox>
#include <QStringListModel>

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

  protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

  private:
    Ui::MainWindow *ui;
    QMenu *fileMenu;
    QMenu *windowMenu;
    QMenu *helpMenu;
    QStatusBar *statusBar;
    QAction *exitAction;
    QAction *minimizeAction;
    QAction *maximizeAction;
    QAction *aboutAction;
    QLabel *titleLabel;
    QList<QButtonGroup *> elementButtons;
    QList<Element> elements;
    QGridLayout *referenceLayout;
    QLabel *searchLabel;
    QLineEdit *searchLineEdit;

    void create_actions();
    void create_menus();
    void set_title_label();
    void set_element_buttons_groups();
    void set_element_buttons_style();
    void set_elements_connections();
    void add_elements_reference();
    void set_search_functionalities();
    void display_element_in_status_bar(const int &elementIndex);
    void clear_status_bar();

  private slots:
    void display_element_information(const int &elementIndex);
    void display_element_information_by_name(const QString &elementName);
    void minimize_window();
    void maximize_window();
    void show_about_dialog();
};
#endif // MAINWINDOW_H
