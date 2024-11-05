#include <iostream>
#include <vector>

using namespace std;

class Animal
{
public:
    virtual void move() = 0;
    void position()
    {
        std::cout << "Na pozici: " << x << std::endl;
    }

protected:
    Animal(int startingPosition) : x(startingPosition)
    {
        cout << "Konstruktor Animal" << endl;
    }
    int x;
};

class Turtle : public Animal
{
public:
    void move() override { x += 5; }
    Turtle(int startingPosition) : Animal(startingPosition)
    {
        cout << "Konstruktor Turtle" << endl;
    }
};

class Cat : public Animal
{
public:
    void move() override { x += 10; }
    Cat(int startingPosition) : Animal(startingPosition)
    {
        cout << "Konstruktor Cat" << endl;
    }
};

int main()
{
    // Vytvoření závodníků
    vector<Animal *> animals;
    animals.push_back(new Cat(10));
    animals.push_back(new Turtle(20));

    // Simulace závodu
    for (int round = 1; round <= 5; ++round)
    {
        cout << "\nKolo " << round << ":" << endl;
        for (auto animal : animals)
        {
            animal->move();
            animal->position();
        }
    }

    // Uvolnění paměti
    for (auto animal : animals)
    {
        delete animal;
    }

    return 0;
}