#pragma once
#include <list>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <algorithm>
#include "Book.h"

class Library
{
private:
    std::string path;
    std::list <Book> books;
    std::list <Book> getAvailableBooks();
public:
    Library(std::string path_to_file);
    void addBook(Book book);
    long getUniqueId();
    void showAvailableBooks();
    void findBookAndBorrowIt(std::string name);
    
    ~Library();

    friend std::ostream& operator<<(std::ostream& out, const Library& obj);
};
