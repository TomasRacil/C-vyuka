#include "PrislusnikUO.h"

PrislusnikUO::PrislusnikUO()
{
	setKrestniJmeno();
	setPrijmeni();
	setRodneCislo();
	std::cout << getCeleJmeno() << " s rodnym cislem " << getRodneCislo() << " se stal prislusnikem UO" << std::endl;
}

PrislusnikUO::PrislusnikUO(std::string krestniJmeno, std::string prijmeni, std::string rodneCislo)
{
	setKrestniJmeno(krestniJmeno);
	setPrijmeni(prijmeni);
	setRodneCislo(rodneCislo);
	std::cout << getCeleJmeno() << " s rodnym cislem " << getRodneCislo() << " se stal prislusnikem UO" << std::endl;
}

void PrislusnikUO::setKrestniJmeno()
{
	std::string krestniJmeno;
	std::cout << "Zadejte krestni jmeno prislusnika: ";
	std::cin >> krestniJmeno;
	setKrestniJmeno(krestniJmeno);
}

void PrislusnikUO::setKrestniJmeno(std::string krestniJmeno)
{
	while (!(isupper(krestniJmeno[0]) && krestniJmeno.find(" ") == std::string::npos)) {
		std::cout << "Spatne zadane krestni jmeno, zadej znovu: ";
		std::cin >> krestniJmeno;
	}
	this->krestniJmeno = krestniJmeno;
}

std::string PrislusnikUO::getKrestniJmeno()
{
	return krestniJmeno;
}

void PrislusnikUO::setPrijmeni()
{
	std::string prijmeni;
	std::cout << "Zadejte prijmeni prislusnika: ";
	std::cin >> prijmeni;
	setPrijmeni(prijmeni);
}

void PrislusnikUO::setPrijmeni(std::string prijmeni)
{
	while (!(isupper(prijmeni[0]) && prijmeni.find(" ") == std::string::npos)) {
		std::cout << "Spatne zadane prijmeni, zadej znovu: ";
		std::cin >> prijmeni;
	}
	this->prijmeni = prijmeni;
}

std::string PrislusnikUO::getPrijmeni()
{
	return prijmeni;
}

void PrislusnikUO::setRodneCislo()
{
	std::string rodneCislo;
	std::cout << "Zadejte rodne cislo prislusnika: ";
	std::cin >> rodneCislo;
	setRodneCislo(rodneCislo);
}

bool isDigit(std::string str) {
	for (int i = 0; i < str.size(); i++) {
		if (!isdigit(str[i])) return false;
	}
	return true;
}

int cifernySoucet(int cislo)
{
	int souc = 0;
	while (cislo != 0) {
		souc += cislo % 10;
		cislo = cislo / 10;
	}
	return souc;
}

bool isRodneCislo(std::string str) {
	std::regex rodne_cislo_regex("^\\d{2}[0156]\\d{1}[0123]\\d{1}\\/\\d{4}$");

	if (std::regex_match(str, rodne_cislo_regex)) {
		if (stoll(str.substr(0, 6) + str.substr(7, 4)) % 11 == 0) {
			return true;
		}
	}

	return false;

	//return (std::regex_match(str, rodne_cislo_regex)) ? true : false;
}

void PrislusnikUO::setRodneCislo(std::string rodneCislo)
{
	std::string predLomitkem = rodneCislo.substr(0, 6);
	std::string zaLomitkem = rodneCislo.substr(0, 6);

	while (
		/*!(
			rodneCislo.size() == 11 
			&& rodneCislo[6]=='/' 
			&& isDigit(rodneCislo.substr(0, 6))
			&& isDigit(rodneCislo.substr(7, 4))
			)*/
		!isRodneCislo(rodneCislo)
		) {
		std::cout << "Rodne cislo neni vhodne zadane, zadejte nove" << std::endl;
		std::cin >> rodneCislo;
	}
	this->rodneCislo = rodneCislo;
	parseRodneCislo();
}

std::tm PrislusnikUO::getDatumNarozeni()
{
	return datumNarozeni;
}

std::string PrislusnikUO::getPohlavi()
{
	return pohlavi;
}

std::string PrislusnikUO::getRodneCislo()
{
	return rodneCislo;
}

std::string PrislusnikUO::getCeleJmeno()
{
	return krestniJmeno + " " + prijmeni;
}

PrislusnikUO::~PrislusnikUO()
{
	std::cout << getCeleJmeno() << " s rodnym cislem " << rodneCislo << " prestal byt prislusnik UO" << std::endl;
}

void PrislusnikUO::parseRodneCislo()
{
	pohlavi = ((rodneCislo[2]-'0') >= 5) ? "zena" : "muz";
	datumNarozeni.tm_year = stoi(rodneCislo.substr(0, 2)) + ((stoi(rodneCislo.substr(0, 2))<54)? 2000:1900);
	datumNarozeni.tm_mon = stoi(rodneCislo.substr(2, 2)) - ((pohlavi=="zena") ? 50:0);
	datumNarozeni.tm_mday = stoi(rodneCislo.substr(4, 2));
}
