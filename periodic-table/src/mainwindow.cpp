#include "../include/mainwindow.h"
#include "../ui/ui_mainwindow.h"

/* PUBLIC METHODS */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->elements = load_elements_from_json_file(ELEMENTS_JSON_PATH);

    statusBar = QMainWindow::statusBar();

    create_actions();
    create_menus();
    set_title_label();
    set_element_buttons_groups();
    set_element_buttons_style();
    add_elements_reference();
    set_elements_connections();
    set_search_functionalities();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* PROTECTED METHODS */
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::Enter)
    {
        QStringList parts = obj->objectName().split('_');
        int elementIndex = parts[1].toInt() - 1;
        display_element_in_status_bar(elementIndex);
    }
    else if (event->type() == QEvent::Leave)
    {
        clear_status_bar();
    }
    return QMainWindow::eventFilter(obj, event);
}

/* PRIVATE METHODS */
void MainWindow::create_actions()
{
    exitAction = new QAction(tr("&Exit"));
    exitAction->setShortcut(QKeySequence::Quit);
    minimizeAction = new QAction(tr("Minimize"));
    maximizeAction = new QAction(tr("Maximize"));
    aboutAction = new QAction(tr("&About"), this);
    exitAction->setStatusTip(tr("Close the application"));
    minimizeAction->setStatusTip(tr("Minimize window"));
    maximizeAction->setStatusTip(tr("Maximize window"));
    aboutAction->setStatusTip(tr("Show the application's About box"));
}

void MainWindow::create_menus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    windowMenu = menuBar()->addMenu(tr("&Window"));
    helpMenu = menuBar()->addMenu(tr("&Help"));
    fileMenu->addAction(exitAction);
    windowMenu->addAction(minimizeAction);
    windowMenu->addAction(maximizeAction);
    helpMenu->addAction(aboutAction);
}

void MainWindow::set_title_label()
{
    titleLabel = ui->centralwidget->findChild<QLabel *>(QString("titleLabel"));
    QPixmap pix(":/data/title_periodic_table.png");
    int newWidth = 800;
    int newHeight = 150;
    QPixmap scaledPix = pix.scaled(newWidth, newHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    titleLabel->setPixmap(scaledPix);
    titleLabel->setFixedSize(newWidth, newHeight);
}

void MainWindow::set_element_buttons_groups()
{
    elementButtons.append(ui->alkaliMetalsGroup);
    elementButtons.append(ui->alkalineEarthMetalsGroup);
    elementButtons.append(ui->transitionMetalsGroup);
    elementButtons.append(ui->halogensGroup);
    elementButtons.append(ui->otherNonmetalsGroup);
    elementButtons.append(ui->metalloidsGroup);
    elementButtons.append(ui->postTransitionMetalsGroup);
    elementButtons.append(ui->lanthanoidGroup);
    elementButtons.append(ui->actinoidGroup);
    elementButtons.append(ui->nobleGasGroup);
    elementButtons.append(ui->unknownGroup);
}

void MainWindow::set_element_buttons_style()
{
    int idx = 0;
    for (auto buttonGroup : elementButtons)
    {
        QString styleSheet = QString("QPushButton {"
                                     "background-color: %1;"
                                     "border-radius: 3px;"
                                     "padding: 2px;"
                                     "min-width: 85px;"
                                     "min-height: 50px;"
                                     "border: 1px solid black;"
                                     "color: black;}"
                                     "QPushButton:hover {"
                                     "background-color: white;}")
                                 .arg(elementsType.at(idx).second);
        for (auto button : buttonGroup->buttons())
        {
            button->setStyleSheet(styleSheet);
        }
        idx++;
    }
}

void MainWindow::set_elements_connections()
{
    for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        QString buttonName = QString("pushButton_%1").arg(i + 1);
        QPushButton *button = findChild<QPushButton *>(buttonName);
        if (button)
        {
            connect(button, &QPushButton::clicked, this, [=]() { display_element_information(i); });
            button->installEventFilter(this);
        }
    }
    // File action
    connect(exitAction, &QAction::triggered, this, &MainWindow::close);

    // Window actions
    connect(minimizeAction, &QAction::triggered, this, &MainWindow::minimize_window);
    connect(maximizeAction, &QAction::triggered, this, &MainWindow::maximize_window);

    // About action
    connect(aboutAction, &QAction::triggered, this, &MainWindow::show_about_dialog);
}

void MainWindow::add_elements_reference()
{
    referenceLayout = ui->centralwidget->findChild<QGridLayout *>(QString("referenceGridLayout"));
    int row = 0, col = 0;
    for (int i = 0; i < elementsType.size(); ++i)
    {
        QLabel *referenceLabel = new QLabel(QString("%1").arg(elementsType.at(i).first));
        QPushButton *referenceColor = new QPushButton();
        referenceColor->setFixedSize(20, 20);
        QString styleSheet = QString("QPushButton {"
                                     "background-color: %1;"
                                     "}")
                                 .arg(elementsType.at(i).second);
        referenceColor->setStyleSheet(styleSheet);
        referenceLayout->addWidget(referenceColor, row, col++);
        referenceLayout->addWidget(referenceLabel, row, col++);
        if (col == MAX_REFERENCE_COLS)
        {
            col = 0;
            ++row;
        }
    }
}

void MainWindow::set_search_functionalities()
{
    searchLabel = ui->centralwidget->findChild<QLabel *>(QString("searchElementLabel"));
    searchLineEdit = ui->centralwidget->findChild<QLineEdit *>(QString("searchElementLineEdit"));
    searchLineEdit->setStyleSheet(QString("background-color: white;"));

    QStringList elementNames;
    for (int i = 0; i < elements.size(); ++i)
    {
        elementNames.append(elements.at(i).get_name());
    }
    QStringListModel *model = new QStringListModel(elementNames);
    QCompleter *completer = new QCompleter(model);

    searchLineEdit->setCompleter(completer);

    connect(searchLineEdit, &QLineEdit::returnPressed, this,
            [=]() { display_element_information_by_name(searchLineEdit->text()); });
}

