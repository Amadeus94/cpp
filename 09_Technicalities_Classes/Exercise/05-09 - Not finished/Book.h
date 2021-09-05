#include <string>

enum class Genre
{
    fiction = 1,
    nonfiction,
    periodical,
    biography,
    children,
    DefaultLisa
};

class Book
{
public:
    std::string getISBN() const { return ISBN; }; // form: n-n-n-x n is an integer -- x is a digit or letter  --- isbn as string
    std::string setISBN(std::string ISBN) { this->ISBN=ISBN; }; // form: n-n-n-x n is an integer -- x is a digit or letter  --- isbn as string
    std::string getTitle() const { return title; };
    std::string getAuthor() const { return author; };
    Genre getGenre() const { return genre; };
    std::string getCopyrightDate() const { return copyrightDate; };
    bool isCheckedOut() const { return checkedOut; };
    Book(std::string ISBN,
         std::string title,
         std::string author,
         std::string copyrightDate);
    Book();

    void checkBookOut();

private:
    std::string ISBN, title, author, copyrightDate;
    bool checkedOut = false;
    Genre genre;
};


bool operator!=(Book book1, Book book2);
bool operator==(Book book1, Book book2);
std::ostream& operator<<(std::ostream& os, Book& book);
bool validateBookName(std::string book);
bool validateISBN(std::string isbn);
