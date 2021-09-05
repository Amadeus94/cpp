#include "Library.h"
#include <iostream>
#include <string>

void Library::addBookToLibrary(int n)
{
    Book book;
    std::cout << "=== Add book to Library: ===";
    book.checkBookOut();

    this->books.push_back(book);

 //   std::string &originalISBN = book.getISBN();
 //   char &lastItem = originalISBN.at(originalISBN.size() - 1);
 //   for (size_t i = 0; i < n; i++)
 //   {
 //       lastItem = char(n + 1);
 //       this->books.push_back(book);
 //   }
};