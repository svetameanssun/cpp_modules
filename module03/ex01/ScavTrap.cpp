/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:21:14 by stitovsk          #+#    #+#             */
/*   Updated: 2025/06/26 10:11:35 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Unnamed") {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap (not ClapTrap)" << name << " is constructed (default)\n";
}

ScavTrap::ScavTrap(const std::string& n) : ClapTrap(n) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap (not ClapTrap)" << name << " is constructed\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap " << name << " copied\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    ClapTrap::operator=(other);
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap (not ClapTrap) " << name << " destroyed\n";
}

void ScavTrap::attack(const std::string& target) {
    if (hitPoints <= 0 || energyPoints <= 0) {
        std::cout << "ScavTrap " << name << " can't attack. Dead or tired!\n";
        return;
    }
    std::cout << "ScavTrap " << name << " violently attacks " << target
              << ", inflicting " << attackDamage << " points of damage!\n";
    energyPoints--;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode!\n";
}




