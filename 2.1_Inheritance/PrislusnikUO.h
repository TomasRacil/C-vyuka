#pragma once
#include <string>

class PrislusnikUO
{
public:
	PrislusnikUO();
	PrislusnikUO(std::string krestniJmeno, std::string prijmeni, std::string rodneCislo);
	void setKrestniJmeno(std::string krestniJmeno);
	std::string getKrestniJmeno();
	void setPrijmeni(std::string prijmeni);
	std::string getPrijmeni();
	void setRodneCislo(std::string rodneCislo);
	std::string getRodneCislo();
	std::string getCeleJmeno();
	~PrislusnikUO();
private:
	std::string krestniJmeno;
	std::string prijmeni;
	std::string rodneCislo;
};

