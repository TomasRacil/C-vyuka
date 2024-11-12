#ifndef KNIHOVNA_H
#define KNIHOVNA_H

#include "kniha.h"
#include <vector>

class Knihovna
{
public:
    void pridejKnihu(Kniha kniha);
    void odeberKnihu(std::string nazev);
    Kniha najdiKnihu(std::string nazev);
    void vypisKnihy();

private:
    std::vector<Kniha> seznamKnih;
};

#endif