#include <iostream>

using namespace std;

template<typename T>
void Swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

//void SwapInt(int& a, int& b) {
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//void SwapChar(char& a, char& b) {
//	int temp = a;
//	a = b;
//	b = temp;
//}

void main() {
	int a = 5, b = 7;
	cout << a << " - " << b << endl;

	//SwapInt(a, b);
	Swap(a, b);
	cout << a << " - " << b << endl;

	char d = 'd', c = 'c';
	cout << d << " - " << c << endl;
	//SwapChar(d, c);
	Swap(d, c);
	cout << d << " - " << c << endl;

	float i = 1.3, j = 4.2;
	cout << i << " - " << j << endl;
	Swap(i, j);
	cout << i << " - " << j << endl;

}
