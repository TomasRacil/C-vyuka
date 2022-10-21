#include <iostream>

using namespace std;

struct Person {
    char first_name[20];
    char last_name[20];
    int age;

};

void printPerson(Person person);
void changePersonAge(Person& person, int age);
void changePersonAge(Person* person, int age);

int main()
{
    Person person1;
    sprintf_s(person1.first_name, 20, "Pepa");
    sprintf_s(person1.last_name, 20, "Omacka");
    person1.age = 20;

    Person person2 = {
        "Josef",
        "Novy",
        18
    };

    printPerson(person2);
    changePersonAge(person2, 10);
    printPerson(person2);
    changePersonAge(&person2, 15);
    printPerson(person2);

}

void printPerson(Person person)
{
    cout << person.first_name << " " << person.last_name << " " << person.age << endl;;
}

void changePersonAge(Person& person, int age)
{
    person.age = age;
}

void changePersonAge(Person* person, int age)
{
    person->age = age*2;
}
