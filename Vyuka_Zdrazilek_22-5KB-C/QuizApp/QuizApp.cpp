#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Otazka
{
    string otazka;
    string a;
    string b;
    string c;
    char reseni;
};

int main()
{
    fstream myFile;
    char odpoved;
    int skore = 0;
    int pocet_otazek = 0;
    vector<string> otazky;

    cout << endl;
	myFile.open("questions.txt", ios::in);
	if (myFile.is_open()) 
    {
		string radek;
		while (getline(myFile,radek))
		{
            Otazka otazka;
            stringstream ss(radek);             // fce na rozkouskovani otazky v radku
            getline(ss, otazka.otazka, ';');
            getline(ss, otazka.a, ';');
            getline(ss, otazka.b, ';');
            getline(ss, otazka.c, ';');

            ss >> otazka.reseni;
            cout << otazka.otazka << " " << otazka.a << " " << otazka.b << " " << otazka.c << " (a, b, c): ";
            cin >> odpoved;
            pocet_otazek++;
            if (odpoved == otazka.reseni)
            {
                cout << "Spravne!" << endl;
                skore++;
            }
            else
                cout << "Spatne..." << endl; 
		}

        cout << endl << "Gratulujeme, vase skore je " << skore << " z " << pocet_otazek << " otazek." << endl; 

		myFile.close();
	}

    return 0;
}