/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 00:45:41 by stitovsk          #+#    #+#             */
/*   Updated: 2025/06/19 00:45:42 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name("Unnamed Zombie") {
    std::cout << "Zombie " << this->name << " created (by default)" << std::endl;
}

Zombie::Zombie(std::string name) : name(name) {
    std::cout << "Zombie " << this->name << " created!" << std::endl;
}

Zombie::~Zombie() {
    std::cout << this->name << ": Arrrgh... *dying*" << std::endl;
}

void Zombie::announce() {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
void Zombie::setName(std::string newName) {
    this->name = newName;
}