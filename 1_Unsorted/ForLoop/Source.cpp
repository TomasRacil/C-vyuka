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
		//fact	1 1 2 6 24
		//i		1 2 3 4 5
	}
	/*for (number; number>0; number--) {
		factorial = factorial * number;
	}*/

	cout << factorial;
}