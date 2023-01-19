#include "Crossword.h"


Crossword::Crossword(int cols, int rows, std::string secret)
{
	this->cols = cols;
	this->rows = rows;
	this->crossword = new char* [rows];
	for (int i = 0; i < rows; i++) {
		this->crossword[i] = new char[cols];
		for (int j = 0; j < cols; j++)
			if (i==0 ||j==0)
				this->crossword[i][j] = '#';
			else
				this->crossword[i][j] = '_';
	}
	this->emplaceSecret(secret);
	clues.insert({ 0, "Tajenka" });
	std::default_random_engine generator;
	std::normal_distribution<float> distribution(9.2, 9.7);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			if (this->crossword[i][j] == '_') {
				auto const& [left, right] = getFreeRow(i,j);
				auto const& [up, down] = getFreeCol(i, j);
				if ((int)distribution(generator)>left && left>2 &&
					(int)distribution(generator)>right && right > 2 &&
					(int)distribution(generator)>up && up > 2&&
					(int)distribution(generator)>down && down > 2
					) {
					this->crossword[i][j] = '#';
				}
			}		
	}
}
Crossword::Crossword(const Crossword& obj)
{
	this->cols = obj.cols;
	this->rows = obj.rows;
	this->crossword = new char* [this->rows];
	for (int i = 0; i < this->rows; i++) {
		this->crossword[i] = new char[this->cols];
		for (int j = 0; j < this->cols; j++)
			this->crossword[i][j] = obj.crossword[i][j];
	}
	std::map<int, std::string>::const_iterator it = obj.clues.begin();
	while (it != obj.clues.end())
	{
		this->clues[it->first] = it->second;
		++it;
	}
}

bool Crossword::completed()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (this->crossword[i][j] == '_')
				return false;
		}
	}
	return true;
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
std::tuple<int,int> Crossword::getFreeRow(int row, int col) {
	int sumR = 0, sumL = 0;
	for (int i = col; i < this->cols; i++) {
		if (this->crossword[row][i] == '_') sumR += 1;
		else break;
	}
	for (int i = col; i >= 0; i--) {
		if (this->crossword[row][i] == '_') sumL += 1;
		else break;
	}
	return std::make_tuple(sumL,sumR);
}
std::tuple<int, int> Crossword::getFreeCol(int row, int col) {
	int sumD = 0, sumU = 0;
	for (int i = row; i < this->rows; i++) {
		if (this->crossword[i][col] == '_') sumD += 1;
		else break;
	}
	for (int i = row; i >= 0; i--) {
		if (this->crossword[i][col] == '_') sumU += 1;
		else break;
	}
	return std::make_tuple(sumU, sumD);
}

//std::tuple<int, int> Crossword::getBestCandidate() {
//	int col, row, val=rows;
//	for (int i = 1; i < rows-1; i++) {
//		for (int j = 1; j < cols-1; j++) {
//			if (crossword[i][j] != '_' && crossword[i][j] != '#') {
//				std::string horizontal = getFreePlacesRow(i, j);
//				std::string vertical = getFreePlacesCol(i, j);
//
//				int h = std::count(horizontal.begin(), horizontal.end(), '_');
//				int v = std::count(vertical.begin(), vertical.end(), '_');
//
//				if (val > (v+h) && (horizontal.find('_') != std::string::npos || vertical.find('_') != std::string::npos)) {
//					val = v+h;
//					row = i, col = j;
//				}
//
//				
//			}
//		}
//	}
//	return std::make_tuple(row, col);
//}

std::vector<std::string> Crossword::getAllPatterns()
{
	std::vector<std::string> output;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (this->crossword[i][j] == '#') {
				if (this->crossword[i][(j+1 < cols) ? j+1 : cols - 1] != '#') {
					auto const& [pattern, pos] = getPatternRow(i, j + 1);
					if (pattern != "")
						output.push_back(pattern);
				}
				if (this->crossword[(i+1 < rows) ? i + 1 : rows - 1][j] != '#') {
					auto const& [pattern, pos] = getPatternCol(i + 1, j);
					if (pattern != "")
						output.push_back(pattern);
				}
			}
		}
	}
	return output;
}

std::vector<std::tuple<std::string, int, int, char, int>> Crossword::getAllPosiblePatterns()
{
	std::vector<std::tuple<std::string, int, int, char, int>> posiblePatterns;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (this->crossword[i][j] != '_' && this->crossword[i][j] != '#') {
				auto const& [row_pattern, r_pos] = getPatternRow(i, j);
				auto const& [col_pattern, c_pos] = getPatternCol(i, j);
				if (row_pattern.length() > 0) posiblePatterns.push_back(std::make_tuple(row_pattern, i, j, 'r', r_pos));
				if (col_pattern.length() > 0) posiblePatterns.push_back(std::make_tuple(col_pattern, i, j, 'c', c_pos));
			}
		}
	}
	return posiblePatterns;
}

std::tuple<std::string,int> Crossword::getPatternRow(int row, int col) {
	std::string right , left;
	for (int c = col+1; c < this->cols; c++) {
		if (crossword[row][c] == '#') break;
		else right += crossword[row][c];
	}
	for (int c = col-1; c >= 0; c--) {
		if (crossword[row][c] == '#') break;
		else left = crossword[row][c] + left;
	}
	std::string output = left + crossword[row][col] + right;
	if (std::count(output.begin(), output.end(), '_') == 0) return std::make_tuple("", 0);
	return make_tuple(output, left.length());
}
std::tuple<std::string, int> Crossword::getPatternCol(int row, int col) {
	std::string down , up ;
	for (int r = row+1; r < this->rows; r++) {
		if (crossword[r][col] == '#') break;
		else down += crossword[r][col];
	}
	for (int r = row-1; r >= 0; r--) {
		if (crossword[r][col] == '#') break;
		else up = crossword[r][col] + up;
	}
	std::string output = up + crossword[row][col] + down;
	if (std::count(output.begin(), output.end(), '_') == 0) return std::make_tuple("", 0);
	return make_tuple(output, up.length());
}

void Crossword::add_word(std::string word, std::string clue, int row, int col, char direction, int pos)
{
	int idx = 0;
	for (char c : word) {
		if (direction == 'r') {
			this->crossword[row][col - pos + idx] = c;
		}
		else {
			this->crossword[row - pos + idx][col ] = c;
		}
		
		idx++;
	}
	/*int id = clues.end()->first;
	this->clues.insert({ id + 1,clue });*/
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