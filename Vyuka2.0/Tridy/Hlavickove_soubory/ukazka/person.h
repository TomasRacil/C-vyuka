#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
public:
    Person(std::string jmeno, int vek);
    std::string getJmeno();
    int getVek();

private:
    std::string jmeno;
    int vek;
};

#endif