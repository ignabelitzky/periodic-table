#ifndef ELEMENT_H
#define ELEMENT_H

#include <QList>
#include <QString>

class Element
{
  public:
    Element();
    Element(int atomicNumber, QString symbol, QString name, float atomicMass, QString category, float electronegativity,
            QString phase, int period, int group, float meltingPoint, float boilingPoint, float density,
            QString discoveredBy, int yearDiscovered, QString namedBy);
    ~Element();
    // setters
    void set_atomic_number(int atomicNumber);
    void set_symbol(QString symbol);
    void set_name(QString name);
    void set_atomic_mass(float atomicMass);
    void set_category(QString category);
    void set_electronegativity(float electronegativity);
    void set_phase(QString phase);
    void set_period(int period);
    void set_group(int group);
    void set_melting_point(float meltingPoint);
    void set_boiling_point(float boilingPoint);
    void set_density(float density);
    void set_discovered_by(QString discoveredBy);
    void set_year_discovered(int yearDiscovered);
    void set_named_by(QString namedBy);

    // getters
    int get_atomic_number();
    QString get_symbol();
    QString get_name();
    float get_atomic_mass();
    QString get_category();
    float get_electronegativity();
    QString get_phase();
    int get_period();
    int get_group();
    float get_melting_point();
    float get_boiling_point();
    float get_density();
    QString get_discovered_by();
    int get_year_discovered();
    QString get_named_by();

  private:
    int atomicNumber;
    QString symbol;
    QString name;
    float atomicMass;
    QString category;
    float electronegativity;
    QString phase;
    int period;
    int group;
    float meltingPoint;
    float boilingPoint;
    float density;
    QString discoveredBy;
    int yearDiscovered;
    QString namedBy;
};

#endif // ELEMENT_H
