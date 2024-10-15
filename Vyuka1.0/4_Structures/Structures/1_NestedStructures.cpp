#include <iostream>
#include <string>

using namespace std;

struct Pet {
	string name;
	string kind;
};

struct Person
{
	string name;
	int age;
	bool male;
	Pet pet;
};

void printPersonAndPet(Person person);


int main() {

	Person personArr[5];
	string pNames[5] = {"Karolina","Jakub", "Ivana", "Premek", "Lucie"};
	int age[5] = { 25,19,52,70,22 };
	bool male[5] = { false, true, false, true, false };

	string aNames[5] = {"Viki", "Damian", "Dan", "Blemba", "Dex"};
	string kind[5] = { "cat", "cat", "dog", "turtle", "parrot" };
	
	for (int i = 0; i < 5; i++) {
		personArr[i] = {
			pNames[i],
			age[i],
			male[i],
			{
				aNames[i],
				kind[i]
			}
		};
	}

	for (int i = 0; i < 5; i++) {
		printPersonAndPet(personArr[i]);
	}


	return 0;
}

void printPersonAndPet(Person person)
{
	cout << person.name << " " << person.age << ((person.male) ? " male" : " female") << endl;
	cout << person.pet.name << " " << person.pet.kind << endl << endl;
}
