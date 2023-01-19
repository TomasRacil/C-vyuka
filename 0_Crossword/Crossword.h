#pragma once
#include <string>
#include <iostream>
#include <tuple>
#include <algorithm>
#include <random>
#include "DB.h"
#include <map>

class Crossword
{
private:
	int rows;
	int cols;
	char** crossword;
	std::map<int, std::string> clues;
	/*DB db = DB(R"(c:\DeleteMe\CROSSWORD.db)");*/
	
	
public:
	
	Crossword(int cols, int rows, std::string secret);
	Crossword(const Crossword& obj);
	bool completed();
	void emplaceSecret(std::string secret);
	std::tuple<int, int> getFreeRow(int row, int col);
	std::tuple<int, int> getFreeCol(int row, int col);
	//std::tuple<int, int> getBestCandidate();
	std::vector<std::string>getAllPatterns();
	std::vector<std::tuple<std::string, int, int, char, int>> getAllPosiblePatterns();
	std::tuple<std::string, int> getPatternRow(int row, int col);
	std::tuple<std::string, int> getPatternCol(int row, int col);
	void add_word(std::string word, std::string clue, int row, int col, char direction, int pos);
	~Crossword();
	friend std::ostream& operator << (std::ostream& out, const Crossword& c);
};

