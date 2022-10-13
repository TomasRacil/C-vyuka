// Stromecek.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

string operator*(std::string s, size_t n)
{
	/*
	* operátor umožòující násobení øetìzcù 
	* vrací øetìzec s n-krát
	*/
	string ret;
	for (size_t i = 0; i < n; ++i)
	{
		ret = ret + s;
	}
	return ret;
}

int main()
{
	int vyska, kmen_v, kmen_s;
	cout << "Zadejte vysku koruny: ";
	cin >> vyska;
	cout << "Zadeje vysku kmene: ";
	cin >> kmen_v;
	cout << "Zadejte sirku kmene: ";
	cin >> kmen_s;

	for (int i = 1; i <= vyska; i++) {
		cout << string(vyska - i, ' ')<<string("* ")*i<<endl;
	}

	for (int i = 0; i < kmen_v; i++) {
		cout << string(vyska-(kmen_s/2)-1, ' ') << string(kmen_s, '#') << endl;
	}

}