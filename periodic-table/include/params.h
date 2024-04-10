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
    QPair<QString, QString>("Alkali metals", "#FFC0CB"),          // Red
    QPair<QString, QString>("Alkaline-earth metals", "#87E79E"),  // ~Green
    QPair<QString, QString>("Transition metals", "#98FB98"),      // ~Green
    QPair<QString, QString>("Halogens", "#FFFF99"),               // ~Yellow
    QPair<QString, QString>("Other non-metals", "#FFA500"),       // Orange
    QPair<QString, QString>("Metalloids", "#D174A8"),             // Magenta-Pink
    QPair<QString, QString>("Post-transition metals", "#987654"), // Brown
    QPair<QString, QString>("Lanthanides", "#E6E6FA"),            // ~Purple
    QPair<QString, QString>("Actinides", "#B0C4DE"),              // ~Gray
    QPair<QString, QString>("Noble gases", "#008080"),            // Teal
    QPair<QString, QString>("Unknown", "#F5F5F5")                 // ~White
});

#endif
