#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;

int faktorial(int cislo)
{
    if (cislo < 0)
    {
        throw invalid_argument("Cislo je mensi jak nula.");
    }
    int faktorial = 1;
    for (int i = 1; i <= cislo; ++i)
    {
        faktorial *= i;
    }
    return faktorial;
}

int faktorial_rekurze(int cislo)
{
    if (cislo < 0)
    {
        throw invalid_argument("Cislo je mensi jak nula.");
    }
    if (cislo == 0)
    {
        return 1;
    }
    else
    {
        return cislo * faktorial_rekurze(cislo - 1);
    }
}

bool kontrolaHesla(const string &heslo)
{
    if (heslo.length() < 8)
    {
        return false;
    }

    bool maVelkePismeno = false;
    bool maMalePismeno = false;
    bool maCislici = false;

    for (char znak : heslo)
    {
        if (isupper(znak))
        {
            maVelkePismeno = true;
        }
        else if (islower(znak))
        {
            maMalePismeno = true;
        }
        else if (isdigit(znak))
        {
            maCislici = true;
        }
    }

    return maVelkePismeno && maMalePismeno && maCislici;
}

void hadejNahodneCislo()
{
    srand(time(0));

    int nahodneCislo = rand() % 10 + 1;

    int tip;
    int pocetPokusu = 0;

    cout << "Myslim si cislo mezi 1 a 100. Zkus ho uhodnout!" << endl;

    do
    {
        cout << "Zadej svuj tip: ";
        cin >> tip;
        pocetPokusu++;

        if (tip < nahodneCislo)
        {
            cout << "Moje cislo je vetsi." << endl;
        }
        else if (tip > nahodneCislo)
        {
            cout << "Moje cislo je mensi." << endl;
        }
        else
        {
            cout << "Gratuluji! Uhodl jsi moje cislo " << nahodneCislo << " na " << pocetPokusu << " pokusu." << endl;
        }
    } while (tip != nahodneCislo);
}

int main()
{
    int cislo;

    cout << "Zadejte cele cislo: ";
    cin >> cislo;

    try
    {
        cout << "Faktorial cisla " << cislo << " je: " << faktorial(cislo) << endl;
        cout << "Faktorial cisla " << cislo << " je: " << faktorial_rekurze(cislo) << endl;
    }
    catch (const std::exception &e)
    {
        cerr << e.what() << '\n';
    }

    string heslo;

    cout << "Zadejte heslo: ";
    cin >> heslo;

    if (kontrolaHesla(heslo))
    {
        cout << "Platne" << endl;
    }
    else
    {
        cout << "Neplatne" << endl;
    }

    hadejNahodneCislo();

    return 0;
}