#include <bits/stdc++.h>
#include <iostream>
#include "Users.h"
#include "Book.h"
#include "UsersList.h"
#include "BooksList.h"
using namespace std;
void BooksList(),UserList(),getBook(),AddUsers(),AddBooks(),AddRate(),SearchUser(),SearchBook();
void DeleteUsers(),DeleteBooks(),DisplayUsers(),DisplayBooks(),getBookForAuthor(),BookEdit(Book & book);
void UserEdit(User & user),getTheHightestRateBook();
//  Do -> print author instead of user in class book if has author
UsersList *users;
BookList *books;
void MainPage(){
    cout << "Select one of the following choices:\n";
    cout << "1- Book List\n";
    cout << "2- Users List\n";
    cout << "3- Exit\n";
    cout << "Choose Number Don't only any thing anther number consider wrong :)    ";
    string s;
    cin >> s;
    if(s=="1") BooksList();
    else if(s=="2") UserList();
    else if(s=="3")return;
    else {
        cout << "Invalid Case Try again\n";
        MainPage();
    }
}
void UserList(){
    cout << "({  Users List  })\n";
    cout << "  1- Create users and add them to users list\n";
    cout << "  2- Delete users and remove them from users list\n";
    cout << "  3- Search User\n";
    cout << "  4- Display all users\n";
    cout << "  5- Edit Data of user\n";
    cout << "  6- Return back\n";
    cout << "  7- To Close Program write ( -1 )\n";
    cout << "Choose Number Don't only any thing anther number consider wrong :)    ";
    string s;
    cin >> s;
    if(s=="1") AddUsers();
    else if(s=="2") DeleteUsers();
    else if(s=="3") SearchUser();
    else if(s=="4") DisplayUsers();
    else if(s=="5") {
        cout << "\nEnter The name : ";
        string t;
        cin >> t;
        if(users->searchUser(t) == nullptr){
            cout << "User not Found\n";
            MainPage();
        }
        else{
            UserEdit(*users->searchUser(t));
        }
    }
    else if(s=="6") MainPage();
    else if(s=="-1")exit(1);
    else {
        cout << "Invalid Case Try Again\n";
        UserList();
    }
    return;
}
void AddUsers(){
    cout << "Enter Number of Users That Will Add :    ";
    int num;
    cin >> num;
    users = new UsersList(num);
    User u1;
    for (int i = 0; i < num;i++){
        cout << i+1 << "- ";
        cin >> u1;
        users->addUser(u1);
    }
    cout << "To return 0 - To Close Write -1.    ";
    cin >> num;
    if(num==0){
        UserList();
    }
    else MainPage();
}
User SearchUserByName(){
    cout << "\nEnter The name :     ";
    string s;
    cin >> s;
    int n;
    if(users->searchUser(s) == nullptr){
        cout << "User not Found\n";
        cout << "To repeat the operation write 2 - To return 0  - To Close Write -1.    ";
        cin >> n;
    }
    else {
        cout << *users->searchUser(s);
        cout << "If wanted to edit user info 1 - To repeat the operation write 2 - To return 0  - To Close Write -1.    ";
        cin >> n;
        if(n==1){
            UserEdit(*users->searchUser(s));
            return User();
        }
    }
    if(n==0) UserList();
    else if(n==2) SearchUserByName();
    else MainPage();
}
User SearchUserById(){
    cout << "\nEnter The ID :    ";
    int id,n;
    cin >> id;
    if(users->searchUser(id) == nullptr){
        cout << "User not Found\n";
        cout << "To repeat the operation write 2 - To return 0  - To Close Write -1.    ";
        cin >> n;
    }
    else {
        cout << *users->searchUser(id);
        cout << "If wanted to edit user info 1 - To repeat the operation write 2 - To return 0  - To Close Write -1.    ";
        cin >> n;
        if(n==1){
            UserEdit(*users->searchUser(id));
            return User();
        }
    }
    if(n==0) UserList();
    else if(n==2) SearchUserById();
    else MainPage();
}
void SearchUser(){
    cout << "Search By ( Name , ID ), if you want return write 0.    ";
    string s;
    cin >> s;
    if(s=="Name") SearchUserByName();
    else if(s=="ID") SearchUserById();
    else if(s=="0") UserList();
    else {
        cout << "Invalid Case Try Again\n";
        SearchUser();
    }
}
void DeleteUsers(){
    cout << "\nEnter ID for User to delete :";
    int id;
    cin >> id;
    users->deleteUser(id);
    cout << "To return 0 -  To repeat the operation write 2  - To Close Write -1.    ";
    cin >> id;
    if(id==0) UserList();
    else if(id==2) DeleteUsers();
    else MainPage();
}
void DisplayUsers(){
    if(users->getUsersCount() == 0){
        cout << "Not Add Users to Show.\n";
    }
    else {
        cout << "({  Display All Users  })\n";
        cout << *users;
    }
    int x;
    cout << "To return 0 - To Close Write -1.    ";
    cin >> x;
    if(x==0) UserList();
    else MainPage();
}
void UserEdit(User & user){
    cout << "You can change : \n";
    cout << "( Name - Age - Password - Email ).    ";
    string s;
    cin >> s;
    if(s=="1" || s=="Name"){
        cout << "Enter Name :    ";
        string name;
        cin >> name;
        user.setName(name);
        cout << "Print User Info ( YES / NO ).    ";
        cin >> s;
        if( s== "1" || s == "YES"){
            cout << user;
        }
        cout << "To repeat the operation write 2 - To return 0  - To Close Write -1.    ";
        cin >> s;
        if(s=="0") UserList();
        else if(s=="2") UserEdit(user);
        else MainPage();
    }
    else if(s=="2" || s=="Age"){
        int age;
        cout << "Enter Age :    " ;
        cin >> age;
        user.setAge(age);
        cout << "Print User Info ( YES / NO ).    ";
        cin >> s;
        if(s=="1" || s == "YES"){
            cout << user;
        }
        cout << "To repeat the operation write 2 - To return 0  - To Close Write -1.    ";
        cin >> s;
        if(s=="0") UserList();
        else if(s=="2") UserEdit(user);
        else MainPage();
    }
    else if(s=="3"|| s=="Password"){
        string password;
        cout << "Enter Password :    " ;
        cin >> password;
        user.setPsseord(password);
        cout << "Print User Info ( YES / NO ).    ";
        cin >> s;
        if(s=="1" || s == "YES"){
            cout << user;
        }
        cout << "To repeat the operation write 2 - To return 0  - To Close Write -1.    ";
        cin >> s;
        if(s=="0") UserList();
        else if(s=="2") UserEdit(user);
        else MainPage();
    }
    else if (s == "4" || s == "Email"){
        string email;
        cout << "Enter Email :    ";
        cin >> email;
        user.setEmail(email);
        cout << "Print User Info ( YES / NO ).    ";
        cin >> s;
        if( s=="1" || s == "YES"){
            cout << user;
        }
        cout << "To repeat the operation write 2 - To return 0  - To Close Write -1.    ";
        cin >> s;
        if(s=="0") UserList();
        else if(s=="2") UserEdit(user);
        else MainPage();
    }
    else {
        cout << "Invalid Case Try Again\n";
        UserEdit(user);
    }
}
void BooksList(){
    cout << "({  Books List  })\n";
    cout << "  1- Create Books and add them to Books list\n";
    cout << "  2- Delete Books and remove them from Books list\n";
    cout << "  3- Search Book\n";
    cout << "  4- Edit Book\n";
    cout << "  5- Get The Hightest Rate Book\n";
    cout << "  6- Display all Book\n";
    cout << "  7- Get Book For Author\n";
    cout << "  8- Add Rate To Book\n";
    cout << "  9- Return back\n";
    cout << "  10- To Close Program write ( -1 )\n";
    cout << "Choose Number Don't only any thing anther number consider wrong :)    ";
    string s;
    cin >> s;
    if(s=="1") AddBooks();
    else if(s=="2") DeleteBooks();
    else if(s=="3") SearchBook();
    else if(s=="4"){
        cout << "\nEnter The title : ";
        string s;
        cin >> s;
        if(books->searchBook(s) == nullptr){
            cout << "Book not Found\n";
            MainPage();
        }
        else{
            BookEdit(*books->searchBook(s));
        }
    }
    else if(s=="5") getTheHightestRateBook();
    else if(s=="6") DisplayBooks();
    else if(s=="7") getBookForAuthor();
    else if(s=="8") AddRate();
    else if(s=="9") MainPage();
    else if(s=="-1") exit(1);
    else {
        cout << "Invalid Case Try Again\n";
        BooksList();
    }
    return;
}
void AddBooks(){
    cout << "Enter Number of Books That Will Add :\n";
    int num;
    cin >> num;
    books = new BookList(num);
    Book b1;
    for (int i = 0; i < num;i++){
        cout << i+1 << "- ";
        cin >> b1;
        cout << "Book Has Author ( YES / NO ). ( In first you must add him in User List ) :    ";
        string s;
        cin >> s;
        if(s=="1" || s=="YES"){
            cout << "Enter Author name:    ";
            string s;
            cin >> s;
            b1.setAuthor(*users->searchUser(s));
        }
        books->addBook(b1);
    }
    cout << "To return 0 - To Close Write -1.    ";
    cin >> num;
    if(num==0){
        BooksList();
        return ;
    }
    else MainPage();
}
void AddRate(){
    cout << "Enter Title of Book :    ";
    string s;
    cin >> s;
    if(books->searchBook(s) == nullptr){
        cout << "Book not Found\n";
        cout << "To repeat the operation write 2 - To return 0  - To Close Write -1\n";
        cin >> s;
    }
    else{
        cout << "Enter Rate (1 : 5) :";
        int n;
        cin >> n;
        if(n>0 && n<6){
            books->searchBook(s)->rateBook(n);
            cout << "To return 0  - To Close Write -1\n";
            cin >> s;
        }
        else {
            cout << "Invalid Input\n";
            cout << "To repeat the operation write 2 - To return 0  - To Close Write -1\n";
            cin >> s;
        }
    }
    if(s=="0") BooksList();
    else if(s=="2") AddRate();
    else MainPage();
}
void DeleteBooks(){
    cout << "\nEnter ID for Book to delete :";
    int id,n;
    cin >> id;
    books->deleteBook(id);
    cout << "To return 0 -  To repeat the operation write 2  - To Close Write -1\n";
    cin >> n;
    if(n==0) BooksList();
    else if(n==2) DeleteBooks();
    else MainPage();
}
void SearchBookByName(){
    cout << "\nEnter The Title :    ";
    string s;
    cin >> s;
    int n;
    if(books->searchBook(s) == nullptr){
        cout << "Book not Found\n";
        cout << "To repeat the operation write 2 - To return 0  - To Close Write -1.    ";
        cin >> n;
    }
    else {
        cout << *books->searchBook(s);
        cout << "If wanted to edit user info 1 - To repeat the operation write 2 - To return 0  - To Close Write -1.    ";
        cin >> n;
        if(n==1){
            BookEdit(*books->searchBook(s));
            return;
        }
    }
    if(n==0) BooksList();
    else if(n==2) SearchBookByName();
    else MainPage();
}
void SearchBookById(){
    cout << "\nEnter The ID : ";
    int id;
    cin >> id;
    int n;
    if(books->searchBook(id) == nullptr){
        cout << "Book not Found\n";
        cout << "To repeat the operation write 2 - To return 0  - To Close Write -1.    ";
        cin >> n;
    }
    else {
        cout << *books->searchBook(id);
        cout << "If wanted to edit user info 1 - To repeat the operation write 2 - To return 0  - To Close Write -1.    ";
        cin >> n;
        if(n==1){
            BookEdit(*books->searchBook(id));
            return;
        }
    }
    if(n==0) BooksList();
    else if(n==2) SearchBookById();
    else MainPage();
}
void SearchBook(){
    cout << "Search By ( Name , ID ), if you want return write 0\n";
    string s;
    cin >> s;
    if(s=="Name") SearchBookByName();
    else if(s=="ID") SearchBookById();
    else if(s=="0") BooksList();
    else {
        cout << "Invalid Case Try Again\n";
        SearchBook();
    }
}
void DisplayBooks(){
    if(books->getBookCount() == 0){
        cout << "Not Add Books to Show.\n";
    }
    else {
        cout << "({  Display All Books  })\n";
        cout << *books;
    }
    int x;
    cout << "To return 0 - To Close Write -1.    ";
    cin >> x;
    if(x==0) BooksList();
    else
        MainPage();
}

