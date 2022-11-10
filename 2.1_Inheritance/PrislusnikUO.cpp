#include "PrislusnikUO.h"

PrislusnikUO::PrislusnikUO()
{
	/*setKrestniJmeno();
	setPrijmeni();*/
	this->krestniJmeno = "";
	this->prijmeni = "";
	this->rodneCislo = "";
}

PrislusnikUO::PrislusnikUO(std::string krestniJmeno, std::string prijmeni, std::string rodneCislo)
{
	setKrestniJmeno(krestniJmeno);
	setPrijmeni(prijmeni);
	setRodneCislo(rodneCislo);
	std::cout << getCeleJmeno() << " s rodnym cislem " << rodneCislo << " se stal prislusnikem UO" << std::endl;
}

void PrislusnikUO::setKrestniJmeno(std::string krestniJmeno)
{
	while (!(isupper(krestniJmeno[0]) && krestniJmeno.find(" ") == std::string::npos)) {
		std::cout << "Spatne zadane krestni jmeno, zadej znovu: ";
		std::cin >> krestniJmeno;
	}
	this->krestniJmeno = krestniJmeno;
}

std::string PrislusnikUO::getKrestniJmeno()
{
	return krestniJmeno;
}

void PrislusnikUO::setPrijmeni(std::string prijmeni)
{
	while (!(isupper(prijmeni[0]) && prijmeni.find(" ") == std::string::npos)) {
		std::cout << "Spatne zadane prijmeni, zadej znovu: ";
		std::cin >> prijmeni;
	}
	this->prijmeni = prijmeni;
}

std::string PrislusnikUO::getPrijmeni()
{
	return prijmeni;
}

void PrislusnikUO::setRodneCislo(std::string rodneCislo)
{
	while (rodneCislo.size() > 11) {
		std::cout << "Rodne cislo neni vhodne zadane, zadejte nove" << std::endl;
		std::cin >> rodneCislo;
	}
	this->rodneCislo = rodneCislo;
}

std::string PrislusnikUO::getRodneCislo()
{
	return rodneCislo;
}

std::string PrislusnikUO::getCeleJmeno()
{
	return krestniJmeno + " " + prijmeni;
}

PrislusnikUO::~PrislusnikUO()
{
	std::cout << getCeleJmeno() << " s rodnym cislem " << rodneCislo << " prestal byt prislusnik UO" << std::endl;
}
