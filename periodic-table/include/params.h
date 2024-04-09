#ifndef PARAMS_H
#define PARAMS_H

#include <QList>
#include <QPair>
#include <QString>
#include <QStringList>

const int NUM_ELEMENTS = 118;
const int MAX_REFERENCE_COLS = 10;
const QString ELEMENTS_JSON_PATH(":/data/elements.json");
const QString BACKGROUND_COLOR("#FAFAD2");

const QStringList properties = {
    "Atomic Number:",     "Symbol:",  "Name:",          "Atomic Mass:",     "Category:",
    "Electronegativity:", "Phase:",   "Period:",        "Group:",           "Melting Point:",
    "Boiling Point:",     "Density:", "Discovered by:", "Year discovered:", "Named by:"};

const QList<QPair<QString, QString>> elementsType({
    QPair<QString, QString>("Alkali Metal", "#FFC0CB"),          // Red
    QPair<QString, QString>("Alkaline-Earth Metal", "#87E79E"),  // ~Green
    QPair<QString, QString>("Transition Metal", "#98FB98"),      // ~Green
    QPair<QString, QString>("Halogen", "#FFFF99"),               // ~Yellow
    QPair<QString, QString>("Other Nonmetal", "#FFA500"),        // Orange
    QPair<QString, QString>("Metalloid", "#D174A8"),             // Magenta-Pink
    QPair<QString, QString>("Post-transition metal", "#987654"), // Brown
    QPair<QString, QString>("Lanthanoid", "#E6E6FA"),            // ~Purple
    QPair<QString, QString>("Actinoid", "#B0C4DE"),              // ~Gray
    QPair<QString, QString>("Noble Gas", "#008080"),             // Teal
    QPair<QString, QString>("Unknown", "#F5F5F5")                // ~White
});

#endif
