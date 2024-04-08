#include "../include/element.h"

Element::Element()
{
    atomicNumber = 0;
    symbol = QString("");
    name = QString("");
    atomicMass = 0.0f;
    category = QString("");
    electronegativity = 0.0f;
    phase = "";
    period = 0;
    group = 0;
    meltingPoint = 0.0f;
    boilingPoint = 0.0f;
    density = 0.0f;
    discoveredBy = QString("");
    yearDiscovered = 0;
    namedBy = QString("");
}

Element::Element(int atomicNumber, QString symbol, QString name, float atomicMass, QString category,
                 float electronegativity, QString phase, int period, int group, float meltingPoint, float boilingPoint,
                 float density, QString discoveredBy, int yearDiscovered, QString namedBy)
    : atomicNumber(atomicNumber), symbol(symbol), name(name), atomicMass(atomicMass), category(category),
      electronegativity(electronegativity), phase(phase), period(period), group(group), meltingPoint(meltingPoint),
      boilingPoint(boilingPoint), density(density), discoveredBy(discoveredBy), yearDiscovered(yearDiscovered),
      namedBy(namedBy)
{
}

Element::~Element()
{
}

// setters
void Element::set_atomic_number(int atomicNumber)
{
    this->atomicNumber = atomicNumber;
}
void Element::set_symbol(QString symbol)
{
    this->symbol = symbol;
}
void Element::set_name(QString name)
{
    this->name = name;
}

void Element::set_atomic_mass(float atomicMass)
{
    this->atomicMass = atomicMass;
}

void Element::set_category(QString category)
{
    this->category = category;
}

void Element::set_electronegativity(float electronegativity)
{
    this->electronegativity = electronegativity;
}

void Element::set_phase(QString phase)
{
    this->phase = phase;
}

void Element::set_period(int period)
{
    this->period = period;
}

void Element::set_group(int group)
{
    this->group = group;
}

void Element::set_melting_point(float meltingPoint)
{
    this->meltingPoint = meltingPoint;
}

void Element::set_boiling_point(float boilingPoint)
{
    this->boilingPoint = boilingPoint;
}

void Element::set_density(float density)
{
    this->density = density;
}

void Element::set_discovered_by(QString discoveredBy)
{
    this->discoveredBy = discoveredBy;
}

void Element::set_year_discovered(int yearDiscovered)
{
    this->yearDiscovered = yearDiscovered;
}

void Element::set_named_by(QString namedBy)
{
    this->namedBy = namedBy;
}

// getters
int Element::get_atomic_number()
{
    return atomicNumber;
}

QString Element::get_symbol()
{
    return symbol;
}

QString Element::get_name()
{
    return name;
}

float Element::get_atomic_mass()
{
    return atomicMass;
}

QString Element::get_category()
{
    return category;
}

float Element::get_electronegativity()
{
    return electronegativity;
}

QString Element::get_phase()
{
    return phase;
}

int Element::get_period()
{
    return period;
}

int Element::get_group()
{
    return group;
}

float Element::get_melting_point()
{
    return meltingPoint;
}

float Element::get_boiling_point()
{
    return boilingPoint;
}

float Element::get_density()
{
    return density;
}

QString Element::get_discovered_by()
{
    return discoveredBy;
}

int Element::get_year_discovered()
{
    return yearDiscovered;
}

QString Element::get_named_by()
{
    return namedBy;
}
