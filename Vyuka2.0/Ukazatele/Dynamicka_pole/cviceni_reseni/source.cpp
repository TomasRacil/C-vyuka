#include <iostream>

int **vytvorMatici(int radky, int sloupce)
{
    int **matice = new int *[radky];
    for (int i = 0; i < radky; i++)
    {
        matice[i] = new int[sloupce];
    }
    return matice;
}

int main()
{
    int radky, sloupce;
    std::cout << "Zadejte počet řádků: ";
    std::cin >> radky;
    std::cout << "Zadejte počet sloupců: ";
    std::cin >> sloupce;

    int **matice = vytvorMatici(radky, sloupce);

    for (int i = 0; i < radky; i++)
    {
        for (int j = 0; j < sloupce; j++)
        {
            matice[i][j] = i * sloupce + j + 1;
        }
    }

    for (int i = 0; i < radky; i++)
    {
        for (int j = 0; j < sloupce; j++)
        {
            std::cout << matice[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < radky; i++)
    {
        delete[] matice[i];
    }
    delete[] matice;

    return 0;
}
