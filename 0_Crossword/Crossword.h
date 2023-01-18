#pragma once
#include <string>
#include <iostream>
#include <tuple>
#include <algorithm>
#include "DB.h"

class Crossword
{
private:
	int rows;
	int cols;
	char** crossword;
	/*DB db = DB(R"(c:\DeleteMe\CROSSWORD.db)");*/
	
	
public:
	
	Crossword(int cols, int rows, std::string secret);
	Crossword(int cols, int rows, char** crossword);
	void emplaceSecret(std::string secret);
	int countEmpty();
	/*void fill();*/
	std::tuple<int, int> getBestCandidate();
	std::string getFreePlacesRow(int row, int col);
	std::string getFreePlacesCol(int row, int col);
	~Crossword();
	friend std::ostream& operator << (std::ostream& out, const Crossword& c);
};

