// 0_Crossword.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
#include <string>
#include "Crossword.h"
#include "DB.h"

#include <chrono>
#include <random>

using namespace std;

void fillCroswordRecursion(Crossword crossword_in);

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

	cout << test << endl;
	cout << test.completed();
	std::vector<std::string> t = test.getAllPatterns();
	DB db(R"(c:\DeleteMe\CROSSWORD.db)");
	db.createViewWithAllWords(t);
	db.getRows();
	//fillCroswordRecursion(test);

	

	return 0;	
}

void fillCroswordRecursion(Crossword crossword_in)
{
	
	std::vector<std::tuple <string,int,int,char, int>> all_posible_paterns = crossword_in.getAllPosiblePatterns();
	for (auto const& [pattern, row, col, direction, pos] : all_posible_paterns) {
		DB db(R"(c:\DeleteMe\CROSSWORD.db)");
		std::vector<tuple<string,string>> posible_words = db.getPosibleWords(pattern);
		std::system("CLS");
		std::cout << crossword_in << std::endl;
		if (posible_words.size() != 0) {
			for (auto const& [word, clue] : posible_words) {
				Crossword crossword_out(crossword_in);
				crossword_out.add_word(word, clue, row, col, direction, pos);
				if (crossword_out.completed()) {
					std::cout << crossword_out << std::endl;
				}
				else {
					fillCroswordRecursion(crossword_out);
				}
			}
		}
		else break;
	}
}
