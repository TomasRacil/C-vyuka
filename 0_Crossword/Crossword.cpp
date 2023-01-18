#include "Crossword.h"

Crossword::Crossword(int cols, int rows, std::string secret)
{
	this->cols = cols;
	this->rows = rows;
	this->crossword = new char* [rows];
	for (int i = 0; i < rows; i++) {
		this->crossword[i] = new char[cols];
		for (int j = 0; j < cols; j++)
			this->crossword[i][j] = '_';
	}
	this->emplaceSecret(secret);
}
Crossword::Crossword(int cols, int rows, char ** crossword)
{
	this->cols = cols;
	this->rows = rows;
	this->crossword = new char* [rows];
	for (int i = 0; i < rows; i++) {
		this->crossword[i] = new char[cols];
		for (int j = 0; j < cols; j++)
			this->crossword[i][j] = crossword[i][j];
	}
}

void Crossword::emplaceSecret(std::string secret)
{
	int x = 0, y = 0, i = 0, s = 0;
	srand((unsigned int)time(NULL));
	do {
		y = 1 + rand() % (this->rows - 2);
		x = 1 + rand() % (this->cols - 2);
	} while ((x + secret.size()+2) > this->cols && (y + secret.size()+2) > this->rows);

	for (char ch : "#" + secret + "#") {
		this->crossword[y + i][x + s] = toupper(ch);
		if (y + secret.size()+2 > rows)
			s++;
		else i++;
	}
}
int Crossword::countEmpty() {
	int empty = 0;
	for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++)
				if (this->crossword[i][j] != ' ') {
					empty += 1;
				};
		}
	return empty;
}
//char** Crossword::copy() {
//	char ** crossword_copy = new char* [rows];
//	for (int i = 0; i < rows; i++) {
//		crossword_copy[i] = new char[cols];
//		for (int j = 0; j < cols; j++)
//			crossword_copy[i][j] = this->crossword[i][j];
//	}
//}

//void Crossword::fill()
//{
//	const auto [row, col] = getBestCandidate();
//	std::cout << row << " " << col << std::endl;
//	std::string horizontal = getFreePlacesRow(row, col);
//	std::string vertical = getFreePlacesCol(row, col);
//
//	std::cout<<horizontal<<std::endl;
//	std::cout << vertical << std::endl;
//	if (std::count(horizontal.begin(), horizontal.end(), '_') > std::count(vertical.begin(), vertical.end(), '_') && horizontal.find('_') != std::string::npos) {
//		//horizotal
//		auto words = db.getPosibleWords(horizontal);
//		if (words.empty()) {
//			//backtrack
//		}
//		else {
//			for (std::tuple<std::string,std::string> word : words) {
//				auto [word, clue] = word;
//				int idx = horizontal.find(crossword[row][col]);
//				int x = 0;
//				for (char ch : "#" + word + "#") {
//					crossword[row][col - idx - 1 + x] = ch;
//					x++;
//			}
//			}
//		}
//	}
//	else if (vertical.find('_') != std::string::npos) {
//		//vertical
//		auto words = db.getPosibleWords(vertical);
//		if (words.empty()) {
//			//backtrack
//		}
//		else {
//			auto [word, clue] = words[0];
//			int idx = vertical.find(crossword[row][col]);
//			int x = 0;
//			for (char ch : "#" + word + "#") {
//				crossword[row - idx - 1 + x][col] = ch;
//				x++;
//			}
//		}
//		
//	}
//	
//}

std::tuple<int, int> Crossword::getBestCandidate() {
	int col, row, val=rows;
	for (int i = 1; i < rows-1; i++) {
		for (int j = 1; j < cols-1; j++) {
			if (crossword[i][j] != '_' && crossword[i][j] != '#') {
				std::string horizontal = getFreePlacesRow(i, j);
				std::string vertical = getFreePlacesCol(i, j);

				int h = std::count(horizontal.begin(), horizontal.end(), '_');
				int v = std::count(vertical.begin(), vertical.end(), '_');

				if (val > (v+h) && (horizontal.find('_') != std::string::npos || vertical.find('_') != std::string::npos)) {
					val = v+h;
					row = i, col = j;
				}

				
			}
		}
	}
	return std::make_tuple(row, col);
}

std::string Crossword::getFreePlacesRow(int row, int col) {
	std::string right , left;
	for (int c = col+1; c < this->cols-1; c++) {
		if (crossword[row][c] == '#') {
			break;
		}
		else {
			right += crossword[row][c];
		}
	}
	for (int c = col-1; c > 0; c--) {
		if (crossword[row][c] == '#') {
			break;
		}
		else {
			left = crossword[row][c] + left;
		}
	}
	return left + crossword[row][col] + right;
}
std::string Crossword::getFreePlacesCol(int row, int col) {
	std::string down , up ;
	for (int r = row+1; r < this->rows-1; r++) {
		if (crossword[r][col] == '#') {
			break;
		}
		else {
			down += crossword[r][col];
		}
	}
	for (int r = row-1; r > 0; r--) {
		if (crossword[r][col] == '#') {
			break;
		}
		else {
			up = crossword[r][col] + up;
		}
	}
	return up + crossword[row][col] + down;
}
	
Crossword::~Crossword()
{
	for (int i = 0; i < rows; i++) {
		delete[] crossword[i];
	}
	delete[] crossword;
	crossword = nullptr;
}

std::ostream& operator<<(std::ostream& out, const Crossword& c)
{
	/*out << getName(m) << ": \n";*/
	std::string output;
	for (int i = 0; i < c.rows; i++) {
		output += (std::string(c.cols * 2 + 1, '_') + "\n");
		output+= "|";
		for (int j = 0; j < c.cols; j++) {

			output += c.crossword[i][j];
			output += + "|";
		}
		output += "\n";
	}
	output += "\n";
	out << output;
	return out;

}