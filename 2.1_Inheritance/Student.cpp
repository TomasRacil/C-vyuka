#include "Student.h"

Student::Student(): PrislusnikUO()
{
	this->cisloStudenta = 0;
}

Student::Student(std::string krestniJmeno, std::string prijmeni, std::string rodneCislo)
{
	setCiloStudenta(0); //automaticky generovane
	std::cout << "Prislusnik je studentem se studentskym cislem: " << cisloStudenta << std::endl;
}

void Student::setCiloStudenta(int cisloStudenta)
{
	this->cisloStudenta = 0; //automaticky generovane
}

int Student::getCisloStudenta()
{
	return 0;
}

Student::~Student() {
	std::cout << "Studen se studentskym cislem: " << cisloStudenta << " prestal byt studentem" << std::endl;
}