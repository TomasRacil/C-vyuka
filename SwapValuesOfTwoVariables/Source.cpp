/*
Jak vymenit hodnoty dvou promenych
*/
#include <iostream>

using namespace std;

int main()
{
	int a = 20;
	int b = 100;

	cout << "a=" << a << ",b=" << b << "\n";

	int temp = a;
	a = b;
	b = temp;

	cout << "a=" << a << ",b=" << b << "\n";

	a += b;
	b = a-b;
	a -= b;

	cout << "a=" << a << ",b=" << b << "\n";

	//system("pause>0");
}