void MainWindow::display_element_in_status_bar(const int &elementIndex)
{
    QString elementInformation = QString("%1 -- Atomic Number %2 -- Period %3 -- Group: %4")
                                     .arg(elements[elementIndex].get_name())
                                     .arg(elements[elementIndex].get_atomic_number())
                                     .arg(elements[elementIndex].get_period())
                                     .arg(elements[elementIndex].get_group());
    statusBar->showMessage(elementInformation);
}

void MainWindow::clear_status_bar()
{
    statusBar->clearMessage();
}

/* PRIVATE SLOTS */
void MainWindow::display_element_information(const int &elementIndex)
{
    const Element &element = elements.at(elementIndex);

    QDialog *infoDialog = new QDialog(this);
    infoDialog->setWindowTitle(element.get_name());

    QVBoxLayout *layout = new QVBoxLayout(infoDialog);

    QGridLayout *gridLayout = new QGridLayout();
    layout->addLayout(gridLayout);

    QStringList values = {QString::number(element.get_atomic_number()),
                          element.get_symbol(),
                          element.get_name(),
                          QString::number(element.get_atomic_mass()),
                          element.get_category(),
                          QString::number(element.get_electronegativity()),
                          element.get_phase(),
                          QString::number(element.get_period()),
                          QString::number(element.get_group()),
                          QString::number(element.get_melting_point()),
                          QString::number(element.get_boiling_point()),
                          QString::number(element.get_density()),
                          element.get_discovered_by(),
                          QString::number(element.get_year_discovered()),
                          element.get_named_by()};

    QString styleSheetProperty("QLabel {"
                               "font-size: 14px;"
                               "padding: 4px;"
                               "font-weight: bold;}");
    QString styleSheetValue("QLabel {"
                            "font-size: 14px;"
                            "padding: 4px;}");

    for (int i = 0; i < properties.size(); ++i)
    {
        QLabel *propertyLabel = new QLabel(properties.at(i));
        QLabel *valueLabel = nullptr;
        if(properties.at(i) == "Melting Point:" || properties.at(i) == "Boiling Point:")
        {
            valueLabel = new QLabel(values.at(i) + QString(" K"));
        }
        else
        {
            valueLabel = new QLabel(values.at(i));
        }
        propertyLabel->setStyleSheet(styleSheetProperty);
        valueLabel->setStyleSheet(styleSheetValue);

        gridLayout->addWidget(propertyLabel, i, 0);
        gridLayout->addWidget(valueLabel, i, 1);
    }

    infoDialog->setStyleSheet(QString("background-color: white;"));

    infoDialog->exec();
}

void MainWindow::display_element_information_by_name(const QString &elementName)
{
    bool found = false;
    Element element = elements.at(0);
    for (const Element &elem : elements)
    {
        if (elem.get_name() == elementName)
        {
            element = elem;
            found = true;
            break;
        }
    }
    if (found)
    {
        QDialog *infoDialog = new QDialog(this);
        infoDialog->setWindowTitle(element.get_name());

        QVBoxLayout *layout = new QVBoxLayout(infoDialog);

        QGridLayout *gridLayout = new QGridLayout();
        layout->addLayout(gridLayout);

        QStringList values = {QString::number(element.get_atomic_number()),
                              element.get_symbol(),
                              element.get_name(),
                              QString::number(element.get_atomic_mass()),
                              element.get_category(),
                              QString::number(element.get_electronegativity()),
                              element.get_phase(),
                              QString::number(element.get_period()),
                              QString::number(element.get_group()),
                              QString::number(element.get_melting_point()),
                              QString::number(element.get_boiling_point()),
                              QString::number(element.get_density()),
                              element.get_discovered_by(),
                              QString::number(element.get_year_discovered()),
                              element.get_named_by()};

        QString styleSheetProperty("QLabel {"
                                   "font-size: 14px;"
                                   "padding: 4px;"
                                   "font-weight: bold;}");
        QString styleSheetValue("QLabel {"
                                "font-size: 14px;"
                                "padding: 4px;}");

        for (int i = 0; i < properties.size(); ++i)
        {
            QLabel *propertyLabel = new QLabel(properties.at(i));
            QLabel *valueLabel = nullptr;
            if(properties.at(i) == "Melting Point:" || properties.at(i) == "Boiling Point:")
            {
                valueLabel = new QLabel(values.at(i) + QString(" K"));
            }
            else
            {
                valueLabel = new QLabel(values.at(i));
            }
            propertyLabel->setStyleSheet(styleSheetProperty);
            valueLabel->setStyleSheet(styleSheetValue);

            gridLayout->addWidget(propertyLabel, i, 0);
            gridLayout->addWidget(valueLabel, i, 1);
        }

        infoDialog->setStyleSheet(QString("background-color: white;"));

        infoDialog->exec();
    }
    else
    {
        QMessageBox::critical(nullptr, "Error", "Element not found!");
    }
    searchLineEdit->clear();
}

void MainWindow::minimize_window()
{
    this->showMinimized();
}

void MainWindow::maximize_window()
{
    this->showMaximized();
}

void MainWindow::show_about_dialog()
{
    QMessageBox *aboutBox = new QMessageBox(this);
    aboutBox->about(this, tr("About Periodic Table"), tr("This is a Qt application created by Ignacio Belitzky."));
}
