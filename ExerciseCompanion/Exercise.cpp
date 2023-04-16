#include "Exercise.h"

Exercise::Exercise(std::string name)
{
	this->name = name;
	this->series = 0;
}

std::tuple<std::string, int> Exercise::getBestRep()
{
	int max = 0;
	for (Rep r : reps) {
		if (r.weight > max) {
			max = r.weight;
		}
	}
	return std::tuple<std::string, int>(name,max);
}

void Exercise::addRep(Rep rep)
{
	reps.push_back(rep);
	series = reps.size();
}

std::ostream& operator<<(std::ostream& out, const Rep& obj)
{
	// TODO: insert return statement here
	out << obj.repetions << " x " << obj.weight<<" kg"<<std::endl;
	return out;
}

std::ostream& operator<<(std::ostream& out, const Exercise& obj)
{
	// TODO: insert return statement here
	out << obj.name << "(" << obj.series << "):" << std::endl;
	for (Rep rep :obj.reps) 
	{
		out << rep;
	}
	return out;
}

Rep::Rep(std::string rep)
{
	std::stringstream ss(rep);
	std::string item;
	std::vector<std::string> items;
	while (std::getline(ss, item, ' ')) {
		items.push_back(item);
	}
	this->repetions = stoi(items[0]);
	this->weight = stoi(items[2]);
}

Rep::Rep(int repetions, float weight)
{
	this->repetions = repetions;
	this->weight = weight;
}
