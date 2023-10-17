#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

    int radky = 0;
    fstream myFile;
    myFile.open("2000.txt", ios::in);
    if (myFile.is_open()) 
    {
        string radek;                       // cteni a vypis ze souboru do konzole
        while (getline(myFile, radek))
        {
            radky++;                        // pocitam radky pro budouci pole
        }
        myFile.close();
    }

    int pole[radky];

    radky = 0;

    myFile.open("2000.txt", ios::in);
    if (myFile.is_open()) 
    {
        string radek;
        while (getline(myFile, radek))
        {
            pole[radky] = stoi(radek);      // nacteni souboru do pole,  stoi = prevod stringu na integer
            radky ++;
        }
        myFile.close();
    }

    for (int i = 0; i < radky; i++)         // porovnavani dvou cisel x + y = 2020
    {
        for (int j = 0; j < radky; j++)
        {
            if (pole[i] + pole[j] == 2020)
                cout << pole[i] << " + " << pole[j] << " = 2020" << endl;
        }
    }

    cout << endl;

    for (int i = 0; i < radky; i++)         // porovnavani tri cisel x + y + z = 2020
    {
        for (int j = 0; j < radky; j++)
        {
            for (int k = 0; k < radky; k++)
            {
                if (pole [i] + pole[j] + pole[k] == 2020)
                {
                    cout << pole[i] << " + " << pole[j] << " + " << pole[k] << " = 2020" << endl;
                }
            }
        }
    }

    return 0;
}