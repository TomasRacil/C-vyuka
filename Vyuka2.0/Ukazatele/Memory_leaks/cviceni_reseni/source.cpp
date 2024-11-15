#include <iostream>

int main()
{
    int velikost;
    std::cout << "Zadejte velikost pole: ";
    std::cin >> velikost;

    int *pole = new int[velikost];

    for (int i = 0; i < velikost; i++)
    {
        pole[i] = i * 10;
    }

    for (int i = 0; i < velikost; i++)
    {
        int *temp = pole + i;
        std::cout << *temp << " ";
    }
    std::cout << std::endl;

    // Záměrně vynecháno
    delete[] pole;

    return 0;
}
