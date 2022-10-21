// 0Numwitch.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>

void switchNum(std::initializer_list<int*> list);
void printNum(std::initializer_list<int> list);

int main()
{
	int a = 1, b = 2, c = 3, d=4;
	printNum({ a, b, c , d});
	for (int i = 0; i < 4; i++) {
		switchNum({ &a,&b,&c ,&d });
		printNum({ a,b,c, d });
	}
}

void switchNum(std::initializer_list<int*> list)
{
	int temp = **(list.end()-1);
	for (int* elem : list) {
		*elem += temp;
		temp = *elem - temp;
		*elem -= temp;
	}
}

void printNum(std::initializer_list<int> list)
{
	for (int elem : list) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;
}
