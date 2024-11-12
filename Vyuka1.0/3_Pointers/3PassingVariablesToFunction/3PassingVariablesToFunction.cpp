// 3PassingVariablesToFunction.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>

using namespace std;

int getMin(int numbers[], int size) {
	int min = numbers[0];
	for (int i = 1; i < size; i++) {
		if (numbers[i] < min) {
			min = numbers[i];
		}
	}
	return min;
}

int getMax(int numbers[], int size) {
	int max = numbers[0];
	for (int i = 1; i < size; i++) {
		if (numbers[i] > max) {
			max = numbers[i];
		}
	}
	return max;
}

void getMinMax(int numbers[], int size, int* min, int* max) {
	*max = numbers[0];
	*min = numbers[0];
	for (int i = 1; i < size; i++) {
		if (numbers[i] > *max) {
			*max = numbers[i];
		}
		else if (numbers[i] < *min)
		{
			*min = numbers[i];
		}
	}
}

int main()
{
	int numbers[5] = { 6,7,2,-3,9 };

	int min, max;

	cout << "Min is " << getMin(numbers, 5) << endl;
	cout << "Max is " << getMax(numbers, 5) << endl;

	getMinMax(numbers, 5, &min, &max);

	cout << "Min is " << min << " max is " << max << endl;

	return 0;
}