#include "knihovna.h"
#include <iostream>
#include <algorithm>

void Knihovna::pridejKnihu(Kniha kniha)
{
    seznamKnih.push_back(kniha);
}

void Knihovna::odeberKnihu(std::string nazev)
{
    seznamKnih.erase(std::remove_if(seznamKnih.begin(), seznamKnih.end(),
                                    [&](const Kniha &k)
                                    { return k.getNazev() == nazev; }),
                     seznamKnih.end());
}

Kniha Knihovna::najdiKnihu(std::string nazev)
{
    for (const auto &kniha : seznamKnih)
    {
        if (kniha.getNazev() == nazev)
        {
            return kniha;
        }
    }
    return Kniha("", "", 0); // Vraťte "prázdnou" knihu, pokud nenalezena
}

void Knihovna::vypisKnihy()
{
    if (seznamKnih.empty())
    {
        std::cout << "V knihovne nejsou zadne knihy." << std::endl;
        return;
    }
    for (const auto &kniha : seznamKnih)
    {
        std::cout << "Nazev: " << kniha.getNazev() << ", Autor: " << kniha.getAutor()
                  << ", Rok vydani: " << kniha.getRokVydani() << std::endl;
    }
}