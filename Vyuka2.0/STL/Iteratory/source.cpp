#include <iostream>
#include <vector>

int main()
{
    std::vector<int> cisla = {10, 20, 30, 40, 50};

    // Vypíšeme prvky vektoru pomocí iterátoru
    for (std::vector<int>::iterator it = cisla.begin(); it != cisla.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}