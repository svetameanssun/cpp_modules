/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:21:39 by stitovsk          #+#    #+#             */
/*   Updated: 2025/06/26 10:24:21 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Unnamed") {
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
    std::cout << "ScavTrap " << getName() << " constructed (default)\n";
}

ScavTrap::ScavTrap(const std::string& n) : ClapTrap(n) {
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
    std::cout << "ScavTrap " << getName() << " constructed\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap " << getName() << " copied\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    ClapTrap::operator=(other);
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << getName() << " destroyed\n";
}

void ScavTrap::attack(const std::string& target) {
    int hp = getHitPoints();
    int ep = getEnergyPoints();
    if (hp <= 0 || ep <= 0) {
        std::cout << "ScavTrap " << getName() << " can't attack.\n";
        return;
    }
    std::cout << "ScavTrap " << getName() << " violently attacks " << target
              << ", inflicting " << getAttackDamage() << " points of damage!\n";
    ep--;
    setEnergyPoints(ep);
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode!\n";
}
