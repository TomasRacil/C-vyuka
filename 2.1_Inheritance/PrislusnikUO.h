#pragma once
#include <string>
#include <iostream>
#include <ctime>
#include <regex>

class PrislusnikUO
{
public:
	PrislusnikUO();
	PrislusnikUO(std::string krestniJmeno, std::string prijmeni, std::string rodneCislo);
	void setKrestniJmeno();
	void setKrestniJmeno(std::string krestniJmeno);
	std::string getKrestniJmeno();
	void setPrijmeni();
	void setPrijmeni(std::string prijmeni);
	std::string getPrijmeni();
	void setRodneCislo();
	void setRodneCislo(std::string rodneCislo);
	std::tm getDatumNarozeni();
	std::string getPohlavi();
	std::string getRodneCislo();
	std::string getCeleJmeno();
	~PrislusnikUO();
private:
	void parseRodneCislo();

	std::string krestniJmeno;
	std::string prijmeni;
	std::string rodneCislo;
	std::tm datumNarozeni;
	std::string pohlavi;
};

