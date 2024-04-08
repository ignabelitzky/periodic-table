#include "../include/mainwindow.h"
#include "../ui/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::display_element_information(int elementIndex)
{
    Element element = elements.at(elementIndex);
    QStringList properties = {"Atomic Number:",     "Symbol:",  "Name:",          "Atomic Mass:",     "Category:",
                              "Electronegativity:", "Phase:",   "Period:",        "Group:",           "Melting Point:",
                              "Boiling Point:",     "Density:", "Discovered by:", "Year discovered:", "Named by:"};
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

    infoDialog->exec();
}
