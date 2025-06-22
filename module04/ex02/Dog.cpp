/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:22:30 by stitovsk          #+#    #+#             */
/*   Updated: 2025/06/22 23:35:44 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    this->type = "Dog";
    this->myBrain =  new Brain();
    std::cout << "Dog has been created\n";
}

Dog::~Dog() {
    delete(this->myBrain);
    std::cout << "Dog has been destroyed\n";
}

Dog::Dog(const Dog&other) : Animal(other) {
    this->type = other.type;
    this->myBrain = new Brain(*other.myBrain);
    std::cout << "Dog copied\n";
}
Dog& Dog::operator=(const Dog &other) {
    if(this != &other) {
        Animal::operator=(other);
        this->type = other.type;
        delete this->myBrain;
        this->myBrain = new Brain(*other.myBrain);
    }
    std::cout << "Dog assigned\n";
    return (*this);
}

void Dog::makeSound(void) const {
    std::cout << "'Woof-woof!' -- *barking*\n";
}


void Dog::setIdea(int index, const std::string& idea) {
    if(index >= 0 && index < 100)
        myBrain->ideas[index] = idea;
}

std::string Dog::getIdea(int index) const {
    if(index >= 0 && index < 100)
        return myBrain->ideas[index];
    return "";
}
