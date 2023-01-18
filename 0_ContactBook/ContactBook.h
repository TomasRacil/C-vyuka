#pragma once
#include <list>
#include "Contact.h"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <regex>

class ContactBook
{
public:
	std::list<Contact> book;

	ContactBook();
	void print();
	void append(Contact contact);
	void load(std::string file);
	ContactBook find(std::string searched);
	ContactBook find_by_surname(std::string surname);
	ContactBook find_by_forename(std::string forename);
	ContactBook find_by_telephone(std::string telephone);
	/*template <std::string Contact::* Attr>
	ContactBook find(std::string searched);*/
	void remove(Contact contact);
	bool exist(Contact contact);
	void save(std::string file);
};
