#pragma once
#include <string>
#include <vector>
#include "PrislusnikUO.h"

class StalyStav:public PrislusnikUO
{
public:
	StalyStav();
	StalyStav(std::string krestniJmeno, std::string prijmeni, std::string rodneCislo, std::string prislusnost);
	void setPrislusnost();
	void setPrislusnost(std::string prislusnost);
	std::string getPrislusnost();
	~StalyStav();

	static std::vector<std::string> allowedPrislunost;

private:
	std::string prislusnost;
};

