#include "Contact.h"

Contact::Contact()
{
    //std::cin >> *this;
}

Contact::Contact(std::string surname, std::string forename, std::string telephone)
{
    this->surname = surname;
    this->forename = forename;
    this->telephone = telephone;
}

std::string Contact::repr()
{
    return surname + " " + forename + ", tel: " + telephone;
}

bool Contact::operator<(const Contact& obj)
{
    if (surname < obj.surname)
        return true;
    else if (surname == obj.surname) {
        if (forename < obj.forename)
            return true;
        else
            return false;
    }
    else
        return false;
}
bool Contact::operator>(const Contact& obj)
{
    if (surname > obj.surname)
        return true;
    else if (forename > obj.forename)
        return true;
    else
        return false;
}

bool Contact::operator==(const Contact& obj)
{
    if (surname == obj.surname && forename == obj.forename && telephone == telephone)
        return true;
    else
        return false;
}

std::ostream& operator<<(std::ostream& out, const Contact& c)
{
    out << c.surname << " " << c.forename << ", tel.: "<< c.telephone;
    return out;
}

std::istream& operator>>(std::istream& in, Contact& c)
{
    std::cout << "Prijmeni: ";
    in >> c.surname;
    std::cout << "Kresti jmeno: ";
    in >> c.forename;
    std::cout << "Telefonni cislo: ";
    in >> c.telephone;
    return in;
}
