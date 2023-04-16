#pragma once
#include "Exercise.h"

struct Time
{
	int year;
	int month;
	int day;
	Time();
	Time(std::string date);
	bool operator<(const Time& obj);
	friend std::ostream& operator<<(std::ostream& out, const Time& obj);
};

class Training
{
private:
	Time training_date;
	std::vector<Exercise> exercises;
public:
	Training(std::string training);
	std::vector<std::tuple<std::string, int>> getBestExercise();
	bool operator<(const Training& obj);
	friend std::ostream& operator<<(std::ostream& out, const Training& obj);
};

