#include <iostream>
#include <string>

using namespace std;

struct Person
{
	int height;
	int age;
	bool gender;
};

int main() {

	struct Person pole_osob[5];

	for (int i = 0; i < 5; i++) {
		pole_osob[i] = {
			170+i,
			20,
			0
		};
	};

	cout << pole_osob[0].age << endl;

	int vyska_celkem = 0;

	for (int i = 0; i < 5; i++) {
		vyska_celkem += pole_osob[i].height;
	}
	cout << vyska_celkem / 5 << endl;

	//for(int i=0;i)

	return 0;
}