#include "Event.h"

Time::Time()
{
	this->year = 0;
	this->month = 0;
	this->day = 0;
	this->hour = 0;
	this->minute = 0;
}

Time::Time(std::string time)
{
	std::stringstream time_ss(time);
	std::vector<int> items;
	std::string item;

	while (getline(time_ss, item, ' ')) {
		items.push_back(stoi(item));
	}
	this->year = items[0];
	this->month = items[1];
	this->day = items[2];
	this->hour = items[3];
	this->minute = items[4];
}

bool Time::operator<(const Time& obj)
{
	
	if (year < obj.year) return true;
	else if (year > obj.year) return false;
	else {
		if (month < obj.month) return true;
		else if (month > obj.month) return false;
		else {
			if (day < obj.day) return true;
			else if (day > obj.day) return false;
			else {
				if (hour < obj.hour) return true;
				else if (hour > obj.hour) return false;
				else {
					if (minute < obj.minute) return true;
					else return false;
				}
			}
		}
	}
}

bool Time::operator>(const Time& obj)
{
	/*if (year > obj.year) return false;
	if (month > obj.month) return false;
	if (day > obj.day) return false;
	if (hour > obj.hour) return false;
	if (minute > obj.minute) return false;
	return true;*/
	if (year > obj.year) return true;
	else if (year < obj.year) return false;
	else {
		if (month > obj.month) return true;
		else if (month < obj.month) return false;
		else {
			if (day > obj.day) return true;
			else if (day < obj.day) return false;
			else {
				if (hour > obj.hour) return true;
				else if (hour < obj.hour) return false;
				else {
					if (minute > obj.minute) return true;
					else return false;
				}
			}
		}
	}
}

bool Time::operator==(const Time& obj)
{
	if (year == obj.year && month == obj.month && day == obj.day && hour == obj.hour && minute == obj.minute) return true;
	return false;
}

bool Time::operator!=(const Time& obj)
{
	if (year == obj.year && month == obj.month && day == obj.day && hour == obj.hour && minute == obj.minute) return false;
	return true;
}

std::ostream& operator<<(std::ostream& out, const Time& obj)
{
	out << obj.year << "-" << obj.month << "-" << obj.day << " " << std::setw(2) <<std::setfill('0') << obj.hour << ":" << std::setw(2) << std::setfill('0')<< obj.minute;
	return out;
}

std::ostream& operator<<(std::ostream& out, const Event& obj)
{
	out << "Name: " << obj.name << "\n";
	out << "Start: " << obj.start_time << "\n";
	out << "End: " << obj.end_time << "\n";
	out << "Place: " << obj.place << "\n";
	out << "Decription: " << obj.description;
	return out;
}

Event::Event(std::string event)
{
	std::stringstream event_ss(event);
	std::vector<std::string> lines;
	std::string line;

	while (getline(event_ss, line,'\n')) {
		lines.push_back(line);
	}
	this->name = lines[0];
	this->start_time = Time(lines[1]);
	this->end_time = Time(lines[2]);
	this->place = lines[3];
	this->description = lines[4];
}

Event::Event(std::string name, std::string start_time, std::string end_time, std::string place, std::string description)
{
	this->name=name;
	this->start_time = Time(start_time);
	this->end_time = Time(end_time);
	this->place = place;
	this->description = description;
}

std::string Event::getName()
{
	return name;
}

Time* Event::getStartTime()
{
	return &start_time;
}

bool Event::operator<(const Event& obj)
{
	if (start_time < obj.start_time) return true;
	else if (start_time == obj.start_time && end_time < obj.end_time) return true;
	return false;
}

bool Event::operator>(const Event& obj)
{
	if (start_time > obj.start_time) return true;
	else if (start_time == obj.start_time && end_time > obj.end_time) return true;
	return false;
}

bool Event::operator==(const Event& obj)
{
	if (start_time == obj.start_time&& name == obj.name&& obj.place==place) return true;
	return false;
}
bool Event::operator!=(const Event& obj)
{
	if (start_time == obj.start_time && name == obj.name && obj.place == place) return false;
	return true;
}
