#include "Training.h"

Time::Time() {}

Time::Time(std::string date) {
	std::stringstream ss(date);
	std::vector<std::string> items;
	std::string item;
	while (std::getline(ss, item, '.')) {
		items.push_back(item);
	}
	day = stoi(items[0]);
	month = stoi(items[1]);
	year = stoi(items[2]);
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
			else return false;
		}
	}
	return false;
}

Training::Training(std::string training)
{
	std::stringstream ss(training);
	std::string line;
	std::getline(ss, line);
	if (line == "") {
		std::getline(ss, line);
	}
	this->training_date = Time(line);
	while (std::getline(ss, line)) {
		std::stringstream sl(line);
		std::string name, reps;
		std::getline(sl, name, '(');
		std::getline(sl, reps, ')');
		Exercise ex = Exercise(name);
		int i = 0;
		while (i < stoi(reps)) {
			std::getline(ss, line);
			ex.addRep(line);
			i++;
		}
		exercises.push_back(ex);
	}
}

std::vector<std::tuple<std::string, int>> Training::getBestExercise()
{
	std::vector<std::tuple<std::string, int>> out;
	for (Exercise e : exercises) {
		out.push_back(e.getBestRep());
	}
	return out;
}

bool Training::operator<(const Training& obj)
{
	if (training_date < obj.training_date) return true;
	else return false;
}

std::ostream& operator<<(std::ostream& out, const Training& obj)
{
	// TODO: insert return statement here
	out << obj.training_date << std::endl;
	for (Exercise ex : obj.exercises)
	{
		out << ex;
	}
	return out;
}

std::ostream& operator<<(std::ostream& out, const Time& obj)
{
	out << obj.day << "." << obj.month << "." << obj.year;
	return out;
}
