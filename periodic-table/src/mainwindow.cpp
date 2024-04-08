#include "../include/mainwindow.h"
#include "../ui/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

    set_element_buttons_style();

    this->elements = load_elements_from_json_file(":/data/elements.json");

    for (int i = 0; i < 128; ++i)
    {
        QString buttonName = QString("pushButton_%1").arg(i + 1);
        QPushButton *button = findChild<QPushButton *>(buttonName);
        if (button)
        {
            connect(button, &QPushButton::clicked, this, [=]() { display_element_information(i); });
        }
    }

    // Add reference to the elements.
    referenceLayout = ui->centralwidget->findChild<QGridLayout *>(QString("referenceGridLayout"));
    int row = 0, col = 0;
    for (int i = 0; i < elementsType.size(); ++i)
    {
        QLabel *referenceLabel = new QLabel(QString("%1").arg(elementsType[i]));
        QPushButton *referenceColor = new QPushButton();
        referenceColor->setFixedSize(20, 20);
        QString styleSheet = QString("QPushButton {"
                                     "background-color: %1;"
                                     "}")
                                 .arg(colors.at(i));
        referenceColor->setStyleSheet(styleSheet);
        referenceLayout->addWidget(referenceColor, row, col++);
        referenceLayout->addWidget(referenceLabel, row, col++);
        if (col == 8)
        {
            col = 0;
            ++row;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_element_buttons_style()
{
    int idx = 0;
    for (auto buttonGroup : elementButtons)
    {
        QString styleSheet = QString("QPushButton {background-color: %1; color: black;}").arg(colors.at(idx));
        for (auto button : buttonGroup->buttons())
        {
            button->setStyleSheet(styleSheet);
        }
        idx++;
    }
}

void MainWindow::display_element_information(int elementIndex)
{
    Element element = elements.at(elementIndex);
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

    QDialog *infoDialog = new QDialog(this);
    infoDialog->setWindowTitle(element.get_name());

    QVBoxLayout *layout = new QVBoxLayout(infoDialog);
    QGridLayout *gridLayout = new QGridLayout();
    layout->addLayout(gridLayout);

    for (int i = 0; i < properties.size(); ++i)
    {
        QLabel *propertyLabel = new QLabel(properties.at(i));
        QLabel *valueLabel = new QLabel(values.at(i));

        gridLayout->addWidget(propertyLabel, i, 0);
        gridLayout->addWidget(valueLabel, i, 1);
    }

    infoDialog->setLayout(layout);

    infoDialog->exec();
}
