#pragma once
#include <string>
#include <sqlite3.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>

class DB
{
private:
	std::string dir;

public:
	DB(std::string directory);
	void createDB();
	void createTables();
	void fillDB(std::string path);
	void getRows();
	std::vector<std::tuple<std::string, std::string>> getPosibleWords(std::string pattern);
	//void deleteData(); // use prior to insert

	//void insertData(std::string word, std::string clue); // uncomment the deleteData above to avoid duplicates
	//void updateData();
	//void selectData();
	//void selectData(std::string table, int id);
	//void getWordID(std::string word);
};

