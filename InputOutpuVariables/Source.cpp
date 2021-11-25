/*
Jednoduchý program prevadi spotrebu v l/100km na mpg
*/
#include <iostream>

using namespace std;

int main()
{
	float spotreba_l_100km;
	cout << "Zadej spotrebu auta (l/100km): ";
	cin >> spotreba_l_100km;
	float spotreba_mpg = 235.215 / spotreba_l_100km;
	cout << "Spotreba v mpg je: " << spotreba_mpg<<endl;
	cout << "Stiskni libovolnou klavesu pro ukonceni";
	system("pause>0");
}