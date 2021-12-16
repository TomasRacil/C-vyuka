#include <iostream>

using namespace std;

template<typename T>
void Swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}
void main() {
	int a = 5, b = 7;
	cout << a << " - " << b << endl;
	Swap<int>(a, b);
	cout << a << " - " << b << endl;

	char d = 'd', c = 'c';
	cout << d << " - " << c << endl;
	Swap(d, c);
	cout << d << " - " << c << endl;
}
