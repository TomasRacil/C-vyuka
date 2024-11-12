#include "VojenskyStudent.h"

VojenskyStudent::VojenskyStudent(): Vojak(), Student()
{
	std::cout << "Vojensky student vytvoren";
}

VojenskyStudent::VojenskyStudent(
	int osobniCislo, std::string hodnost, std::string krestniJmeno, 
	std::string prijmeni, std::string rodneCislo)
	: Vojak(osobniCislo, hodnost), Student(krestniJmeno, prijmeni, rodneCislo)
{
	std::cout << "Vojensky student vytvoren";
}

VojenskyStudent::~VojenskyStudent() {
	std::cout << "Vojensky student smazan";
}