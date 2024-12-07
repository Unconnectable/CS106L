/*
 * CS106L Assignment 5: TreeBook
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

#include <iostream>
#include <string>

class User
{
public:
  User(const std::string& name);
  void add_friend(const std::string& name);
  std::string get_name() const;
  size_t size() const;
  void set_friend(size_t index, const std::string& name);

  /** 
   * STUDENT TODO:
   * Your custom operators and special member functions will go here!
   */
  friend std::ostream& operator << (std::ostream& out,const User& usr);
  
  ~User();
  User(const User& user);
  User& operator=(const User& user);

  //delete the following functions
  User(User&& user) = delete;
  User& operator=(User&& user) = delete;

  friend User &operator+=(User &user1,User &user2);
  friend bool operator<(const User &user1, const User &user2);

  //friend User& operator+=(User& user1,User& user2);
  //friend bool operator<(const User& user1, const User& user2);

private:
  std::string _name;
  std::string* _friends;
  size_t _size;
  size_t _capacity;
};