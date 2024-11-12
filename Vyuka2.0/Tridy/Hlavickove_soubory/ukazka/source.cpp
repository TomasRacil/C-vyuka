#include <iostream>
#include "person.h"

int main()
{
    Person osoba("Jan", 30);
    std::cout << "Jmeno: " << osoba.getJmeno() << std::endl;
    std::cout << "Vek: " << osoba.getVek() << std::endl;

    return 0;
}