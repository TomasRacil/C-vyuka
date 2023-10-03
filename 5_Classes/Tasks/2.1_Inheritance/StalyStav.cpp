#include "StalyStav.h"
#include <iostream>

StalyStav::StalyStav():PrislusnikUO()
{
	this->prislusnost = "";
	setPrislusnost();
}
StalyStav::StalyStav(std::string krestniJmeno, std::string prijmeni, std::string rodneCislo, std::string prislusnost) :PrislusnikUO(krestniJmeno, prijmeni, rodneCislo)
{
	setPrislusnost(prislusnost);
	std::cout << "Prislusnik se stal clenem " << getPrislusnost() << std::endl;
}

void StalyStav::setPrislusnost()
{
	std::string prislusnost;
	std::cout << "Zadejte prislusnost osoby: ";
	std::cin >> prislusnost;
	setPrislusnost(prislusnost);
}

void StalyStav::setPrislusnost(std::string prislusnost) {
	while (!(std::find(allowedPrislunost.begin(), allowedPrislunost.end(), prislusnost) != allowedPrislunost.end())) {
		std::cout << "Spatne zadana prislunost: ";
		std::cin >> prislusnost;
	}
	this->prislusnost = prislusnost;
	
}

std::string StalyStav::getPrislusnost() {
	return prislusnost;
}

StalyStav::~StalyStav()
{
	std::cout << "Prislusnik prestal byt clenem " << prislusnost << std::endl;
}