/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:21:26 by stitovsk          #+#    #+#             */
/*   Updated: 2025/06/26 10:15:34 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Unnamed"){
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
    std::cout << "FragTrap " << getName() << " constructed (default)\n";
}

FragTrap::FragTrap(const std::string& n) : ClapTrap(n){
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
    std::cout << "FragTrap " << getName() << " constructed\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other){
    std::cout << "FragTrap " << getName() << " copied\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other){
    ClapTrap::operator=(other);
    return (*this);
}

FragTrap::~FragTrap(){
    std:: cout << "FragTrap " << getName() << " is deleted\n";
}

void FragTrap::highFivesGuys(void){
    std:: cout << "FragTrap " << getName() << " displays a positive high-fives request on the standard output\n";
}