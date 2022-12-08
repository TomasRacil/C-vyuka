#include "ContactBook.h"
#include <fstream>
#include <vector>

ContactBook::ContactBook()
{
	book = {};
}

void ContactBook::print()
{
	for (Contact contact : book) {
		std::cout << contact.repr() << std::endl;
	}
}

void ContactBook::append(Contact contact)
{
	if (exist(contact)) {
		std::cout << "Contact already exists" << std::endl;
	}
	else {
		book.push_back(contact);
		book.sort();
	}
	
}

void ContactBook::load(std::string file)
{
	std::ifstream myfile;
	myfile.open(file+".csv");
	std::string line;
	while (getline(myfile, line))
	{
		std::stringstream ss(line);
		std::string substring{};
		std::vector<std::string> substrings{};

		while (std::getline(ss, substring, ';')) {
			substrings.push_back(substring);
		}
		Contact contact;
		contact.surname = substrings[0];
		contact.forename = substrings[1];
		contact.telephone = substrings[2];
		append(contact);
	}
	myfile.close();
}

ContactBook ContactBook::find_by_surname(std::string searched)
{
	ContactBook matches;
	std::copy_if(book.begin(), book.end(), std::back_inserter(matches.book), [&](Contact contact) {
		int idx = 0;
		for (auto ch : searched) {
			if (tolower(ch) != tolower(contact.surname[idx]))
				return false;
			idx++;
		}
		return true;
		});
	return  matches;
}

ContactBook ContactBook::find_by_forename(std::string searched)
{
	ContactBook matches;
	std::copy_if(book.begin(), book.end(), std::back_inserter(matches.book), [&](Contact contact) {
		int idx = 0;
	for (auto ch : searched) {
		if (tolower(ch) != tolower(contact.forename[idx]))
			return false;
		idx++;
	}
	return true;
		});
	return  matches;
}

ContactBook ContactBook::find_by_telephone(std::string searched)
{
	ContactBook matches;
	std::copy_if(book.begin(), book.end(), std::back_inserter(matches.book), [&](Contact contact) {
		int idx = 0;
	for (auto ch : searched) {
		if (tolower(ch) != tolower(contact.telephone[idx]))
			return false;
		idx++;
	}
	return true;
		});
	return  matches;
}
void ContactBook::remove(Contact contact)
{
	auto it = std::find(book.begin(), book.end(), contact);
	book.erase(it);
}

bool ContactBook::exist(Contact contact)
{
	auto it = std::find(book.begin(), book.end(), contact);
	if (it == book.end())
		return false;
	else
		return true;
}

void ContactBook::save(std::string file)
{
	std::ofstream myfile;
	myfile.open(file+".csv");
	for (Contact cont : book) {
		myfile << cont.surname << ";" << cont.forename << ";" << cont.telephone << "\n";
	}
	myfile.close();
}
