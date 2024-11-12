#include <iostream>
#include "PrislusnikUO.h"
#include "StalyStav.h"
#include "Vojak.h"
#include "VojenskyStalyStav.h"
#include "Student.h"


int Student::studentInstances = 0;
std::vector<std::string> StalyStav::allowedPrislunost = { "FVT","FVZ","FVL" };
std::vector<std::string> Vojak::hodnosti = { "vojin", "svobodnik" };

int main() {
	VojenskyStalyStav vojstav;

	StalyStav stav = vojstav;


}