#include "Student.h"

Student::Student() : PrislusnikUO()
{
	setCiloStudenta();
	std::cout << "Prislusnik je studentem se studentskym cislem: " << cisloStudenta << std::endl;
}

Student::Student(std::string krestniJmeno, std::string prijmeni, std::string rodneCislo)
{
	setCiloStudenta();
	std::cout << "Prislusnik je studentem se studentskym cislem: " << cisloStudenta << std::endl;
}

void Student::setCiloStudenta()
{
	studentInstances++;
	cisloStudenta = (1970 + time(NULL) / 31537970) * 10000 + studentInstances;
}

int Student::getCisloStudenta()
{
	return 0;
}

Student::~Student() {
	std::cout << "Studen se studentskym cislem: " << cisloStudenta << " prestal byt studentem" << std::endl;
}