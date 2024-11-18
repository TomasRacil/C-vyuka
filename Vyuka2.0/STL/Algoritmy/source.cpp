#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> cisla = {5, 2, 8, 1, 9};

    // Seřazení vektoru
    sort(cisla.begin(), cisla.end());

    // Výpis seřazeného vektoru
    cout << "Seřazený vektor: ";
    for (int cislo : cisla)
    {
        cout << cislo << " ";
    }
    cout << endl; // Výstup: 1 2 5 8 9

    // Nalezení prvku
    auto it = find(cisla.begin(), cisla.end(), 5);
    if (it != cisla.end())
    {
        cout << "Prvek 5 nalezen na pozici " << distance(cisla.begin(), it) << endl;
    }

    return 0;
}