#include "Book.h"

Book::Book()
{
    id=0;
    name="";
    author="";
    available=false;
}

Book::Book(std::string book)
{
    std::stringstream ss(book);
	std::string information;
    std::vector <std::string> informations;
	while (std::getline(ss, information, ';')) {
		informations.push_back(information);
	}
    id=stol(informations[0]);
    name=informations[1];
    author=informations[2];
    if (informations[3]=="Available") available=true;
    else available=false;
}

long Book::getId()
{
    return id;
}

void Book::setID(long id)
{
    this->id = id;
}

bool Book::getAvailable()
{
    return available;
}

void Book::setAvailable(bool available)
{
    this->available = available;
}

std::string Book::getName()
{
    return name;
}

bool Book::operator<(const Book &obj)
{
    if(author.compare(obj.author)<0) return true;
    return false;
}

bool Book::operator==(const Book &obj)
{
    if (id==obj.id){
        return true;
    }
    return false;
}

Book::~Book()
{
}

std::ostream& operator<<(std::ostream& out, const Book& obj){
    // TODO: insert return statement here
	out << obj.id<< ";" << obj.name<< ";" << obj.author << ";";
	if (obj.available) out << "Available";
    else out << "Unavailable";
	return out;
}
