#pragma once
//#include <vector>
//#include <string>
#include <fstream>
#include <algorithm>
#include <map>
#include <iostream>
#include "Training.h"

class TrainingDiary
{
private:
	std::string path;
	std::string owner;
	std::vector<Training> trainings;
public:
	TrainingDiary(std::string path);
	void printPersonalBest();
	void addTraining(Training training);
	friend std::ostream& operator<<(std::ostream& out, const TrainingDiary& obj);
	~TrainingDiary();
};

