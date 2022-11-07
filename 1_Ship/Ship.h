#pragma once
#include <string>
#include "Waypoint.h"

class Ship
{
public:
	Ship(int direction, int positionE, int positionN);
	Ship(int positionE, int positionN, int waypointPosE, int waypointPosN);
	void move(int value);
	void move(char command, int value);
	void turn(char direction, int value);
	void info();
	void navigate(std::string navigationFile, bool version2);

private:
	int direction;
	int positionE;
	int positionN;
	Waypoint waypoint;

	char degToDirection(int deg);
};

