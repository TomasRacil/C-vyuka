#pragma once
#include <list>
#include "Contact.h"
#include <iostream>
#include <algorithm>
#include <sstream>

class ContactBook
{
private:
	std::list<Contact> book;
public:
	ContactBook();
	void print();
	void append(Contact contact);
	void load(std::string file);
	ContactBook find_by_surname(std::string surname);
	ContactBook find_by_forename(std::string forename);
	ContactBook find_by_telephone(std::string telephone);
	/*template <std::string Contact::* Attr>
	ContactBook find(std::string searched);*/
	void remove(Contact contact);
	bool exist(Contact contact);
	void save(std::string file);
};
