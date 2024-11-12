#include <iostream>

using namespace std;

int main()
{
	/*int luckyNumbers[5] = { 2,3,4,6,8 };
	cout << luckyNumbers << endl;
	cout << &luckyNumbers[0] << endl;
	cout << luckyNumbers[2] << endl;
	cout << *(luckyNumbers + 2) << endl;*/
	int luckyNumbers[5];

	for (int i = 0; i <= 5; i++)
	{
		cout << "Number: ";
		cin >> luckyNumbers[i];
	}

	for (int i = 0; i <= 5; i++)
	{
		cout << luckyNumbers[i] << " ";
	}
	cout << endl;
	for (int i = 0; i <= 10; i++)
	{
		cout << luckyNumbers + i << " : " << *(luckyNumbers + i) << endl;
	}
}