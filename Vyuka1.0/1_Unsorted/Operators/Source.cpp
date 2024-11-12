/*
Ukazka operatoru v c++
*/

#include <iostream>

using namespace std;

int main()
{
	/*
	matematicke operatory
	+,-,*,/,%
	*/
	cout << "5+2=" << 5 + 2 << "\n";
	cout << "5/2=" << 5 / 2 << "\n";
	cout << "5/2=" << 5 / 2.0 << "\n";
	cout << "5/2=2 a zbytek " << 5 % 2 << "\n";
	/*
	iteracni operatory
	++,--
	*/
	int number = 6;
	number++;
	cout << "cislo 6 zvetsene o jedna " << number << "\n";
	cout << "cislo 7 zvetsene o jedna ? " << number++ << "\n";
	cout << "cislo 7 zvetsene o jedna ? " << ++number << "\n";
	/*
	komparacni operatory
	<,>,<=,>=,==,!=
	*/
	int a = 5, b = 8;
	cout << "a vetsi jak b " << (a > b) << "\n";

	/*
	logicke operatory
	&&,||,!
	*/
	cout << "je a rovno 5 a b rovno 8 " << (a == 5 && b == 8) << "\n";

	/*
	dalsi matematicke operatory
	=,=+,=-,=*,=/,=%
	*/
	int x = 5;
	x += 7; //x=x+7
	cout << "cislo x zvetsene o 7 " << x << "\n";

	//system("pause>0");
}