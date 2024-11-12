#pragma once
#include <string>
#include <iostream>

class Contact
{
public:
	std::string surname;
	std::string forename;
	std::string telephone;

	Contact();
	Contact(std::string surname, std::string forename, std::string telephone);
	std::string repr();
	bool operator <(const Contact& obj);
	bool operator >(const Contact& obj);
	bool operator ==(const Contact& obj);

	friend std::ostream& operator << (std::ostream& out, const Contact& c);
	friend std::istream& operator >> (std::istream& in, Contact& c);
	//friend std::sstream& operator >> (std::sstream& in, Contact& c);
	friend class ContactBook;
};

