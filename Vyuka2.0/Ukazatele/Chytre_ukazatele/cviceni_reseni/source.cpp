#include <iostream>
#include <memory>

// Funkce pro alokaci pole
std::unique_ptr<int[]> alokujPole(size_t velikost)
{
    // Alokace paměti pro pole o dané velikosti
    std::unique_ptr<int[]> pole = std::make_unique<int[]>(velikost);
    return pole;
}

int main()
{
    // Získání velikosti pole od uživatele
    size_t velikost;
    std::cout << "Zadejte velikost pole: ";
    std::cin >> velikost;

    // Alokace pole
    std::unique_ptr<int[]> pole = alokujPole(velikost);

    // Naplnění pole hodnotami
    for (size_t i = 0; i < velikost; ++i)
    {
        pole[i] = i * 2;
    }

    // Výpis pole na konzoli
    std::cout << "Pole: ";
    for (size_t i = 0; i < velikost; ++i)
    {
        std::cout << pole[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}