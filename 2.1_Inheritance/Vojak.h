#pragma once
#include <string>
class Vojak
{
protected:
	Vojak();
	Vojak(int osobniCislo, std::string hodnost);
	void setOsobniCislo(int osobniCislo);
	int getOsobniCislo();
	void setHodnost(std::string hodnost);
	std::string getHodnost();
	~Vojak();
	
private:
	int osobniCislo;
	std::string hodnost;
};

