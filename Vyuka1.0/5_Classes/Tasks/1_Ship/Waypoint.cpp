#include "Waypoint.h"

Waypoint::Waypoint()
{
	this->coord = { 0,0 };
}

Waypoint::Waypoint(Point coord)
{
	this->coord = coord;
}

void Waypoint::rotate(char direction, int degrees)
{
	int temp = coord.positionEast;;
	if (degrees == 180) {
		coord.positionEast = -coord.positionEast;
		coord.positionNorth = -coord.positionNorth;
	}
	else if ((degrees == 90 && direction == 'L') || (degrees == 270 && direction == 'R')) {
		coord.positionEast = -coord.positionNorth;
		coord.positionNorth = temp;
	}
	else if ((degrees == 270 && direction == 'L') || (degrees == 90 && direction == 'R')) {
		coord.positionEast = coord.positionNorth;
		coord.positionNorth = -temp;
	}
}

void Waypoint::move(char direction, int value)
{
	switch (direction)
	{
	case 'N':
		coord.positionNorth += value;
		break;
	case 'E':
		coord.positionEast += value;
		break;
	case 'S':
		coord.positionNorth -= value;
		break;
	case 'W':
		coord.positionEast -= value;
		break;
	default:
		break;
	}
}

Point Waypoint::getWaypoint()
{
	return coord;
}