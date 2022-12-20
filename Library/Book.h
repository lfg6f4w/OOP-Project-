#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED
// for composition (has a)
#include "Users.h"
class Book{
private:
    string title;
    string isbn;
    string category;
    int id;
    int numRate;
    double averageRating;
    double sumRate;
    User author;
    bool hasAuthor;
public:
    static int count;
    Book();
    Book(string,string,string,double);
    Book(const Book&);
    void setTitle(string);
    string getTitle()const;
    void setISBN(string);
    string getISBN()const;
    void setCategory(string);
    string getCategory()const;
    void setId(int);
    int getId()const;
    void setAuthor(const User&);
    User getAuthor() const;
    double getAverageRating()const;
    void rateBook(double);
    bool operator==(const Book&);
    void operator=(const Book&);
    friend istream & operator >> (istream &,Book&);
    friend ostream & operator << (ostream &,const Book&);
    ~Book();
};

#endif // BOOK_H_INCLUDED
