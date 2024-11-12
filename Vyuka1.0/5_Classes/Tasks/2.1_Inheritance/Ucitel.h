#pragma once
#include <vector>
#include <iterator>
#include <sstream>
#include "StalyStav.h"

class Ucitel:public StalyStav
{
public:
	Ucitel();
	Ucitel(std::string krestniJmeno, std::string prijmeni, std::string rodneCislo, std::string prislusnost);
	void addPredmet();
	void addPredmet(std::string);
	void removePredmet(std::string predmet);
	std::string getPredmety();
	~Ucitel();
private:
	std::vector<std::string> vyucovanePredmety;
};

