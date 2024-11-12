#include <iostream>
#include <chrono>
using namespace std;

struct Pole
{
    int *radek;
    int delka;
};

void vytiskniPole(Pole *pole)
{
    for (int i = 0; i < pole->delka; i++)
    {
        cout << pole->radek[i] << ", ";
    }
    cout << endl;
}

void vytiskniPole(Pole pole)
{
    for (int i = 0; i < pole.delka; i++)
    {
        cout << pole.radek[i] << ", ";
    }
    cout << endl;
}

Pole *vytvoreniPole(int delka)
{
    Pole *pole = new Pole;
    pole->delka = delka;
    pole->radek = new int[delka];
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    srand(seed);
    for (int i = 0; i < delka; i++)
    {
        pole->radek[i] = rand() % 10;
    }
    return pole;
}

// Pole vytvoreniPole(int delka){
//     Pole pole;
//     pole.delka = delka;
//     pole.radek = new int[delka];
//     srand(time(NULL));
//     for (int i = 0; i < delka; i++)
//     {
//         pole.radek[i] = rand() % 10;
//     }
//     return pole;
// }

void odstraneniPole(Pole *pole)
{
    delete[] pole->radek;
    pole->radek = nullptr;
    delete pole;
    pole = nullptr;
}

void odstraneniPole(Pole pole)
{
    delete[] pole.radek;
    pole.radek = nullptr;
}

Pole *sectiPole(Pole *pole1, Pole *pole2)
{
    if (pole1->delka != pole2->delka)
    {
        return nullptr;
    }
    else
    {
        Pole *vysledek = vytvoreniPole(pole1->delka);
        for (int i = 0; i < pole1->delka; i++)
        {
            vysledek->radek[i] = pole1->radek[i] + pole2->radek[i];
        }
        return vysledek;
    }
}

int main()
{

    Pole *pole = vytvoreniPole(5);
    Pole *pole2 = vytvoreniPole(5);
    vytiskniPole(pole);
    vytiskniPole(pole2);
    Pole *soucet = sectiPole(pole, pole2);
    vytiskniPole(soucet);
    odstraneniPole(pole);
    odstraneniPole(pole2);
    odstraneniPole(soucet);

    return 0;
}