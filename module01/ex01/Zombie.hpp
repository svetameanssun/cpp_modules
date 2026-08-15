#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <sstream>
#include <string>

class Zombie {
 private:
  std::string name;

 public:
  Zombie(void);
  Zombie(std::string name);
  ~Zombie();
  void announce(void);
  void setName(std::string newName);
};

Zombie *zombieHorde(int N, std::string name);

#endif