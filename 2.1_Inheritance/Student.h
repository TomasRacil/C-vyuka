#pragma once
#include "PrislusnikUO.h"

class Student : public PrislusnikUO
{
public:
	Student();
	Student(std::string krestniJmeno, std::string prijmeni, std::string rodneCislo);
	void setCiloStudenta(int cisloStudenta);
	int getCisloStudenta();
	~Student();
private:
	int cisloStudenta;
};

