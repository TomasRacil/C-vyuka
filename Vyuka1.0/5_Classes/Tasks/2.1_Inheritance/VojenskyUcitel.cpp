#include "VojenskyUcitel.h"

VojenskyUcitel::VojenskyUcitel(): Vojak(), Ucitel()
{
}

VojenskyUcitel::VojenskyUcitel(
	int osobniCislo, std::string hodnost, std::string krestniJmeno, 
	std::string prijmeni, std::string rodneCislo, std::string prislusnost)
	: Vojak(osobniCislo, hodnost), Ucitel(krestniJmeno, prijmeni, rodneCislo, prislusnost)
{
	std::cout << getCeleJmeno() << " je vojenskym ucitelem" << std::endl;
}

VojenskyUcitel::~VojenskyUcitel()
{
	std::cout << getCeleJmeno() << " uz neni vojenskym ucitelem" << std::endl;
}
