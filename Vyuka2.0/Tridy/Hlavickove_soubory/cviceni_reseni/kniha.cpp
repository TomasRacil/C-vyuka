#include "kniha.h"

Kniha::Kniha(std::string nazev, std::string autor, int rokVydani)
    : nazev(nazev), autor(autor), rokVydani(rokVydani) {}

std::string Kniha::getNazev() const
{
    return nazev;
}

std::string Kniha::getAutor() const
{
    return autor;
}

int Kniha::getRokVydani() const
{
    return rokVydani;
}

void Kniha::setNazev(std::string nazev)
{
    this->nazev = nazev;
}

void Kniha::setAutor(std::string autor)
{
    this->autor = autor;
}

void Kniha::setRokVydani(int rokVydani)
{
    this->rokVydani = rokVydani;
}