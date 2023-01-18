#pragma once
#include <string>
#include <list>
#include <fstream>
#include <sstream>
#include "Vozidlo.h"

class Cesta
{
private:
	std::string start;
	std::string cil;
	std::string soubor;
	int vzdalenost;
	float cena_litr_paliva;
	std::list<Vozidlo> flotila;
public:
	Cesta(std::string soubor, float cena_paliva);
	void pridej_vozidlo(Vozidlo nove_vozidlo);
	Vozidlo& get_vozidlo(int index);
	float spocitej_celkovou_spotrebu();
	float spocitej_celkovou_cenu();
	~Cesta();
	friend std::ostream& operator<<(std::ostream& out, const Cesta& c);
};