#include "DB.h"

// retrieve contents of database used by selectData()
/* argc: holds the number of results, argv: holds each value in array, azColName: holds each column returned in array, */
static int callback(void* NotUsed, int argc, char** argv, char** azColName)
{
	for (int i = 0; i < argc; i++) {
		// column name and value
		std::cout << azColName[i] << ": " << argv[i] << std::endl;
	}

	std::cout << std::endl;

	return 0;
}

void replace_all(
	std::string& s,
	std::string const& toReplace,
	std::string const& replaceWith
) {
	std::string buf;
	std::size_t pos = 0;
	std::size_t prevPos;

	// Reserves rough estimate of final size of string.
	buf.reserve(s.size());

	while (true) {
		prevPos = pos;
		pos = s.find(toReplace, pos);
		if (pos == std::string::npos)
			break;
		buf.append(s, prevPos, pos - prevPos);
		buf += replaceWith;
		pos += toReplace.size();
	}
	buf.append(s, prevPos, s.size() - prevPos);
	s.swap(buf);
}


DB::DB(std::string directory)
{
	dir = directory;
}

void DB::createDB()
{
	sqlite3* DB;

	int exit = 0;
	exit = sqlite3_open(this->dir.c_str(), &DB);

	sqlite3_close(DB);
}

void DB::createTables()
{
	sqlite3* DB;
	char* messageError;

	std::string sql = "CREATE TABLE IF NOT EXISTS word("
		"word      TEXT NOT NULL,"
		"clue      TEXT NOT NULL);"
		"CREATE INDEX word_index"
		"ON      word(word);";
		/*"CREATE TABLE IF NOT EXISTS clue("
		"clue      TEXT PRIMARY KEY,"
		"word     TEXT );";*/
		//"FOREIGN KEY(word) REFERENCES word(word));";

	try
	{
		int exit = 0;
		exit = sqlite3_open(this->dir.c_str(), &DB);
		/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
		if (exit != SQLITE_OK) {
			std::cerr << "Error in createTable function." << std::endl;
			sqlite3_free(messageError);
		}
		else
			std::cout << "Table created Successfully" << std::endl;
		sqlite3_close(DB);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
	}
}

void DB::fillDB(std::string path)
{
	std::fstream infile(path);
	std::string line;
	std::vector<std::string> splittedString(4);
	std::getline(infile, line);

	sqlite3* DB;

	int exit = sqlite3_open(this->dir.c_str(), &DB);

	char* errorMessage;

	sqlite3_exec(DB, "PRAGMA synchronous=OFF", NULL, NULL, &errorMessage);
	sqlite3_exec(DB, "PRAGMA count_changes=OFF", NULL, NULL, &errorMessage);
	sqlite3_exec(DB, "PRAGMA journal_mode=MEMORY", NULL, NULL, &errorMessage);
	sqlite3_exec(DB, "PRAGMA temp_store=MEMORY", NULL, NULL, &errorMessage);

	sqlite3_exec(DB, "BEGIN TRANSACTION", NULL, NULL, &errorMessage);

	std::string word_buffer = "INSERT INTO word (word, clue) VALUES (?,?); ";/*
	//char clue_buffer[] = "INSERT INTO (clue,word) clue VALUES (?2, ?1); ";*/
	sqlite3_stmt* word;
	///*sqlite3_stmt* clue;*/

	sqlite3_prepare_v2(DB, word_buffer.c_str(), word_buffer.length(), &word, NULL);
	////sqlite3_prepare_v2(DB, clue_buffer, strlen(clue_buffer), &clue, NULL);

	while (getline(infile, line))
	{
		splittedString.clear();
		size_t last = 0, pos = 0;
		while ((pos = line.find('\t', last)) != std::string::npos) {
			splittedString.emplace_back(line, last, pos - last);
			last = pos + 1;
		}
		if (last)
			splittedString.emplace_back(line, last);
		if (splittedString[2] != "") {
			replace_all(splittedString[2], "'", "''");
			replace_all(splittedString[3], "'", "''");

			sqlite3_bind_text(word, 1, splittedString[2].c_str(), splittedString[2].size(), SQLITE_STATIC);
			sqlite3_bind_text(word, 2, splittedString[3].c_str(), splittedString[3].size(), SQLITE_STATIC);
			/*sqlite3_bind_text(clue, 2, splittedString[3].c_str(), splittedString[3].length(), SQLITE_STATIC);
			sqlite3_bind_text(clue, 1, splittedString[2].c_str(), splittedString[2].length(), SQLITE_STATIC);*/

			auto step_word = sqlite3_step(word);
			/*auto step_clue = sqlite3_step(clue);*/

			if (step_word != SQLITE_DONE)
			{
				printf("Commit Failed!\n");
			}
			/*if (step_clue != SQLITE_DONE)
			{
				printf("Commit Failed!\n");
			}*/
			sqlite3_reset(word); /*
			sqlite3_reset(clue);*/
		}		
	}

	sqlite3_exec(DB, "COMMIT TRANSACTION", NULL, NULL, &errorMessage);
	sqlite3_finalize(word);
	/*sqlite3_exec(DB, "CREATE INDEX words_index ON word(word);", NULL, NULL, &errorMessage);*/
}

void DB::getRows()
{
	sqlite3* DB;
	char* messageError;
	int exit = sqlite3_open(this->dir.c_str(), &DB);

	std::string sql("SELECT COUNT(*) FROM posible_words;");
	exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);
	
}

std::vector<std::tuple<std::string,std::string>> DB::getPosibleWords(std::string pattern)
{
	 sqlite3* DB;
	 sqlite3_stmt* stmt;
	 std::vector<std::tuple<std::string, std::string>> posible_words;
	 int exit = sqlite3_open(this->dir.c_str(), &DB);

	 std::string selectQuery = "SELECT word, clue FROM word WHERE word LIKE ?;";
	 try {
		 sqlite3_prepare_v2(DB, selectQuery.c_str(), selectQuery.length(), &stmt, NULL);

		 sqlite3_bind_text(stmt, 1, pattern.c_str(), pattern.size(), SQLITE_STATIC);

		 while ((sqlite3_step(stmt)) == SQLITE_ROW) {
			 posible_words.push_back(
				 std::make_tuple(
					 std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))),
					 std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)))));
		 }
	 }
	 catch(...){
		 std::cout << "Search error" << std::endl;
	 }
	 return posible_words;
}
void DB::createViewWithAllWords(std::vector<std::string> patterns) {

	sqlite3* DB;
	std::string selectQuery = "CREATE VIEW posible_words AS  SELECT word, clue FROM word WHERE (";
	for (std::string pattern : patterns) {
		selectQuery += "word LIKE '" + pattern + "' OR ";
	}
	selectQuery = selectQuery.substr(0, selectQuery.length() - 3) + ");";
	try
	{
		int exit = 0;
		char* messageError;
		exit = sqlite3_open(this->dir.c_str(), &DB);
		/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
		exit = sqlite3_exec(DB, selectQuery.c_str(), NULL, 0, &messageError);
		if (exit != SQLITE_OK) {
			std::cerr << "Error in createTable function." << std::endl;
			sqlite3_free(messageError);
		}
		else
			std::cout << "Table created Successfully" << std::endl;
		sqlite3_close(DB);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
	}
}
