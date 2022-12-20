#include "Users.h"
int User::count = 0;
User::User(): User( "Unknown" , 0 , "Unknown" , "Unknown" ){ }
User::User(string name, int age,string password,string email)
    : name(name), age(age) , id(id), password(password), email(email){
    count++;
    id = count;
}

User::User(const User& user){
    name = user.name;
    age = user.age;
    id = user.id;
    password = user.password;
    email =  user.email;
    count++;
}

bool User::operator==(const User& user){
    return tie(user.name,user.age,user.password,user.id,user.email) == tie(name,age,password,id,email);
}

void User::operator=(const User& user){
    name = user.name;
    email = user.email;
    age = user.age;
    password = user.password;
}

void User::setName(string name){
    this -> name = name;
}

string User::getName() const{
    return name;
}

void User::setPsseord(string password){
    this -> password = password;
}

string User::getPassword() const{
    return password;
}

void User::setEmail(string email){
    this -> email = email;
}

string User::getEmail() const{
    return email;
}

void User::setAge(int age){
    this -> age = age;
}

int User::getAge() const{
    return age;
}

void User::setId(int id){
    this -> id = id;
}

int User::getId() const{
    return id;
}

istream &operator >> (istream & input,User& user){
    cout << "Enter User info\n";
    cout << "\nUser name : ";
    input >> user.name;
    cout << "\nUser Age : ";
    input >> user.age;
    cout << "\nUser Email : ";
    input >> user.email;
    cout << "\nUser Password : ";
    input >> user.password;
    cout << '\n';
    return input;
}

ostream &operator << (ostream & output,const User& user){
    output << "The User info :"
    << "\n   User name : " << user.name
    << "\n   User Age : " << user.age
    << "\n   User ID : " << user.id
    << "\n   User Email : " << user.email
    << "\n   User Password : " << user.password << '\n';
    return output;
}
