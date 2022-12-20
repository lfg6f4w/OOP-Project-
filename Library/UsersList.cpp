#include "UsersList.h"

UsersList::UsersList() : UsersList(0){ }
UsersList::UsersList(int capacity) : capacity(capacity) {
  users = new User[capacity];
  usersCount = 0;
}
UsersList::UsersList(const UsersList & userList){
  this->capacity = userList.capacity;
  users = new User[capacity];
  usersCount = 0;
}
int UsersList::getUsersCount()const{
  return usersCount;
}
void UsersList::addUser(User &user){
  if(usersCount < capacity){
    users[usersCount] = user;
    usersCount++;
    cout << "User Added\n";
  }
  else {
    cout << "No Capacity\n";
  }
}
User* UsersList::searchUser(string name) const{
  for (int i = 0; i < usersCount;i++){
    if(name == users[i].getName()){
      return &users[i];
    }
  }
  return nullptr;
}
User* UsersList::searchUser(int id) const{
  for (int i = 0; i < usersCount;i++){
    if(id == users[i].getId()){
      return &users[i];
    }
  }
  return nullptr;
}
void UsersList::deleteUser(int id){
  for (int i = 0; i < usersCount;i++){
    if(id == users[i].getId()){
      while(i<usersCount - 1){
        users[i] = users[i + 1];
        i++;
      }
      usersCount--;
      cout << "User Deleted.\n";
      return;
    }
  }
  cout << "Not Found User to delete\n";
}
ostream &operator<<(ostream & output, UsersList & usersList){
  for (int i = 0; i < usersList.usersCount;i++){
    output << usersList.users[i];
  }
  return output;
}
UsersList::~UsersList(){
  delete users;
}
