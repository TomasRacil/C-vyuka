#pragma once
#include "Point.cpp"

class Waypoint
{
public:
	Waypoint();
	Waypoint(Point coord);
	void rotate(char direction, int degrees);
	void move(char direction, int value);
	Point getWaypoint();
private:
	Point coord;
};

