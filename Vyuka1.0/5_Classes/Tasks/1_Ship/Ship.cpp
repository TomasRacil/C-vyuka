#include "Ship.h"
#include <iostream>
#include <fstream>

Ship::Ship(int direction, int positionE, int positionN)
{
	this->direction = direction;
	this->positionE = positionE;
	this->positionN = positionN;
}

Ship::Ship(int positionE, int positionN, int waypointPosE, int waypointPosN)
{
	this->positionE = positionE;
	this->positionN = positionN;
	this->direction = NULL;
	this->waypoint = Waypoint({ waypointPosE ,waypointPosN });
}

void Ship::move(int value)
{
	positionE += waypoint.getWaypoint().positionEast * value;
	positionN += waypoint.getWaypoint().positionNorth * value;
}

void Ship::move(char command, int value)
{
	if (command != 'F') {
		switch (command)
		{
		case 'N':
			positionN += value;
			break;
		case 'E':
			positionE += value;
			break;
		case 'S':
			positionN -= value;
			break;
		case 'W':
			positionE -= value;
			break;
		default:
			break;
		}
	}
	else move(degToDirection(this->direction), value);

}

void Ship::turn(char direction, int value)
{
	switch (direction)
	{
	case 'L':
		this->direction = (360 + this->direction - value) % 360;
		break;
	case 'R':
		this->direction = (this->direction + value) % 360;
		break;
	default:
		break;
	}
}

void Ship::info()
{
	std::cout << "Lod je otocena na " << degToDirection(direction) << " na souradnicich " << positionE << " vychodne a " << positionN << " severne " << std::endl;
	std::cout << "Od startu urazila " << abs(positionE) + abs(positionN) << " jednotek (manhattan)" << std::endl;
}

void Ship::navigate(std::string navigationFile, bool version2)
{
	std::ifstream file;
	std::string line;
	char command;
	int value;
	file.open(navigationFile);
	while (getline(file, line)) {
		command = line[0];
		value = stoi(line.substr(1, std::string::npos));
		if (version2) {
			if (command == 'L' || command == 'R') {
				waypoint.rotate(command, value);
			}
			else if (command == 'F') {
				move(value);
			}
			else {
				waypoint.move(command, value);
			}
		}
		else {
			if (command == 'L' || command == 'R') {
				turn(command, value);
			}
			else move(command, value);
		}
	}
	file.close();
}

char Ship::degToDirection(int deg)
{
	switch (deg)
	{
	case 0:
		return 'N';
	case 90:
		return 'E';
	case 180:
		return 'S';
	case 270:
		return 'W';
	default:
		return 0;
	}
}