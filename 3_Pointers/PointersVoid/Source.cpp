#include <iostream>

using namespace std;

void printNumber(int* numberPtr) {
	cout << *numberPtr << endl;
}
void print(void* ptr, char type) {
	cout << ptr << endl;
	switch (type) {
	case 'i':cout << *((int*)ptr) << endl; break;
	case 'c':cout << *((char*)ptr) << endl; break;
	}
}

int main() {
	int n = 5;
	char letter = 'a';
	printNumber(&n);
	print(&n, 'i');
	print(&letter, 'c');

	return 0;
}