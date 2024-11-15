#include <iostream>

int main()
{
    int pole[5] = {10, 20, 30, 40, 50};
    // int *ukazatel = pole;

    // std::cout << *(pole + 1) << std::endl;

    for (int i = 0; i < 5; i++)
    {
        std::cout << *(pole + i) << " ";
    }
    std::cout << std::endl;

    return 0;
}