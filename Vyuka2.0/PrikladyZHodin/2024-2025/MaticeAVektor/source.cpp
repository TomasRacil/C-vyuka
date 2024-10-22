#include <iostream>
#include <chrono>

using namespace std;

struct Vektor
{
    int pocet_hodnot;
    int *hodnoty;
};

struct Matice
{
    int pocet_radku;
    Vektor *radky;
};

void vytiskniVektor(Vektor *vektor)
{
    for (int i = 0; i < vektor->pocet_hodnot; i++)
    {
        cout << vektor->hodnoty[i] << "\t";
    }
}
void vytiskniMatici(Matice *matice)
{
    if (matice == nullptr)
    {
        return;
    }
    for (int i = 0; i < matice->pocet_radku; i++)
    {
        vytiskniVektor(&(matice->radky[i]));
        cout << endl;
    }
}
// void vytiskniMatici(int **matice, int r, int s)
// {
//     for (int i = 0; i < r; i++)
//     {
//         for (int j = 0; j < s; j++)
//         {
//             cout << matice[i][j] << "\t";
//         }
//         cout << endl;
//     }
// }

Vektor *vytvorVektor(int pocet_hodnot)
{
    Vektor *vektor = new Vektor;
    vektor->pocet_hodnot = pocet_hodnot;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    srand(seed);
    vektor->hodnoty = new int[pocet_hodnot];
    for (int i = 0; i < vektor->pocet_hodnot; i++)
    {
        vektor->hodnoty[i] = rand() % 10;
    }
    return vektor;
}

Matice *vytvorMatici(int pocet_sloupcu, int pocet_radku)
{
    Matice *matice = new Matice;
    matice->pocet_radku = pocet_radku;
    matice->radky = new Vektor[pocet_radku];

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    srand(seed);

    for (int i = 0; i < matice->pocet_radku; i++)
    {
        // Directly assign the address of the created Vektor
        matice->radky[i] = *vytvorVektor(pocet_sloupcu);
    }

    return matice;
}

// int **vytvoreniMatice(int r, int s)
// {
//     int **matice = new int *[r];
//     // srand(time(NULL));
//     unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//     srand(seed);
//     for (int i = 0; i < r; i++)
//     {
//         matice[i] = new int[s];
//         for (int j = 0; j < s; j++)
//         {
//             matice[i][j] = rand() % 10;
//         }
//     }
//     return matice;
// }

void odstraneniVektoru(Vektor *vektor)
{
    if (vektor == nullptr)
    {
        return;
    }
    delete[] vektor->hodnoty;
    vektor->hodnoty = nullptr;
}

void odstraneniMatice(Matice *matice)
{
    if (matice == nullptr)
    {
        return;
    }
    for (int i = 0; i < matice->pocet_radku; i++)
    {
        odstraneniVektoru(&(matice->radky[i]));
    }
    delete[] matice->radky;
    matice->radky = nullptr;
    delete matice;
    matice = nullptr;
}

// void odstraneniMatice(int **matice, int r)
// {
//     for (int i = 0; i < r; i++)
//     {
//         delete[] matice[i];
//     }
//     delete[] matice;
//     matice = nullptr;
// }

int main()
{
    int radky = 0, sloupce = 0;
    cout << "Zadejte pocet radku: ";
    cin >> radky;

    cout << "Zadejte pocet sloupcu: ";
    cin >> sloupce;

    Matice *matice = vytvorMatici(sloupce, radky);

    cout << "Vypis matici:" << endl;

    vytiskniMatici(matice);

    cout << "Zadejte pocet radku: ";
    cin >> radky;

    cout << "Zadejte pocet sloupcu: ";
    cin >> sloupce;

    Matice *matice2 = vytvorMatici(sloupce, radky);

    cout << "Vypis matici:" << endl;

    vytiskniMatici(matice2);

    // cout << "Soucet matic:" << endl;

    // Matice *vyslednaMatice = sectiMatice(matice, matice2);

    // vytiskniMatici(vyslednaMatice);

    // Matice *vyslednaMatice2 = vynasobMatice(matice, matice2);

    // cout << "Vynasobeni matic:" << endl;

    // vytiskniMatici(vyslednaMatice2);

    odstraneniMatice(matice);
    odstraneniMatice(matice2);
    // odstraneniMatice(vyslednaMatice);
    // odstraneniMatice(vyslednaMatice2);

    return 0;
}