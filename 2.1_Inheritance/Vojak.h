#pragma once
#include <string>
#include <vector>
class Vojak
{
protected:
	Vojak();
	Vojak(int osobniCislo, std::string hodnost);
	void setOsobniCislo();
	void setOsobniCislo(int osobniCislo);
	int getOsobniCislo();
	void setHodnost();
	void setHodnost(std::string hodnost);
	std::string getHodnost();
	~Vojak();

	static std::vector<std::string> hodnosti;
	
private:
	int osobniCislo;
	std::string hodnost;
};

