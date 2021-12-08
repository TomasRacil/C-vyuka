/*
Cyklus uvnitø cyklu
*/

#include <iostream>

using namespace std;

void main() {
	
	int grade, sum=0;

	for (int i = 0; i < 3; i++) {
		do {
			cout << "Zadej znamku " << i + 1 << ": ";
			cin >> grade;
		} while (grade<1||grade>5);
		sum += grade;
	}
	cout << "Prumerna znamka je " << sum / 3;
}