#include "Ucitel.h"

Ucitel::Ucitel() :StalyStav()
{
}

Ucitel::Ucitel(
	std::string krestniJmeno, std::string prijmeni, 
	std::string rodneCislo, std::string prislusnost):
	StalyStav(krestniJmeno, prijmeni, rodneCislo, prislusnost)
{
	addPredmet();
	std::cout << getCeleJmeno() << " se stal ucitelem a byly mu prirazeny tyto predmety "<< getPredmety() << std::endl;
}

void Ucitel::addPredmet()
{
	std::string predmet;
	std::cout << "Zadejte predmet, ktery chcete priradit ucitelovi: ";
	std::cin >> predmet;
	addPredmet(predmet);
}

void Ucitel::addPredmet(std::string predmet)
{
	vyucovanePredmety.push_back(predmet);
}

void Ucitel::removePredmet(std::string predmet)
{
	vyucovanePredmety.erase(std::remove(vyucovanePredmety.begin(), vyucovanePredmety.end(), predmet), vyucovanePredmety.end());
}

std::string Ucitel::getPredmety()
{
	const char* const delim = ", ";

	std::ostringstream imploded;
	std::copy(vyucovanePredmety.begin(), vyucovanePredmety.end(),
		std::ostream_iterator<std::string>(imploded, delim));
	return imploded.str();
}

Ucitel::~Ucitel()
{
	vyucovanePredmety.clear();
	std::cout << getCeleJmeno() << "Prestal byt ucitelem a vsechny predmety, ktere ucitel ucil byly uvolneny" << std::endl;
}



