#pragma once
#include <string>
class Contact
{
private:
	std::string surname;
	std::string forename;
	int telephone;
public:
	std::string repr();
	bool operator <(const Contact& obj);
	bool operator >(const Contact& obj);
	bool operator ==(const Contact& obj);
};

