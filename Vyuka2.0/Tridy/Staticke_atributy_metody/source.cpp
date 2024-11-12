#include <iostream>

class Pocitadlo
{
public:
    Pocitadlo() { pocet_instanci++; }
    ~Pocitadlo() { pocet_instanci--; }

    static int getPocetInstanci() { return pocet_instanci; }

private:
    static int pocet_instanci;
};

int Pocitadlo::pocet_instanci = 0; // Inicializace statického atributu

int main()
{
    Pocitadlo p1;
    std::cout << "Pocet instanci: " << Pocitadlo::getPocetInstanci() << std::endl;

    Pocitadlo p2;
    std::cout << "Pocet instanci: " << Pocitadlo::getPocetInstanci() << std::endl;

    return 0;
}