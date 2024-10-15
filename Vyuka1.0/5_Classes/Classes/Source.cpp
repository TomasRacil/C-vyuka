#include <iostream>

using namespace std;

class Person
{
public:
	bool gender;
	
	void setAge(int ageValue);
	int getAge();
	Person(bool genderValue, int heightValue, int ageValue);
	void changeHeightAndGender(bool genderVal, int heightVal);
private:
	void setHeight(int heightValue);
	int height;
	int age;

};
Person::Person(bool genderValue, int heightValue, int ageValue)
{
	gender = genderValue;
	height = height;
	age = ageValue;
}
void Person::changeHeightAndGender(bool genderVal, int heightVal)
{
	gender = genderVal;
	setHeight(heightVal);
}
void Person::setAge(int ageValue)
{
	if (ageValue > 150) {
		cout << "Toto neni platna volba" << endl;
	}
	else {
		age = ageValue;
	}
}
int Person::getAge()
{
	return age;
}

void Person::setHeight(int heightValue) {
	height = heightValue;
}


int main() {

	Person tomas(0,175,22);

	//tomas.setAge(20);

	//tomas.age = 20;
	tomas.gender = 0;
	tomas.height = 170;

	//cin >> tomas.age;
	int vek;
	cout << tomas.getAge() << endl;
	cout << "Zadej novy vek:";
	cin >> vek;
	tomas.setAge(vek);
	cout << tomas.getAge() << endl;
	cout << tomas.gender << endl;
	cout << tomas.height << endl;

	return 0;
}


