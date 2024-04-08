#ifndef PARAMS_H
#define PARAMS_H

#include <QStringList>

const QStringList properties = {
    "Atomic Number:",     "Symbol:",  "Name:",          "Atomic Mass:",     "Category:",
    "Electronegativity:", "Phase:",   "Period:",        "Group:",           "Melting Point:",
    "Boiling Point:",     "Density:", "Discovered by:", "Year discovered:", "Named by:"};

const QStringList colors({
    "#FF0000", // Red
    "#00FF00", // Green
    "#0000FF", // Blue
    "#FFFF00", // Yellow
    "#FFA500", // Orange
    "#800080", // Purple
    "#FFC0CB", // Pink
    "#00FFFF", // Cyan
    "#FF00FF", // Magenta
    "#008080", // Teal
    "#FFFFFF"  // White
});

const QStringList elementsType({"Alkali Metal", "Alkaline-Earth Metal", "Transition Metal", "Halogen", "Other Nonmetal",
                                "Metalloid", "Post Transition Metal", "Lanthanoid", "Actinoid", "Noble Gas",
                                "Unknown"});

#endif
