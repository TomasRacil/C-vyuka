#include <iostream>

using namespace std;

int main() {
	int n = 5;
	cout << n << endl;
	cout << &n << endl;

	int* ptr = &n;

	cout << ptr << endl;
	cout << *ptr << endl;

	*ptr = 8;

	cout << ptr << endl;
	cout << *ptr << endl;
	cout << n << endl;

	return 0;
}