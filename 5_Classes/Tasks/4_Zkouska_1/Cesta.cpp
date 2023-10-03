#include "Cesta.h"


Cesta::Cesta(std::string soubor, float cena_paliva)
{
	this->cena_litr_paliva = cena_paliva;
	this->soubor = soubor;
	std::ifstream file;
	file.open(this->soubor);
	std::string radek;
	std::getline(file, start);
	std::getline(file, cil);
	std::getline(file, radek);
	vzdalenost = std::stoi(radek);
	std::getline(file, radek);
	while (getline(file, radek)) {
		std::string vyrobce=radek;
		std::string model;
		getline(file, model);
		getline(file, radek);
		float spotreba=stof(radek);
		this->flotila.push_back(Vozidlo(vyrobce, model, spotreba));
	}
	flotila.sort();
}

void Cesta::pridej_vozidlo(Vozidlo nove_vozidlo)
{
	flotila.push_back(nove_vozidlo);
	flotila.sort();
}

Vozidlo& Cesta::get_vozidlo(int index)
{
	auto l_front = flotila.begin();
	std::advance(l_front, index);
	return *l_front;
}

float Cesta::spocitej_celkovou_spotrebu()
{
	float celkova_spotreba = 0.0;
	for (Vozidlo vozidlo : flotila) {
		celkova_spotreba += vozidlo.get_spotrebu();
	}
	return celkova_spotreba*vzdalenost/100.0;
}

float Cesta::spocitej_celkovou_cenu()
{
	return spocitej_celkovou_spotrebu()*cena_litr_paliva;
}

Cesta::~Cesta()
{
	std::ofstream file;
	file.open(this->soubor);
	std::string output;
	output += this->start + "\n" + this->cil + "\n" + std::to_string(this->vzdalenost) + "\n\n";
	for (Vozidlo vozidlo : flotila) {
		std::stringstream ss;
		ss << vozidlo;
		output+=ss.str();
	}
	file.write(output.c_str(),output.size());
}

std::ostream& operator<<(std::ostream& out, const Cesta& c)
{
	out << c.start << "\n" << c.cil << "\n" << c.vzdalenost << "\n\n";
	for (Vozidlo vozidlo : c.flotila) {
		out<<vozidlo;
	}
	return out;
}
