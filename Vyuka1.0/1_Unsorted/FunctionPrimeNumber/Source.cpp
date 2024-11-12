#include <iostream>

using namespace std;

bool isPrimeNumber(int number) {
	for (int i = 2; i < number; i++) {
		if (number % i == 0)
			return false;
	}
	return true;
}

void main() {
	int number;
	cout << "Zadej cislo: ";
	cin >> number;

	bool isPrime = isPrimeNumber(number);

	if (isPrime)
		cout << "Prvocislo" << endl;
	else
		cout << "Neni prvocislo" << endl;

	//Najdi provcisla

	for (int i = 1; i <= 1000; i++) {
		if (isPrimeNumber(i))
			cout << i << endl;
	}
}