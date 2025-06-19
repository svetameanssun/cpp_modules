/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:40:08 by stitovsk          #+#    #+#             */
/*   Updated: 2025/06/19 12:40:09 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void HumanB::attack(void){
    
    if (weaponB != NULL) { // Check if weapon exists before attacking
        std::cout << name << " attacks with their " << weaponB->getType() << std::endl;
    } else {
        std::cout << name << " has no weapon to attack with!" << std::endl;
    }
}

void HumanB::setWeapon(Weapon &weaponType){
    weaponB = &weaponType;
}