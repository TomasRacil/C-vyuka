/*
Jednoducha kalkulacka
*/
#include <iostream>

using namespace std;

int main()
{
	float a, b;
	char operation;
	cout << "Zadej cislo operaci a cislo \n";
	cin>> a >> operation >> b;

	switch (operation)
	{
	case'-': cout << "=" << a - b << "\n"; break;
	case'+': cout << "=" << a + b << "\n"; break;
	case'/': cout << "=" << a / b << "\n"; break;
	case'*': cout << "=" << a * b << "\n"; break;
	case'%':
		bool isAInt, isBInt;
		isAInt = int(a) == a;
		isBInt = int(b) == b;
		if (isAInt && isBInt) {
			cout << "=" << (int(a) % int(b)) << "\n"; break;
		}
		else {
			cout << "operace neni validni \n";
		}
		
	default: cout << "operace neni validni \n"; break;
	}

	//system("pause>0");
}