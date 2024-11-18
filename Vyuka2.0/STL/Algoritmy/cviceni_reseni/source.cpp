#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

int main()
{
    vector<int> cisla(10);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    generate(cisla.begin(), cisla.end(), [&]()
             { return dist(gen); });

    cout << "Původní vektor: ";
    for_each(cisla.begin(), cisla.end(), [](int cislo)
             { cout << cislo << " "; });
    cout << endl;

    transform(cisla.begin(), cisla.end(), cisla.begin(), [](int cislo)
              { return cislo * 2; });

    int soucet = accumulate(cisla.begin(), cisla.end(), 0);
    cout << "Součet prvků: " << soucet << endl;

    auto maxPrvek = max_element(cisla.begin(), cisla.end());
    cout << "Největší prvek: " << *maxPrvek << endl;

    auto novyKonec = remove_if(cisla.begin(), cisla.end(), [](int cislo)
                               { return cislo % 2 == 0; });
    cisla.erase(novyKonec, cisla.end());

    cout << "Upravený vektor: ";
    for_each(cisla.begin(), cisla.end(), [](int cislo)
             { cout << cislo << " "; });
    cout << endl;

    return 0;
}