#include "StalyStav.h"
#include <iostream>

StalyStav::StalyStav():PrislusnikUO()
{
	this->prislusnost = "";
}
StalyStav::StalyStav(std::string krestniJmeno, std::string prijmeni, std::string rodneCislo, std::string prislusnost) :PrislusnikUO(krestniJmeno, prijmeni, rodneCislo)
{
	setPrislusnost(prislusnost);
	std::cout << "Prislusnik se stal clenem " << prislusnost << std::endl;
}

void StalyStav::setPrislusnost(std::string prislusnost) {
	this->prislusnost = prislusnost;
}

std::string StalyStav::getPrislusnost() {
	return prislusnost;
}

StalyStav::~StalyStav()
{
	std::cout << "Prislusnik prestal byt clenem " << prislusnost << std::endl;
}