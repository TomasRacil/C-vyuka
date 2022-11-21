#include "Vojak.h"
#include <iostream>

Vojak::Vojak() {
	this->osobniCislo = 0;
	setHodnost();
	std::cout << "Vojak s osobnim cislem " << osobniCislo << " byl vytvoren" << std::endl;
}

Vojak::Vojak(int osobniCislo, std::string hodnost) {
	setOsobniCislo(osobniCislo);
	setHodnost(hodnost);
	std::cout << "Vojak s osobnim cislem " << osobniCislo << " byl vytvoren" << std::endl;
}
void Vojak::setOsobniCislo()
{
	int osobniCislo;
	std::cout << "Zadejte osobni cislo: ";
	std::cin >> osobniCislo;
	setOsobniCislo(osobniCislo);
}
void Vojak::setOsobniCislo(int osobniCislo) {
	while (osobniCislo<1000000 || osobniCislo>=10000000) {
		std::cout << "Spatne zadane osobni cislo: ";
		std::cin >> osobniCislo;
	}
	this->osobniCislo = osobniCislo;
}

int Vojak::getOsobniCislo() {
	return osobniCislo;
}

void Vojak::setHodnost()
{
	std::string hodnost;
	std::cout << "Zadejte hodnost osoby: ";
	std::cin >> hodnost;
	setHodnost(hodnost);
}

void Vojak::setHodnost(std::string hodnost) {
	while (!(std::find(hodnosti.begin(), hodnosti.end(), hodnost) != hodnosti.end())) {
		std::cout << "Spatne zadana hodost: ";
		std::cin >> hodnost;
	}
	this->hodnost = hodnost;
}

std::string Vojak::getHodnost() {
	return hodnost;
}

Vojak::~Vojak(){
	std::cout << "Vojak s osobnim cislem "<<osobniCislo<< " byl smazan" << std::endl;
}
