#include <iostream>

using namespace std;

const float M_KM = 1.60934;
const float G_L = 3.78541;

float MPG_l100km(float MPG)
{
    float galony_mile = 1 / MPG;
    float galony_km = galony_mile / M_KM;
    float litry_km = galony_km * G_L;
    float l_100km = litry_km * 100;
    return l_100km;
}

float l100km_MPG(float l_100km)
{
    float galony_100km = l_100km / G_L;
    float galony_na_km = galony_100km / 100;
    float galony_na_mili = galony_na_km * M_KM;
    float MPG = 1 / galony_na_mili;
    return MPG;
}

void dotazNaLitry()
{
    float vstup_prevod;
    cout << "Zadej pocet mili na galon: ";
    cin >> vstup_prevod;
    cout << "Spotreba v litrech na 100 km je: " << MPG_l100km(vstup_prevod) << endl;
}

void dotazNaGalony()
{
    float vstup_prevod;
    cout << "Zadej spotrebu l na 100 km: ";
    cin >> vstup_prevod;
    cout << "Dojezd v milich na galon je: " << l100km_MPG(vstup_prevod) << endl;
}

int main()
{

    char vyber;
    float vstup_prevod;
    do
    {
        cout << "Chcete zahajit prevod z MPG na l/100km (L) nebo z l/100km na MPG (G)?" << endl;
        cin >> vyber;
        switch (vyber)
        {
        case 'L':
            dotazNaLitry();
            break;
        case 'G':
            dotazNaGalony();
            break;
        default:
            break;
        }
        cout << "Checete pokracovat v prevodu? (A-pro pokracovat)" << endl;
        cin >> vyber;
    } while (vyber == 'A');

    return 0;
}

/*
    float galony_mile = 1 / MPG;
    float galony_km = galony_mile / M_KM;
    float litry_km = galony_km * G_L;
    float l_100km = litry_km * 100;
    return l_100km;

    float galony_100km = l_100km / G_L;
    float galony_na_km = galony_100km / 100;
    float galony_na_mili = galony_na_km * M_KM;
    float MPG = 1 / galony_na_mili;
    return MPG;
*/
