#include "Calendar.h"

Calendar::Calendar(std::string name)
{
	this->name = name;
	this->path = name + ".txt";
}

Calendar::Calendar(std::string name, std::string path)
{
	this->name = name;
	this->path = path;

	std::string event;
	std::ifstream file;
	file.open(path);
	std::string line;
	while (getline(file, line)) {
		if (line != "") {
			event += line + '\n';
		}
		else {
			this->events.push_back(Event(event));
			event.erase();
		}
	}
	if (!event.empty()) {
		this->events.push_back(Event(event));
		event.erase();
	}
	this->events.sort();
}

void Calendar::addEvent(Event event)
{
	if (std::find(events.begin(), events.end(), event) == events.end())
		events.push_back(event);
	else 
		std::cout << "Event already in calendar" << std::endl <<std::endl;
	events.sort();
}

Calendar Calendar::findEvent(std::string name)
{
	Calendar foundEvents = Calendar("Events named " + name);
	for (Event e : events) {
		if (e.name == name) {
			foundEvents.addEvent(e);
		}
	}
	return foundEvents;
}

Calendar Calendar::findEventsAfter(Time time)
{
	std::stringstream time_s;
	time_s << time;
	Calendar foundEvents = Calendar("Events after " + time_s.str());
	for (Event e : events) {
		if (e.start_time > time) {
			foundEvents.addEvent(e);
		}
	}
	return foundEvents;
}

Calendar::~Calendar()
{
	std::ofstream file;
	file.open(this->name+".txt");
	std::stringstream out;
	for (Event event : events) {
		out << event.name << "\n";
		out << event.start_time.year << " " << event.start_time.month << " " << event.start_time.day << " "<< event.start_time.hour <<" "<< event.start_time.minute<<"\n";
		out << event.end_time.year << " " << event.end_time.month << " " << event.end_time.day << " " << event.end_time.hour << " " << event.end_time.minute << "\n";
		out << event.place << "\n";
		out << event.description << "\n\n";
	}
	file.write(out.str().c_str(), out.str().size());
}

Calendar Calendar::findEventsBefore(Time time)
{
	std::stringstream time_s;
	time_s << time;
	Calendar foundEvents = Calendar("Events before " + time_s.str());
	for (Event e : events) {
		if (e.start_time < time) {
			foundEvents.addEvent(e);
		}
	}
	return foundEvents;
}

std::ostream& operator<<(std::ostream& out, const Calendar& obj)
{
	out << obj.name << std::endl;
	for (Event e : obj.events) {
		out << e << std::endl<<std::endl;
	}
	return out;
}
