#pragma once
#include <string>
#include "Vojak.h"
#include "StalyStav.h"

class VojenskyStalyStav:public Vojak, public StalyStav
{
public:
	VojenskyStalyStav();
	VojenskyStalyStav(int osobniCislo, std::string hodnost, std::string krestniJmeno, std::string prijmeni, std::string rodneCislo, std::string prislusnost);
	~VojenskyStalyStav();
private:

};

