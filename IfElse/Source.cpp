/*
Jednoduchý program demonstrujici vetveni
*/

#include <iostream>

using namespace std;

int main()
{
	int number;
	cout << "Zadej cele cislo: ";
	cin >> number;
	if (number % 2 == 0) {
		cout << "cislo je sude\n";
	}
	else {
		cout << "cislo je liche\n";
	}

	int a,b,c;
	cout << "Zadej delky stran trojuhlniku: \n";
	cin >> a >> b >> c;
	if (a==b&&b==c) {
		cout << "je to rovnostrany trojuhelnik";
	}
	else {
		if (a != b && b != c && c != a) {
			cout << "je to obecny trojuhelnik";
		}
		else {
			cout << "je to rovnorameny trojuhelnik";
		}
		
	}

	//int a, b, c;
	cout << "Zadej delky stran trojuhlniku: \n";
	cin >> a >> b >> c;
	if (a == b && b == c) {
		cout << "je to rovnostrany trojuhelnik";
	}
	else if (a != b && b != c && c != a) {
		cout << "je to obecny trojuhelnik";
	}
	else {
		cout << "je to rovnorameny trojuhelnik";
	}


	//system("pause>0");
}