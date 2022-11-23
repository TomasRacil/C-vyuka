
// FriendFunctions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Person {
private:
    int age;
    std::string name;

public:
    Person(std::string name, int age ) { this->name = name;   this->age = age; };

    friend void print(Person);
};

void print(Person per) {
    std::cout << per.name << " is " << per.age << "vyears old" << std::endl;
}

int main()
{
    Person per("Jakub", 25);
    print(per);

}
