#include "knihovna.h"
#include <iostream>
#include <limits> // Pro numeric_limits

int main()
{
    Knihovna knihovna;
    int volba;

    do
    {
        std::cout << "\nMenu:\n";
        std::cout << "1. Pridat knihu\n";
        std::cout << "2. Odebrat knihu\n";
        std::cout << "3. Vyhledat knihu\n";
        std::cout << "4. Vypis vsechny knihy\n";
        std::cout << "0. Konec\n";
        std::cout << "Zadejte volbu: ";
        std::cin >> volba;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Vyčištění bufferu

        switch (volba)
        {
        case 1:
        {
            std::string nazev, autor;
            int rok;
            std::cout << "Zadejte nazev knihy: ";
            std::getline(std::cin, nazev);
            std::cout << "Zadejte autora knihy: ";
            std::getline(std::cin, autor);
            std::cout << "Zadejte rok vydani knihy: ";
            std::cin >> rok;
            knihovna.pridejKnihu(Kniha(nazev, autor, rok));
            break;
        }
        case 2:
        {
            std::string nazev;
            std::cout << "Zadejte nazev knihy k odebrani: ";
            std::getline(std::cin, nazev);
            knihovna.odeberKnihu(nazev);
            break;
        }
        case 3:
        {
            std::string nazev;
            std::cout << "Zadejte nazev knihy k vyhledani: ";
            std::getline(std::cin, nazev);
            Kniha nalezenaKniha = knihovna.najdiKnihu(nazev);
            if (nalezenaKniha.getNazev() != "")
            {
                std::cout << "Nalezena kniha:\n";
                std::cout << "Nazev: " << nalezenaKniha.getNazev() << ", Autor: "
                          << nalezenaKniha.getAutor() << ", Rok vydani: "
                          << nalezenaKniha.getRokVydani() << std::endl;
            }
            else
            {
                std::cout << "Kniha nenalezena." << std::endl;
            }
            break;
        }
        case 4:
            knihovna.vypisKnihy();
            break;
        case 0:
            std::cout << "Konec programu.\n";
            break;
        default:
            std::cout << "Neplatna volba.\n";
        }
    } while (volba != 0);

    return 0;
}