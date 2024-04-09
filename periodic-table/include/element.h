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
    int get_atomic_number() const;
    QString get_symbol() const;
    QString get_name() const;
    float get_atomic_mass() const;
    QString get_category() const;
    float get_electronegativity() const;
    QString get_phase() const;
    int get_period() const;
    int get_group() const;
    float get_melting_point() const;
    float get_boiling_point() const;
    float get_density() const;
    QString get_discovered_by() const;
    int get_year_discovered() const;
    QString get_named_by() const;

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
