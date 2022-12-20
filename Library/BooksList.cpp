#include "BooksList.h"

BookList::BookList() : BookList(0){ }

BookList::BookList(int capacity) : capacity(capacity){
  books = new Book[capacity];
  bookCount = 0;
}

BookList::BookList(const BookList & book){
  capacity = book.capacity;
  books = new Book[capacity];
  bookCount = book.bookCount;
}
int BookList::getBookCount() const{
  return bookCount;
}

void BookList::addBook(const Book & book){
  if(bookCount < capacity){
    books[bookCount] = book;
    bookCount++;
    cout << "Book Added\n";
  }
  else {
    cout << "No Capacity\n";
  }
}

Book *BookList::searchBook(string bookTitle) const{
  for (int i = 0; i < bookCount;i++){
    if(bookTitle == books[i].getTitle()){
      return &books[i];
    }
  }
  return nullptr;
}

Book *BookList::searchBook(int id) const{
  for (int i = 0; i < bookCount;i++){
    if(id == books[i].getId()){
      return &books[i];
    }
  }
  return nullptr;
}

void BookList::deleteBook(int id){
  for (int i = 0; i < bookCount;i++){
    if(id == books[i].getId()){
      while(i<bookCount - 1){
        books[i] = books[i + 1];
        i++;
      }
      bookCount--;
      cout << "Book Deleted. \n";
      break;
    }
  }
  cout << "Not Found Book to delete \n";
return;
}

vector<Book> BookList::getTheHightestRateBook() const{
  double maxRate = -1.0;
  for (int i = 0; i < bookCount;i++){
    maxRate = max(maxRate, books[i].getAverageRating());
  }
  vector<Book>BooksHaveHightRate;
  for (int i = 0; i < bookCount;i++){
    if(maxRate == books[i].getAverageRating() && maxRate > 0){
      BooksHaveHightRate.push_back(books[i]);
    }
  }
  return BooksHaveHightRate;
}

vector<Book> BookList::getBookForAuthor(User & Author){
  vector<Book> AuthorSBook;
  for (int i = 0; i < bookCount;i++){
    if(Author == books[i].getAuthor()){
      AuthorSBook.push_back(books[i]);
    }
  }
  return AuthorSBook;
}

Book BookList::operator[](int pos){
  if(pos > 0 && pos <= capacity){
    return books[pos - 1];
  }
  else{
    return Book();
  }
}


ostream &operator<<(ostream &output, BookList &books){
  for (int i = 1; i <= books.bookCount;i++){
    output << books[i];
  }
  return output;
}

BookList::~BookList(){
  delete books;
}
