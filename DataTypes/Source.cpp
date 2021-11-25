/*
Ukazka datovych typu
*/
#include <iostream>

using namespace std;

int main()
{
	int yearOfBirth = 1996;
	char gender = 'm';
	bool isStudent = true;
	float height = 1.83; //4bytes
	double ageOfTheUniverseInDays = 5032255000000;
	//double totalComputingPower = 200000000000000000000;

	cout << "Velikost datoveho typu int je " << sizeof(int) << "bytu\n";
	cout << "Minimalni velikost datoveho typu int je " << INT_MIN << "\n";
	cout << "Maximalni velikost datoveho typu int je " << INT_MAX << "\n";
	cout << "Velikost datoveho typu unsigned int je " << sizeof(unsigned int) << "\n";
	//cout << "Minimalni velikost datoveho typu unsigned int je " << UINT_MIN << "\n";
	cout << "Maximalni velikost datoveho typu unsigned int je " << UINT_MAX << "\n";
	cout << "Velikost datoveho typu char je " << sizeof(char) << "bytu\n";
	cout << "Velikost datoveho typu bool je " << sizeof(bool) << "bytu\n";
	cout << "Velikost datoveho typu float je " << sizeof(float) << "bytu\n";
	cout << "Velikost datoveho typu double je " << sizeof(double) << "bytu\n\n";

	//data type overflow
	int maxValue = INT_MAX;
	cout << "Hodnota v maxValue " << maxValue << "\n";
	maxValue++;
	cout << "Hodnota v maxValue " << maxValue << "\n";

	system("pause>0");
}