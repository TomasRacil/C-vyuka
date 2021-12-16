/*
Cyklus uvnitø cyklu
*/

#include <iostream>
#include <iomanip>

using namespace std;

void main() {

	int grade, sum = 0;

	for (int i = 0; i < 3; i++) {
		do {
			cout << "Zadej znamku " << i + 1 << ": ";
			cin >> grade;
		} while (grade < 1 || grade>5);
		sum += grade;
	}
	cout << "Prumerna znamka je " << sum / 3.0<<endl;

	//tabulka násobení
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			cout << i << " * " << j << " = " << i * j<<endl;
		}
		cout << endl;
	}

	//obdelniky
	int sirka, vyska;
	char symbol;
	cout << "Zadej sirku obdelniku: ";
	cin >> sirka;
	cout << "Zadej vysku obdelniku: ";
	cin >> vyska;
	cout << "Zadej symbol: ";
	cin >> symbol;

	for (int i = 0; i < vyska; i++) {
		cout << endl;
		for (int j = 0; j < sirka; j++) {
			cout <<setw(3)<< symbol;
		}
	}
	cout << endl;

	//trojuhelnik
	int delka;
	cout << "Zadej delku zakladny trojuhelniku: ";
	cin >> delka;
	cout << "Zadej symbol: ";
	cin >> symbol;

	for (int i = 0; i <= delka; i++) {
		
		for (int j = 0; j <= i; j++) {
			cout << setw(3) << symbol;
		}
		cout << endl;
	}
	cout << endl << endl;
	for (int i = delka; i >= 0; i--) {

		for (int j = 0; j <= i; j++) {
			cout << setw(3) << symbol;
		}
		cout << endl;
	}
}