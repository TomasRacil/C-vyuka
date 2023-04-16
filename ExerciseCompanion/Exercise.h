#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <tuple>

struct Rep
{
	int repetions;
	int weight;
	Rep(std::string);
	Rep(int repetions, float weight);
	friend std::ostream& operator<<(std::ostream& out, const Rep& obj);
};

class Exercise
{
private:
	std::string name;
	int series;
	std::vector<Rep> reps;
public:
	//Exercise(std::string text);
	Exercise(std::string name);
	std::tuple<std::string, int> getBestRep();
	void addRep(Rep rep);
	friend std::ostream& operator<<(std::ostream& out, const Exercise& obj);
};

