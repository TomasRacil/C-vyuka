#include "person.h"

Person::Person(std::string jmeno, int vek) : jmeno(jmeno), vek(vek) {}

std::string Person::getJmeno()
{
    return jmeno;
}

int Person::getVek()
{
    return vek;
}