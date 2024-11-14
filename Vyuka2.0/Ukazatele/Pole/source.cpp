#include <iostream>

int main()
{
    int pole[5] = {10, 20, 30, 40, 50};
    int *ukazatel = pole;

    for (int i = 0; i < 5; i++)
    {
        std::cout << *(ukazatel + i) << " "; // Vypíše 10 20 30 40 50
    }
    std::cout << std::endl;

    return 0;
}