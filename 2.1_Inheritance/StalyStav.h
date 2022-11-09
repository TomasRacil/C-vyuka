#pragma once
#include <string>
#include "PrislusnikUO.h"

class StalyStav:public PrislusnikUO
{
public:
	StalyStav();
	StalyStav(std::string krestniJmeno, std::string prijmeni, std::string rodneCislo, std::string prislusnost);
	void setPrislusnost(std::string prislusnost);
	std::string getPrislusnost();
	~StalyStav();

private:
	std::string prislusnost;
};

