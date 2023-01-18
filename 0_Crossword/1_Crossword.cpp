// 0_Crossword.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
#include <string>
#include "Crossword.h"
#include "DB.h"

#include <chrono>

using namespace std;

Crossword fillCroswordRecursion(Crossword recurive);

int main()
{
	/*std::string dir = R"(c:\DeleteMe\CROSSWORD.db)";
	DB db(dir);*/

	int rows=10, cols=10;
	std::string secret="Python";
	/*std::cin >> rows;
	std::cin >> cols;
	std::cin >> secret;*/

	Crossword test(cols, rows, secret); 

	cout << test;
	/*int x;
	while (true){
		cout << test;
		test.fill();
		cin >> x;
	}*/
	

	/*db.getRows();
	db.createDB();
	db.createTables();
	db.getRows();
	auto start = std::chrono::high_resolution_clock::now();
	db.fillDB("clues.tsv");
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
	cout << duration.count() << endl;
	db.getRows();*/

	/*auto start = std::chrono::high_resolution_clock::now();
	db.getPosibleWords("_Y____");
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
	cout << duration.count() << endl;*/

	return 0;

	
	
}



//fill db
/*std::ifstream file("clues.tsv", std::ios::binary | std::ios::ate);
	std::streamsize size = file.tellg();
	file.seekg(0, std::ios::beg);
	std::vector<char> buffer(size);
	std::map<std::string, list<std::string>> dict;
	if (file.read(buffer.data(), size))
	{
	}
	int row = 0;
	int col = 0;
	std::string word, clue;
	for (char ch : buffer) {
		if (row != 0) {
			if (ch == '\t') {
				col++;
			}
			else if (ch == '\n') {
				col = 0;
				row++;
				if (!word.empty()) {
					word.shrink_to_fit();
					clue.shrink_to_fit();
					dict[word].push_back(clue);
					word.clear();
					clue.clear();
				}

			}
			else {
				if (col == 2)
					word += ch;
				else if (col == 3)
					clue += ch;
			}

		}
		else if (ch == '\n') {
			row++;
		}
	}
	buffer.clear();
	buffer.shrink_to_fit();*/

//Crossword fillCroswordRecursion(Crossword recursive)
//{
//	auto [row, col] = recursive.getBestCandidate();
//	std::string horizontal = recursive.getFreePlacesRow(row, col), vertival = recursive.getFreePlacesCol(row, col);
//	return Crossword();
//}
