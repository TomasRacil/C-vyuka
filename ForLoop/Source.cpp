/*
For loop
*/

#include <iostream>

using namespace std;

void main() {
	int number;
	double factorial=1;
	cout << "Number: ";
	cin >> number;
	for (int i = 1; i <= number; i++) {
		factorial = factorial * i;
	}
	/*for (number; number>0; number--) {
		factorial = factorial * number;
	}*/
	cout << factorial;
}