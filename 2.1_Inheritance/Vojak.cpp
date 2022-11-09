#include "Vojak.h"
#include <iostream>

Vojak::Vojak() {
	this->osobniCislo = 0;
	this->hodnost = "";
	std::cout << "Vojak s osobnim cislem " << osobniCislo << " byl vytvoren" << std::endl;
}

Vojak::Vojak(int osobniCislo, std::string hodnost) {
	setOsobniCislo(osobniCislo);
	setHodnost(hodnost);
	std::cout << "Vojak s osobnim cislem " << osobniCislo << " byl vytvoren" << std::endl;
}
void Vojak::setOsobniCislo(int osobniCislo) {
	this->osobniCislo = osobniCislo;
}

int Vojak::getOsobniCislo() {
	return osobniCislo;
}

void Vojak::setHodnost(std::string hodnost) {
	this->hodnost = hodnost;
}

std::string Vojak::getHodnost() {
	return hodnost;
}

Vojak::~Vojak(){
	std::cout << "Vojak s osobnim cislem "<<osobniCislo<< " byl smazan" << std::endl;
}
