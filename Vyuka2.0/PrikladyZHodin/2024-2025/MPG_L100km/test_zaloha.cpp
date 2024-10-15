#include <iostream>

using namespace std;

const float mil_to_km = 1.60934;
const float gal_to_liter = 3.78541;

float prevodMPG_L100(float mile_na_galon)
{
    float galony_mile = 1 / mile_na_galon;
    float galony_km = galony_mile / mil_to_km;
    float litry_km = galony_km * gal_to_liter;
    float litry_100km = litry_km * 100;
    return litry_100km;
    // return 100 / (mile_na_galon / gal_to_liter * mil_to_km);
}

float prevodL100_MPG(float litry_100km)
{
    float galony_100km = litry_100km * (1 / gal_to_liter);
    float galony_na_km = galony_100km / 100;
    float galony_na_mili = galony_na_km * mil_to_km;
    float mili_na_galon = 1 / galony_na_mili;
    return mili_na_galon;
    // return (100 * gal_to_liter / mil_to_km) / liters;
}

int main()
{
    char vyber;
    float vstup_prevod;

    cout << "Chcete zahajit prevod MPG na L/100km (L) nebo L/100km na MPG (G)?" << endl;
    cin >> vyber;

    switch (vyber)
    {
    case 'L':
        cout << "Zadej pocet mili na galon: ";
        cin >> vstup_prevod;
        cout << "Spotreba v litrech je: " << prevodMPG_L100(vstup_prevod) << endl;
        break;
    case 'G':
        cout << "Zadej pocet l na 100 km: ";
        cin >> vstup_prevod;
        cout << "Kolik mili na galon: " << prevodL100_MPG(vstup_prevod) << endl;
        ;
        break;
    default:
        cout << "Toto neni platna volba" << endl;
        break;
    }

    return 0;
}
