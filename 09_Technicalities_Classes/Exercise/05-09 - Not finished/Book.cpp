#include <string>
#include <iostream>
#include "Book.h"
#include <vector>
#include <ctype.h>
using namespace std;

bool validateBookName(string book)
{
    for (char c : book)
    {
        if (c == '#')
            return false;
    }
    return true;
}

// form: n-n-n-x
// n = integer ; x= a digit or letter
bool validateISBN(string isbn)
{
    int max = INT_MAX;
    int min = INT_MIN;

    int count = 0;

    int int1, int2, int3;
    char last;

    int begin = 0;
    int end;

    vector<string> s;
    string substring;

    for (size_t i = 0; i < isbn.size() && count != 3; i++)
    {
        if (!isdigit(isbn.at(i)) && isbn.at(i) != '-')
            return false;
        if (isbn.at(i) == '-')
        {
            count++;
            substring = isbn.substr(begin, i - begin); // copy three characters of isbn ( starting from position 1)
            s.push_back(substring);
            begin = i + 1;
            end = i;
            continue;
        }
    }

    if (count != 3)
        return false;

    if ((isbn.size() - 1 - end != 1) && (isdigit(isbn.at(isbn.size() - 1)) || isalpha(isbn.at(isbn.size() - 1))))
    {
        cout << "too many after - ";
        return false;
    }
    return true;
}

void Book::checkBookOut()
{
    cout << "Welcome to Amadeus Library: " << endl
         << "Book name: ";
    string title, author, copyrightDate, ISBN;
    Genre genre;
    int genreNum;

    // DRY lol
    getline(cin, title);
    if (validateBookName(title))
        this->title = title;
    else
    {
        cout << "ERROR";
    }

    cout << endl
         << "Author's name: ";
    getline(cin, author);
    this->author = author;

    cout << endl
         << "Copyright Date: ";
    getline(cin, copyrightDate);
    this->copyrightDate = copyrightDate;

    cout << endl
         << "ISBN: ";
    getline(cin, ISBN);
    if (validateISBN(ISBN))
    {
        this->ISBN = ISBN;
    }
    else
    {
        cout << "Error ISBN";
    }
    cout << endl
         << "Choose a genre: \n 1. fiction \n 2. nonfiction  \n 3. periodical  \n 4. biography  \n 5. children ";
    cin >> genreNum;
    genre = (Genre)genreNum;
}

//Operators
// == checks for ISB is the same for two books
// != not ---
// << prints out title, author and isbn on separate lines
bool operator==(Book book1, Book book2)
{
    return book1.getISBN() == book2.getISBN();
}

bool operator!=(Book book1, Book book2)
{
    return !(book1 == book2);
}

ostream &operator<<(ostream &os, Book &book)
{
    os << endl
       << "Printing Book information: " << endl
       << "title: " << book.getTitle() << endl
       << "author: " << book.getAuthor() << endl
       << "copyrightdate: " << book.getCopyrightDate() << endl
       << "isbn: " << book.getISBN() << endl;
    return os;
}

Book::Book(std::string ISBN,
           std::string title,
           std::string author,
           std::string copyrightDate) : ISBN{ISBN}, title{title}, author{author}, copyrightDate{copyrightDate}
{
    this->genre = Genre::DefaultLisa;
}

Book::Book()
{
    this->genre = Genre::DefaultLisa;
}