void getTheHightestRateBook(){
    vector<Book> booksWithHeightRate = books->getTheHightestRateBook();
    for (int i = 0; i < booksWithHeightRate.size();i++){
        cout << i + 1 << "- ";
        cout << booksWithHeightRate[i];
    }
    if(booksWithHeightRate.empty()){
        cout << "Not Added Rate for Books\n";
    }
    int x;
    cout << "To return 0 - To Close Write -1.    ";
    cin >> x;
    if(x==0) BooksList();
    else MainPage();
}
void getBookForAuthor(){
    cout << "Enter Name for author :    ";
    string s;
    cin >> s;
    if(users->searchUser(s) == nullptr){
        cout << "This Author Not added";
    }
    else{
        vector<Book> AuthorsBooks = books->getBookForAuthor(*users->searchUser(s));
        for (int i = 0; i < AuthorsBooks.size();i++){
            cout << i + 1 << "- ";
            cout << AuthorsBooks[i];
        }
        if(AuthorsBooks.empty()){
            cout << "Not Found Book for Author\n";
        }
    }
    int x;
    cout << "To return 0 - To Close Write -1.    ";
    cin >> x;
    if(x==0) BooksList();
    else
        MainPage();
}
void BookEdit(Book & book){
    cout << "You can change : \n";
    cout << "( Title - ISBN - Category - Author ).    ";
    string s;
    cin >> s;
    if(s=="1" || s=="Title"){
        cout << "Enter Title :    " ;
        string Title;
        cin >> Title;
        book.setTitle(Title);
        cout << "Print Book Info ( YES / NO ).    ";
        cin >> s;
        if( s=="1" || s == "YES"){
            cout << book;
        }
        cout << "To repeat the operation write 2 - To return 0  - To Close Write -1.    ";
        cin >> s;
        if(s=="0") BooksList();
        else if(s=="2") BookEdit(book);
        else MainPage();
    }
    else if(s=="2" || s=="ISBN"){
        string ISBN;
        cout << "Enter ISBN :    " ;
        cin >> ISBN;
        book.setISBN(ISBN);
        cout << "Print Book Info ( YES / NO ).    ";
        cin >> s;
        if( s=="1" || s == "YES"){
            cout << book;
        }
        cout << "To repeat the operation write 2 - To return 0  - To Close Write -1.    ";
        cin >> s;
        if(s=="0") BooksList();
        else if(s=="2") BookEdit(book);
        else MainPage();
    }
    else if(s=="3"|| s=="Category"){
        string Category;
        cout << "Enter Category :    " ;
        cin >> Category;
        book.setCategory(Category);
        cout << "Print Book Info ( YES / NO ).    ";
        cin >> s;
        if( s=="1" || s == "YES"){
            cout << book;
        }
        cout << "To repeat the operation write 2 - To return 0  - To Close Write -1.    ";
        cin >> s;
        if(s=="0") BooksList();
        else if(s=="2") BookEdit(book);
        else MainPage();
    }
    else if (s == "4" || s == "Author"){
        User Author;
        cout << "Enter Author :    " ;
        cin >> Author;
        book.setAuthor(Author);
        cout << "Print Book Info ( YES / NO ).    ";
        cin >> s;
        if( s=="1" || s == "YES"){
            cout << book;
        }
        cout << "To repeat the operation write 2 - To return 0  - To Close Write -1.    ";
        cin >> s;
        if(s=="0") BooksList();
        else if(s=="2") BookEdit(book);
        else MainPage();
    }
    else {
        cout << "Invalid Case Try Again\n";
        BookEdit(book);
    }
}
int main(){
    MainPage();
    return 0;
}
