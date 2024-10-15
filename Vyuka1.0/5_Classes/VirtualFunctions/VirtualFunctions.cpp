// VirtualFunctions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Animal
{
public:	
	void position();
	virtual void move() = 0;
protected:
	Animal(int startingPosition);
	int x = 0;	
};


class Turtle :public Animal
{
public:
	void move() { x += 5; };
	Turtle(int startignPosition);
};


class Cat : public Animal
{
public:
	void move() { x += 10; };
	Cat(int startignPosition);
};



int main() {
	

	Animal* cat = new Cat(10);
	cat->move();
	Animal* turtle = new Turtle(20);
	turtle ->move();
	
	Animal* animals[2] = { cat, turtle };

	for (int i = 0; i < 2;i++) {
		animals[i]->move();
		animals[i]->position();
	}



	return 1;
}


Animal::Animal(int startingPosition) {
	x = startingPosition;
	cout << "Constructor animal" << endl;
}

void Animal::position()
{
	std::cout << "On position: " << this->x << std::endl;
}



Turtle::Turtle(int startignPosition) :Animal(startignPosition)
{
	cout << "Constuctor Turtle" << endl;
}



Cat::Cat(int startignPosition) :Animal(startignPosition)
{
	cout << "Constuctor Cat" << endl;
}