#ifndef UTILS_H
#define UTILS_H

#include "element.h"
#include <QButtonGroup>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QList>
#include <QString>
#include <QStringList>

QList<Element> load_elements_from_json_file(const QString jsonFilename);

void print_elements(QList<Element> elements);

#endif // UTILS_H
