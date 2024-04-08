#include "../include/utils.h"

QList<Element> load_elements_from_json_file(const QString jsonFilename)
{
    QList<Element> result{};
    QFile jsonFile(jsonFilename);
    if (!jsonFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open JSON file";
    }
    else
    {
        QByteArray jsonData = jsonFile.readAll();
        QJsonParseError error;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &error);
        if (jsonDoc.isNull())
        {
            qDebug() << "Failed to parse JSON:" << error.errorString();
        }
        else if (!jsonDoc.isObject())
        {
            qDebug() << "JSON document is not an object";
        }
        else
        {
            QJsonObject jsonObj = jsonDoc.object();
            QJsonArray elementsArray = jsonObj["elements"].toArray();

            for (const auto &element : elementsArray)
            {
                QJsonObject elementObj = element.toObject();
                Element newElement(elementObj["atomic_number"].toInt(), elementObj["symbol"].toString(),
                                   elementObj["name"].toString(), elementObj["atomic_mass"].toDouble(),
                                   elementObj["category"].toString(), elementObj["electronegativity"].toDouble(),
                                   elementObj["phase"].toString(), elementObj["period"].toInt(),
                                   elementObj["group"].toInt(), elementObj["melting_point"].toDouble(),
                                   elementObj["boiling_point"].toDouble(), elementObj["density"].toDouble(),
                                   elementObj["discovered_by"].toString(), elementObj["year_discovered"].toInt(),
                                   elementObj["named_by"].toString());
                result.append(newElement);
            }
        }
    }
    return result;
}

void print_elements(QList<Element> elements)
{
    for (Element &element : elements)
    {
        qDebug() << "Atomic Number: " << element.get_atomic_number();
        qDebug() << "Symbol: " << element.get_symbol();
        qDebug() << "Name: " << element.get_name();
        qDebug() << "Atomic Mass: " << element.get_atomic_mass();
        qDebug() << "Category: " << element.get_category();
        qDebug() << "Electronegativity: " << element.get_electronegativity();
        qDebug() << "Phase: " << element.get_phase();
        qDebug() << "Period: " << element.get_period();
        qDebug() << "Group: " << element.get_group();
        qDebug() << "Melting point: " << element.get_melting_point();
        qDebug() << "Boiling point: " << element.get_boiling_point();
        qDebug() << "Density: " << element.get_density();
        qDebug() << "Discovered by: " << element.get_discovered_by();
        qDebug() << "Year discovered: " << element.get_year_discovered();
        qDebug() << "Named by: " << element.get_named_by();
        qDebug() << "- - - - - - - - - - - - - - - ";
    }
}
