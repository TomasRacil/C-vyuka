#pragma once
#include <string>

class Vozidlo
{
private:
	std::string vyrobce;
	std::string model;
	float spotreba_l_100;
public:
	Vozidlo(std::string vyrobce, std::string model, float spotreba_l_100);
	bool operator<(Vozidlo& o);
	void spocitej_spotrebu(int km, float palivo);
	float get_spotrebu();
	friend std::ostream& operator<<(std::ostream& out, const Vozidlo& v);
};

