/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:22:30 by stitovsk          #+#    #+#             */
/*   Updated: 2025/06/22 23:34:00 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    this->type = "Dog";
    std::cout << "Dog has been created\n";
}

Dog::~Dog() {
    std::cout << "Dog has been destroyed\n";
}

Dog::Dog(const Dog&other) : Animal(other) {
    std::cout << "Dog copied\n";
}
Dog& Dog::operator=(const Dog &other) {
    Animal::operator=(other);
    return (*this);
}

void Dog::makeSound(void) const {
    std::cout << "'Woof-woof!' -- *barking*\n";
}