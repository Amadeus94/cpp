#include <string>
#include <vector>
#include "Book.h"
#include "Patron.h"
#include "../../Drill/final_Date_Class/Chrono.h"

struct Transaction{
    Book book;
    Patron patron;
    Chrono::Date date;
};

class Library
{
public:
    class Invalid{};
    void addBookToLibrary();
    void addPatronToLibrary();
    void checkOutBook(); // Make sure that both the user and the book are in the library
                            // if they are not  report an error
                            // if not create a transaction  andd add it into the transactions vector
private:
    std::vector<Book> books;
    std::vector<Patron> patrons;
    std::vector<Transaction> transactions;

};

