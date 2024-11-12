#include <iostream>

using namespace std;

class Person
{
public:
    Person(bool genderValue, int heightValue, int ageValue);
    void setAge(int ageValue);
    int getAge();
    void changeGender(bool genderVal);
    void changeHeight(int heightVal);
    bool getGender();
    int getHeight();

private:
    void setHeight(int heightValue);
    bool gender;
    int height;
    int age;
};

Person::Person(bool genderValue, int heightValue, int ageValue)
{
    gender = genderValue;
    height = heightValue; // Oprava: přiřazení heightValue
    age = ageValue;
}

void Person::changeGender(bool genderVal)
{
    gender = genderVal;
}

void Person::changeHeight(int heightVal)
{
    setHeight(heightVal);
}

void Person::setAge(int ageValue)
{
    if (ageValue > 150)
    {
        cout << "Toto neni platna volba" << endl;
    }
    else
    {
        age = ageValue;
    }
}

int Person::getAge()
{
    return age;
}

bool Person::getGender()
{
    return gender;
}

int Person::getHeight()
{
    return height;
}

void Person::setHeight(int heightValue)
{
    height = heightValue;
}

int main()
{
    Person tomas(0, 175, 22); // Využití konstruktoru

    int vek;
    cout << tomas.getAge() << endl;
    cout << "Zadej novy vek:";
    cin >> vek;
    tomas.setAge(vek);
    cout << tomas.getAge() << endl;
    cout << tomas.getGender() << endl; // Použití metody getGender()
    cout << tomas.getHeight() << endl; // Použití metody getHeight()

    return 0;
}