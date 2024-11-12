#ifndef KNIHA_H
#define KNIHA_H

#include <string>

class Kniha
{
public:
    Kniha(std::string nazev, std::string autor, int rokVydani);
    std::string getNazev() const;
    std::string getAutor() const;
    int getRokVydani() const;
    void setNazev(std::string nazev);
    void setAutor(std::string autor);
    void setRokVydani(int rokVydani);

private:
    std::string nazev;
    std::string autor;
    int rokVydani;
};

#endif