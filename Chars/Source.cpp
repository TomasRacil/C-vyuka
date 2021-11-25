/*
Prace se znaky
*/

#include <iostream>

using namespace std;

int main()
{

	cout << (int)'a' << "\n";
	cout << int('a') << "\n";
	cout << int('A') << "\n";
	cout << char(65) << "\n";

	char c1, c2, c3;
	cout << "zadej 3 znaky: \n";
	cin >> c1 >> c2 >> c3;
	cout << "prevedeno do asci: " << int(c1) << " " << int(c2) << " " << int(c3)<<"\n";
	cout << "prevedeno zpet na znaky: " << char(int(c1)) << " " << char(int(c2)) << " " << char(int(c3))<<"\n";

	system("pause>0");
}