#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<string, int> osoby;

    osoby["Jan"] = 30;
    osoby["Petra"] = 25;
    osoby["Pavel"] = 40;
    osoby["Anna"] = 28;

    cout << "Záznamy v mapě:" << endl;
    for (auto const &[jmeno, vek] : osoby)
    {
        cout << jmeno << ": " << vek << endl;
    }

    string hledaneJmeno = "Petra";
    if (osoby.count(hledaneJmeno) > 0)
    {
        cout << "Věk osoby " << hledaneJmeno << " je " << osoby[hledaneJmeno] << endl;
    }
    else
    {
        cout << "Osoba s jménem " << hledaneJmeno << " nebyla nalezena." << endl;
    }

    string jmenoKOdstraneni = "Pavel";
    osoby.erase(jmenoKOdstraneni);

    cout << "Záznamy v mapě po odstranění:" << endl;
    for (auto const &[jmeno, vek] : osoby)
    {
        cout << jmeno << ": " << vek << endl;
    }

    return 0;
}