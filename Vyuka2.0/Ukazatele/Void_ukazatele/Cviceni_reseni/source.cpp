#include <iostream>
#include <cstring>

void prohod(void *a, void *b, int velikost)
{
    char *charA = static_cast<char *>(a);
    char *charB = static_cast<char *>(b);
    char temp[velikost];
    memcpy(temp, charA, velikost);
    memcpy(charA, charB, velikost);
    memcpy(charB, temp, velikost);
}

int main()
{
    int cislo1 = 10;
    double cislo2 = 3.14;

    std::cout << "Před prohozením:" << std::endl;
    std::cout << "cislo1: " << cislo1 << std::endl;
    std::cout << "cislo2: " << cislo2 << std::endl;

    prohod(&cislo1, &cislo2, sizeof(int));

    std::cout << "Po prohození:" << std::endl;
    std::cout << "cislo1: " << cislo1 << std::endl;
    std::cout << "cislo2: " << cislo2 << std::endl;

    return 0;
}
