#pragma once
#include <string>
#include <sstream>
#include <vector>

class Book
{
private:
    long id; 
    std::string name;
    std::string author;
    bool available;
public:
    Book();
    Book(std::string book);
    long getId();
    void setID(long id);
    bool getAvailable();
    void setAvailable(bool available);
    std::string getName();
    bool operator <(const Book& obj);
    bool operator ==(const Book& obj);

    ~Book();

    friend std::ostream& operator<<(std::ostream& out, const Book& obj);
};
