#ifndef USERS_H_INCLUDED
#define USERS_H_INCLUDED

#include <bits/stdc++.h>
using namespace std;

class User{
private:
    string name;
    int age;
    int id;
    string password;
    string email;

public:
    static int count;
    User();
    User(string,int,string ,string);
    User(const User& );
    void setAsAuthor(bool);
    bool getAsAuthor() const;
    bool operator==(const User& );
    void operator=(const User& );
    void setName(string);
    string getName() const;
    void setPsseord(string);
    string getPassword() const;
    void setEmail(string);
    string getEmail() const;
    void setAge(int);
    int getAge() const;
    void setId(int);
    int getId() const;
    friend istream &operator >> (istream &,User&);
    friend ostream &operator << (ostream &,const User&);
};

#endif // USERS_H_INCLUDED
