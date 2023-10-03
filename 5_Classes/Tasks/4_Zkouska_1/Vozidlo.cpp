#include "Vozidlo.h"
#include <fstream>

Vozidlo::Vozidlo(std::string vyrobce, std::string model, float spotreba_l_100)
{
	this->vyrobce = vyrobce;
	this->model = model;
	this->spotreba_l_100 = spotreba_l_100;
}

bool Vozidlo::operator<(Vozidlo& o)
{
	if (spotreba_l_100 < o.spotreba_l_100)
		return true;
	else
		return false;
}

void Vozidlo::spocitej_spotrebu(int km, float palivo)
{
	spotreba_l_100 = 100.0 / km * palivo;
}

float Vozidlo::get_spotrebu()
{
	return this->spotreba_l_100;
}

std::ostream& operator<<(std::ostream& out, const Vozidlo& v)
{
	out << v.vyrobce << "\n" << v.model << "\n" << v.spotreba_l_100 << "\n";
	return out;
}
