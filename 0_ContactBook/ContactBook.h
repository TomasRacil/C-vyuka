#pragma once
#include <list>
#include "Contact.h"
class ContactBook
{
private:
	std::list<Contact> book;
public:
	ContactBook();
	void print();
	ContactBook find_by_surname(std::string surname);
	ContactBook find_by_forename(std::string forename);
	ContactBook find_by_telephone(int telephone);
	void remove(Contact contact);
	bool exist(Contact);
};

