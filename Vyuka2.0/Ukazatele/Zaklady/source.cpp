#include <iostream>

int main()
{
    int cislo = 10;
    int *ukazatel = &cislo;

    std::cout << "Hodnota cislo: " << cislo << std::endl;
    std::cout << "Adresa cislo: " << &cislo << std::endl;
    std::cout << "Hodnota ukazatel: " << ukazatel << std::endl;
    std::cout << "Hodnota *ukazatel: " << *ukazatel << std::endl;

    *ukazatel = 20;
    std::cout << "Hodnota cislo po zmene: " << cislo << std::endl;

    return 0;
}