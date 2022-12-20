#include "Book.h"
int Book::count = 0;

Book::Book() : Book("Unknown", "Unknown" ,"Unknown",0.0){ };

Book::Book(string title,string isbn,string category,double averageRating)
    : title(title) , isbn(isbn) , category(category),averageRating(averageRating){
    count++;
    id = count;
    numRate = 0;
    sumRate = 0;
}

Book::Book(const Book& book){
    title = book.title;
    isbn = book.isbn;
    category = book.category;
    id = book.id;
    averageRating = book.averageRating;
    setAuthor(book.author);
}

void Book::setTitle(string title){
    this->title = title;
}

string Book::getTitle()const{
    return title;
}

void Book::setISBN(string isbn){
    this->isbn = isbn;
}

string Book::getISBN()const{
    return isbn;
}

void Book::setCategory(string category){
    this->category = category;
}

string Book::getCategory()const{
    return category;
}

void Book::setId(int id){
    this->id = id;
}

int Book::getId()const{
    return id;
}

void Book::setAuthor(const User& user){
    author = user;
}

User Book::getAuthor()const{
    return author;
}

double Book::getAverageRating()const{
    return averageRating;
}

void Book::rateBook(double rate){
    numRate++;
    sumRate+=rate;
    averageRating = sumRate / numRate;
    cout << "Done Rating\n";
}

void Book::operator=(const Book& book){
    title = book.title;
    isbn = book.isbn;
    category = book.category;
    author = book.author;
    numRate = book.numRate;
    sumRate = book.sumRate;
    averageRating = book.averageRating;
}

bool Book::operator==(const Book& book){
    return tie(book.title,book.isbn,book.id,book.category) == tie(title,isbn,id,category);
}

istream & operator >> (istream & input,Book& book){
    cout << "Enter Book info\nEnter Book Title : " ;
    input >> book.title ;
    cout << "Enter Book Category : " ;
    input >> book.category ;
    cout << "Enter Book ISBN : " ;
    input >> book.isbn ;
    return input;
}

ostream & operator << (ostream &output,const Book& book){
    output << "Book Info \n" <<
        "\tBook Title : " << book.title <<
        "\n\tBook Category : " << book.category <<
        "\n\tBook ID : " << book.id <<
        "\n\tBook ISBN : " << book.isbn <<
        "\n\tBook Average Rating : " << book.averageRating <<
        "\n\tBook Author : " ;
        if(book.author.getName() == "Unknown"){
            output << "None Found Author\n";
        }
        else {
            output << '\n' << book.author ;
        }
    return output;
}

Book::~Book(){ }
