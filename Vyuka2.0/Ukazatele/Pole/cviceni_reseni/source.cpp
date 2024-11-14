#include <iostream>

int sectiPole(int *pole, int velikost)
{
    int soucet = 0;
    for (int i = 0; i < velikost; i++)
    {
        soucet += *(pole + i);
        // soucet += pole[i];
    }
    return soucet;
}

int main()
{
    int pole[5] = {10, 20, 30, 40, 50};
    int soucet = sectiPole(pole, 5);
    std::cout << "Soucet prvku pole: " << soucet << std::endl;
    return 0;
}
