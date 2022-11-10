#pragma once
#include "Ucitel.h"
#include "Vojak.h"

class VojenskyUcitel: public Vojak, public Ucitel
{
public:
	VojenskyUcitel();
	VojenskyUcitel(int osobniCislo, std::string hodnost, std::string krestniJmeno,
		std::string prijmeni, std::string rodneCislo, std::string prislusnost);
	~VojenskyUcitel();
private:

};

