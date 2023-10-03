// 1_Ship.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
#include <string>
#include "Ship.h"
#include "Waypoint.h"
#include "Point.cpp"

using namespace std;


std::ostream& operator<<(std::ostream& out, const Point& _point)
{
	out << _point.positionEast << "E, " << _point.positionNorth << "N";
	return out;
}

int main()
{
	Ship test1(90, 0, 0);
	test1.info();
	test1.navigate("navigation_data.txt",false);
	test1.info();
	Ship test2(0, 0, 10, 1);
	test2.info();
	test2.navigate("navigation_data.txt", true);
	test2.info();

}

