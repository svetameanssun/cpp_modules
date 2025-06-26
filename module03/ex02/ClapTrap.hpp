#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
 public:
  ClapTrap();
  ClapTrap(const std::string& name);
  ClapTrap(const ClapTrap& other);
  ClapTrap& operator=(const ClapTrap& other);
  ~ClapTrap();

  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  std::string getName() const;
  int getHitPoints() const;
  int getEnergyPoints() const;
  int getAttackDamage() const;

  void setHitPoints(unsigned int hp);
  void setEnergyPoints(unsigned int ep);
  void setAttackDamage(unsigned int ad);

 private:
  std::string name;
  int hitPoints;
  int energyPoints;
  int attackDamage;
};

#endif
