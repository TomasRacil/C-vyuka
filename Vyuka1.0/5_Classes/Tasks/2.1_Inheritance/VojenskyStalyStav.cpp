#include <iostream>
#include "VojenskyStalyStav.h"

VojenskyStalyStav::VojenskyStalyStav():Vojak(),StalyStav()
{
}

VojenskyStalyStav::VojenskyStalyStav(
	int osobniCislo, std::string hodnost, std::string krestniJmeno, 
	std::string prijmeni, std::string rodneCislo, std::string prislusnost)
	: Vojak(osobniCislo, hodnost), StalyStav(krestniJmeno, prijmeni, rodneCislo, prislusnost)
{
	std::cout << getCeleJmeno() << " je ted clenem vojenskeho staleho stavu UO" << std::endl;
}

VojenskyStalyStav::~VojenskyStalyStav() {
	std::cout << getCeleJmeno() << " prestal byt clenem vojenskeho staleho stavu UO" << std::endl;
}
