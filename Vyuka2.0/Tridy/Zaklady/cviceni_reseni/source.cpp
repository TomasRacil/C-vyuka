#include <iostream>

class Obdelnik
{
private:
    int delka;
    int sirka;

public:
    // Konstruktor
    Obdelnik(int delka, int sirka)
    {
        this->delka = delka;
        this->sirka = sirka;
    }

    // Gettery
    int getDelka()
    {
        return delka;
    }

    int getSirka()
    {
        return sirka;
    }

    // Settery s kontrolou záporných hodnot
    void setDelka(int delka)
    {
        if (delka > 0)
        {
            this->delka = delka;
        }
        else
        {
            std::cout << "Chyba: Delka nemuze byt zaporna!" << std::endl;
        }
    }

    void setSirka(int sirka)
    {
        if (sirka > 0)
        {
            this->sirka = sirka;
        }
        else
        {
            std::cout << "Chyba: Sirka nemuze byt zaporna!" << std::endl;
        }
    }

    // Vypocet obsahu
    int obsah()
    {
        return delka * sirka;
    }

    // Vypocet obvodu
    int obvod()
    {
        return 2 * (delka + sirka);
    }

    // Kontrola, zda je obdelnik ctverec
    bool jeCtverec()
    {
        return delka == sirka;
    }
};

int main()
{
    // Vytvoreni instance obdelniku
    Obdelnik obdelnik1(5, 10);

    // Vypis informaci o obdelniku
    std::cout << "Delka: " << obdelnik1.getDelka() << std::endl;
    std::cout << "Sirka: " << obdelnik1.getSirka() << std::endl;
    std::cout << "Obsah: " << obdelnik1.obsah() << std::endl;
    std::cout << "Obvod: " << obdelnik1.obvod() << std::endl;
    std::cout << "Je ctverec: " << (obdelnik1.jeCtverec() ? "ano" : "ne") << std::endl;

    // Zmena delky a sirky
    obdelnik1.setDelka(7);
    obdelnik1.setSirka(-3); // Test zadání záporné hodnoty

    // Vypis informaci o obdelniku po zmene
    std::cout << "\nPo zmene:" << std::endl;
    std::cout << "Delka: " << obdelnik1.getDelka() << std::endl;
    std::cout << "Sirka: " << obdelnik1.getSirka() << std::endl;

    return 0;
}