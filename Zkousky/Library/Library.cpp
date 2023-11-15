#include "Library.h"

std::list<Book> Library::getAvailableBooks()
{
    std::list<Book> available;
    for (Book book: books){
        if (book.getAvailable()==true) available.push_back(book);
    }
    return available;
}

Library::Library(std::string path_to_file)
{
    this->path = path_to_file;
    std::ifstream file;
    file.open(path);
    std::string book;
    while (std::getline(file, book)) {
        books.push_back(Book(book));
    }
    books.sort();
    //std::sort(books.begin(), books.end());
}

void Library::addBook(Book book)
{
    bool unique = true;
    for(Book b : books){
        if(b.getId()==book.getId()) unique = false;
    }
    if (unique) {
        books.push_back(book);
        books.sort();
        std::cout<<"Kniha přidána s ID: "<<book.getId()<<std::endl;
        }
    else{
        std::cout<<"Kniha nemá unikátní ID"<<std::endl;
    }
}

long Library::getUniqueId()
{
    long last_id = 0;
    for (Book book: books){
        if (book.getId()>last_id)last_id=book.getId();
    }
    return last_id+1;
}

void Library::showAvailableBooks()
{
    for (Book book: getAvailableBooks()){
        std::cout<<book<<std::endl;
    }

}

void Library::findBookAndBorrowIt(std::string name)
{
    std::list <Book> books;
    for (Book book: getAvailableBooks()){
        if (book.getName().find(name)!=std::string::npos){
            books.push_back(book);
        }
    }
    if (books.size()>1){
        std::cout<<"Nalezena více knih, prosím upřesněte hledání:"<<std::endl;
        for (Book book: books){
            std::cout<<book<<std::endl;
        }
    }else if (books.size()<1)
    {
        std::cout<<"Nenalezena žádná dostupná kniha s tímto jménem."<<std::endl;
    }else{
        std::cout<<"Nalezena tato kniha:"<<std::endl;
        std::cout<<*(books.begin())<<std::endl;
        std::cout<<"Chcete knihu vypujcit (A/N):"<<std::endl;
        char borrow;
        std::cin>>borrow;
        if (borrow=='A'){
            std::list <Book>::iterator b;
            for (b = this->books.begin(); b != this->books.end(); ++b)
            {
                if ((*b)==(*books.begin())) b->setAvailable(false);
            }
            
            std::cout<<"Kniha vypujcena"<<std::endl;
        }
    }
    
}

Library::~Library()
{
    std::ofstream file;
    file.open(path);
    std::stringstream out;
    for (Book b : books) {
        out << b << std::endl;
    }
    file.write(out.str().c_str(), out.str().size());
}

std::ostream &operator<<(std::ostream &out, const Library &obj)
{
    for(Book book: obj.books){
        out<<book<<std::endl;
    }
    return out;
}
