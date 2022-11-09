#include "PrislusnikUO.h"
#include <iostream>

PrislusnikUO::PrislusnikUO()
{
	this->krestniJmeno = "";
	this->prijmeni = "";
	this->rodneCislo = "";
}

PrislusnikUO::PrislusnikUO(std::string krestniJmeno, std::string prijmeni, std::string rodneCislo)
{
	setKrestniJmeno(krestniJmeno);
	setPrijmeni(prijmeni);
	setRodneCislo(rodneCislo);
	std::cout<< "Prislusnik UO s rodnym cislem " << rodneCislo << " byl vytvoren" << std::endl;
}

void PrislusnikUO::setKrestniJmeno(std::string krestniJmeno)
{
	this->krestniJmeno = krestniJmeno;
}

std::string PrislusnikUO::getKrestniJmeno()
{
	return krestniJmeno;
}

void PrislusnikUO::setPrijmeni(std::string prijmeni)
{
	this->prijmeni = prijmeni;
}

std::string PrislusnikUO::getPrijmeni()
{
	return prijmeni;
}

void PrislusnikUO::setRodneCislo(std::string rodneCislo)
{
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
	std::cout << "Prislusnik UO s rodnym cislem " << rodneCislo << " byl smazan" << std::endl;
}
