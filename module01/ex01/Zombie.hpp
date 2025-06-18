#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <sstream>

class Zombie {
  private:
    std::string name;
  public:
    Zombie(void);
    Zombie(std::string name);
    void announce(void);
    void setName(std::string newName);
    ~Zombie();
};

Zombie* zombieHorde(int N, std::string name);

#endif