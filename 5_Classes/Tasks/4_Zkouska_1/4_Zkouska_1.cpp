
#include <iostream>
#include "Cesta.h"
#include "Vozidlo.h"

int main()
{
    Cesta cesta("cesta.txt", 37.6f);
    std::cout << cesta << std::endl;
    Vozidlo nove_auto("Ford", "Focus", 5.8);
    cesta.pridej_vozidlo(nove_auto);
    cesta.get_vozidlo(0).spocitej_spotrebu(85, 4.3);
    std::cout << cesta << std::endl;
    std::cout << cesta.spocitej_celkovou_spotrebu() << std::endl;
    std::cout << cesta.spocitej_celkovou_cenu() << std::endl;
    std::cout << cesta;
}
