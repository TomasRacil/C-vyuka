#pragma once
#include <string>
class Contact
{
	std::string surname;
	std::string forename;
	int telephone;

	bool operator <(const Contact& obj);
	bool operator >(const Contact& obj);
	bool operator ==(const Contact& obj);
};

