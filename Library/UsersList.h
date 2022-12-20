#ifndef USERSLIST_H_INCLUDED
#define USERSLIST_H_INCLUDED

#include "Users.h"

class UsersList{
  private:
    User *users;
    int capacity;
    int usersCount;
  public:
    UsersList();
    UsersList(int);
    UsersList(const UsersList &);
    int getUsersCount() const;
    void addUser(User &);
    User* searchUser(string) const;
    User *searchUser(int) const;
    void deleteUser(int);
    friend ostream &operator<<(ostream &, UsersList &);
    ~UsersList();
};


#endif // USERSLIST_H_INCLUDED
