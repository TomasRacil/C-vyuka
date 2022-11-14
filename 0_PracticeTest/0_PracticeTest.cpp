// 0_PracticeTest.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Vozidlo {
public:
    Vozidlo();
    void NastavZnacku(string znacka);
    void NastavKm(int km);
    void NastavLitry(int l);
    void VypocetSpotreby();
    void Ukazpotrebu();

private:
    string Znacka;
    int UjetoKm;
    int Projeto;
    float Spotreba;
};

bool JePrvocislo(int cislo);
int CifernySoucet(int cislo);

int main()
{
    Vozidlo vozidlo;
    string tempS;
    int tempI;
    cout << "Zadejte znacku vozidla: ";
    cin >> tempS;
    vozidlo.NastavZnacku(tempS);
    cout << "Zadejte ujete kilometry: ";
    cin >> tempI;
    vozidlo.NastavKm(tempI);
    cout << "Zadejte projete litry: ";
    cin >> tempI;
    vozidlo.NastavLitry(tempI);
    vozidlo.VypocetSpotreby();
    vozidlo.Ukazpotrebu();

    int c13=0, c14=0;
    for (int i = 990000; i <= 1001000; i++) {
        if (JePrvocislo(i)) {
            if (CifernySoucet(i) == 13) c13++;
            else if (CifernySoucet(i) == 14) c14++;
        }
    }
    if (c13 > c14) cout << "Trinact je castejsi ciferny soucin s "<<c13<<" vyskyty" << endl;
    else cout << "Ctrnact je castejsi ciferny soucins " << c14 << " vyskyty" << endl;

}

bool JePrvocislo(int cislo) {
    for (int i = 2; i < (cislo / 2); i++) {
        if (cislo % i == 0) return false;
        else return true;
    }
}

int CifernySoucet(int cislo)
{
    int souc=0;
    while (cislo != 0) {
        souc += cislo % 10;
        cislo = cislo / 10;
    }
    return souc;
}

Vozidlo::Vozidlo()
{
    UjetoKm = 0;
    Projeto = 0;
    Spotreba = 0;
}

void Vozidlo::NastavZnacku(string znacka)
{
    Znacka = znacka;
}

void Vozidlo::NastavKm(int km)
{
    UjetoKm = km;
}

void Vozidlo::NastavLitry(int l)
{
    Projeto = l;
}

void Vozidlo::VypocetSpotreby()
{
    Spotreba = (float)Projeto / ((float)UjetoKm / 100.0);
}

void Vozidlo::Ukazpotrebu()
{
    cout << "Prumerna spotreba vozu " << Znacka << " je " << setprecision(2) << Spotreba << "l/100km.";
}
