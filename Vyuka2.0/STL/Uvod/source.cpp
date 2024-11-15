#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    // Vytvoření vektoru celých čísel
    std::vector<int> cisla = {5, 2, 8, 1, 9};

    // Výpis neřazeného vektoru
    std::cout << "Nerazena cisla: ";
    for (int cislo : cisla)
    {
        std::cout << cislo << " ";
    }
    std::cout << std::endl;

    // Seřazení vektoru pomocí algoritmu sort
    std::sort(cisla.begin(), cisla.end());

    // Výpis seřazeného vektoru
    std::cout << "Serazena cisla: ";
    for (int cislo : cisla)
    {
        std::cout << cislo << " ";
    }
    std::cout << std::endl;

    return 0;
}