#include "Book.h"
#include "Library.h"
#include <iostream>


int main(){
    Book book("9;Animal Farm;Orwell George;Available");
    std::cout<<book<<std::endl<<std::endl;

    Library library("data.txt");
    std::cout<<library<<std::endl<<std::endl;

    library.addBook(book);
    std::cout<<std::endl;

    book.setID(library.getUniqueId());
    library.addBook(book);
    std::cout<<std::endl;

    std::cout<<"Dostupné knihy:"<<std::endl;
    library.showAvailableBooks();
    std::cout<<std::endl;

    std::cout<<"Pujceni knihy:"<<std::endl;
    library.findBookAndBorrowIt("Kill");
    std::cout<<std::endl;
    library.findBookAndBorrowIt("a");
    std::cout<<std::endl;
    library.findBookAndBorrowIt("Great");
    std::cout<<std::endl;

    std::cout<<"Dostupné knihy:"<<std::endl;
    library.showAvailableBooks();
    std::cout<<std::endl;

}