#ifndef BOOKSLIST_H_INCLUDED
#define BOOKSLIST_H_INCLUDED

#include "Book.h"

class BookList{
  private:
    Book *books;
    int capacity;
    int bookCount;
  public:
    BookList();
    BookList(int);
    BookList(const BookList &);
    void addBook(const Book &);
    int getBookCount() const;
    Book *searchBook(string) const;
    Book *searchBook(int) const;
    void deleteBook(int);
    vector<Book> getTheHightestRateBook() const;
    vector<Book> getBookForAuthor(User &);
    Book operator[](int);
    friend ostream &operator<<(ostream &, BookList &);
    ~BookList();
};

#endif // BOOKSLIST_H_INCLUDED

