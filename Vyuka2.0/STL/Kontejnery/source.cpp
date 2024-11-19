#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    // Sekvenční kontejnery

    // Vektor
    vector<int> cisla = {1, 5, 2, 4, 3};
    cisla.push_back(6);
    cout << "Vektor: ";
    for (int cislo : cisla)
    {
        cout << cislo << " ";
    }
    cout << endl;

    // List
    list<string> jmena = {"Anna", "Petr", "Jan"};
    jmena.push_back("Jana");
    cout << "List: ";
    for (string jmeno : jmena)
    {
        cout << jmeno << " ";
    }
    cout << endl;

    // Deque
    deque<double> teploty = {25.5, 24.8, 26.1};
    teploty.push_back(27.3);
    cout << "Deque: ";
    for (double teplota : teploty)
    {
        cout << teplota << " ";
    }
    cout << endl;

    // Asociativní kontejnery

    // Set
    set<char> znaky = {'a', 'c', 'b', 'a'};
    znaky.insert('d');
    cout << "Set: ";
    for (char znak : znaky)
    {
        cout << znak << " ";
    }
    cout << endl; // Výstup: a b c

    // Map
    map<string, int> vek = {{"Anna", 25}, {"Petr", 30}};
    vek["Jan"] = 30;
    cout << "Map: ";
    for (auto const &[klic, hodnota] : vek)
    {
        cout << klic << ":" << hodnota << " ";
    }
    cout << endl;

    // Kontejnery adaptérů

    // Stack
    stack<int> zasobnik;
    zasobnik.push(1);
    zasobnik.push(2);
    zasobnik.push(3);
    cout << "Zasobnik: ";
    while (!zasobnik.empty())
    {
        cout << zasobnik.top() << " ";
        zasobnik.pop();
    }
    cout << endl;

    // Queue
    queue<int> fronta;
    fronta.push(1);
    fronta.push(2);
    fronta.push(3);
    cout << "Fronta: ";
    while (!fronta.empty())
    {
        cout << fronta.front() << " ";
        fronta.pop();
    }
    cout << endl;

    return 0;
}