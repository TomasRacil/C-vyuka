#pragma once
#include "PrislusnikUO.h"

class Student : public PrislusnikUO
{
public:
	Student();
	Student(std::string krestniJmeno, std::string prijmeni, std::string rodneCislo);
	
	int getCisloStudenta();
	~Student();

	static int studentInstances;
private:
	void setCiloStudenta();
	int cisloStudenta;
};

