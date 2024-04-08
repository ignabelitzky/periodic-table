#ifndef UTILS_H
#define UTILS_H

#include <QList>
#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include "element.h"

QList<Element> load_elements_from_json_file(const QString jsonFilename);

void print_elements(QList<Element> elements);

#endif // UTILS_H
