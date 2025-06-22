/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:22:26 by stitovsk          #+#    #+#             */
/*   Updated: 2025/06/22 23:35:40 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
    this->myBrain =  new Brain();
    std::cout << "Cat has been created\n";
}

Cat::Cat(const Cat& other) : Animal(other) {
    this->type = other.type;
    this-> myBrain = new Brain(*other.myBrain); // deep copy;
    std::cout << "Cat has been copied\n";
}

Cat& Cat::operator=(const Cat& other) {
    if(this != &other) {
        Animal::operator=(other);
        this->type = other.type;
        delete(this->myBrain);
        this->myBrain = new Brain(*other.myBrain);
    }
    std::cout << "Cat has been assigned\n";
    return (*this);
}

Cat::~Cat() {
    delete(this->myBrain);
    std::cout << "Cat has been destroyed\n";
}

void Cat::makeSound(void) const {
    std::cout << "'Meow-meow!' -- *meowing*\n";
}

void Cat::setIdea(int index, const std::string& idea) {
    if(index >= 0 && index < 100)
        myBrain->ideas[index] = idea;
}

std::string Cat::getIdea(int index) const {
    if(index >= 0 && index < 100)
        return myBrain->ideas[index];
    return "";
}