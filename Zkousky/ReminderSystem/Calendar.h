#pragma once
#include <list>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Event.h"
class Calendar
{
private:
	std::string name;
	std::string path;
	std::list<Event> events;

public:
	Calendar(std::string name);
	Calendar(std::string name, std::string path);
	
	void addEvent(Event event);
	Calendar findEvent(std::string name);
	Calendar findEventsAfter(Time time);
	Calendar findEventsBefore(Time time);
	~Calendar();

	friend std::ostream& operator << (std::ostream& out, const Calendar& obj);
};

