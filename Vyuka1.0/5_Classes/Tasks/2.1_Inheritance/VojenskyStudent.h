#pragma once
#include "Vojak.h"
#include "Student.h"

class VojenskyStudent:public Vojak, public Student
{
public:
	VojenskyStudent();
	VojenskyStudent(int osobniCislo, std::string hodnost, std::string krestniJmeno, std::string prijmeni, std::string rodneCislo);
	~VojenskyStudent();
private:

};

