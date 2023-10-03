#pragma once
#include <string>
#include <ostream>
#include <sstream>
#include <vector>
#include <iomanip>

struct Time {
	int minute;
	int hour;
	int day;
	int month;
	int year;

	Time();
	Time(std::string time);

	bool operator < (const Time& obj);
	bool operator > (const Time& obj);
	bool operator == (const Time& obj);
	bool operator != (const Time& obj);

	friend std::ostream& operator << (std::ostream& out, const Time& obj);
};



class Event
{
private:
	std::string name;
	Time start_time;
	Time end_time;
	std::string place;
	std::string description;

public:
	Event(std::string path);
	Event(std::string name, std::string start_time, std::string end_time, std::string place, std::string description);

	std::string getName();
	Time* getStartTime();

	bool operator < (const Event& obj);
	bool operator > (const Event& obj);
	bool operator == (const Event& obj);
	bool operator != (const Event& obj);

	friend std::ostream& operator << (std::ostream& out, const Event& obj);
	friend class Calendar;
};

