/*
Demonstrace switch case; vužití pro výpis poètu dnù v mìsící
*/

#include <iostream>

using namespace std;

int main()
{

	int year, month;
	cout << "Year, month: ";
	cin >> year >> month;

	switch (month) {
	case 2:(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) ? 
		cout << "29 dni v mesici" : cout << "28 dni v mesici"; break;
	case 4:
	case 6:
	case 9:
	case 11: cout << "30 dni v mesici"; break;
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: cout << "31 dni v mesici"; break;
	default: cout << "Neplatne zadani";
	}
}