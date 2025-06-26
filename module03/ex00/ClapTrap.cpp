/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 23:30:33 by stitovsk          #+#    #+#             */
/*   Updated: 2025/06/26 09:42:00 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : name("Unnamed"), hitPoints(10), energyPoints(10), attackDamage(0) {
  std::cout << "ClapTrap " << name << " constructed!" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
  std::cout << "ClapTrap " << name << " constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : name(other.name),
      hitPoints(other.hitPoints),
      energyPoints(other.energyPoints),
      attackDamage(other.attackDamage) {
  std::cout << "ClapTrap " << name << " copied!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
  if (this != &other) {
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
  }
  std::cout << "ClapTrap " << name << " assigned!" << std::endl;
  return *this;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << name << " destructed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
  if (hitPoints <= 0) {
    std::cout << "ClapTrap " << name << " can't attack: no hit points left!"
              << std::endl;
    return;
  }
  if (energyPoints <= 0) {
    std::cout << "ClapTrap " << name << " can't attack: no energy left!"
              << std::endl;
    return;
  }
  std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
            << attackDamage << " points of damage!" << std::endl;
  energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (hitPoints <= 0) {
    std::cout << "ClapTrap " << name << " is already dead!" << std::endl;
    return;
  }
  hitPoints -= amount;
  if (hitPoints < 0) hitPoints = 0;
  std::cout << "ClapTrap " << name << " takes " << amount
            << " points of damage!"
            << " (HP left: " << hitPoints << ")" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (hitPoints <= 0) {
    std::cout << "ClapTrap " << name << " can't repair: already dead!"
              << std::endl;
    return;
  }
  if (energyPoints <= 0) {
    std::cout << "ClapTrap " << name << " can't repair: no energy left!"
              << std::endl;
    return;
  }
  hitPoints += amount;
  energyPoints--;
  std::cout << "ClapTrap " << name << " recovers " << amount << " hit points!"
            << " (HP: " << hitPoints << ", EP: " << energyPoints << ")"
            << std::endl;
}

std::string ClapTrap::getName() const { return name; }
int ClapTrap::getHitPoints() const { return hitPoints; }
int ClapTrap::getEnergyPoints() const { return energyPoints; }
int ClapTrap::getAttackDamage() const { return attackDamage; }
