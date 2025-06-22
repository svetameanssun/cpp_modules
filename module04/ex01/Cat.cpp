/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:22:26 by stitovsk          #+#    #+#             */
/*   Updated: 2025/06/22 21:22:27 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
    std::cout << "Cat has been created\n";
}

Cat::Cat(const Cat& other) : Animal(other){
    std::cout << "Cat has been copied\n";
}

Cat& Cat::operator=(const Cat& other){
    Animal::operator=(other);
    std::cout << "Cat has been assigned\n";
    return (*this);
}

Cat::~Cat(){
    std::cout << "Cat has been destroyed\n";
}

void Cat::makeSound(void) const {
    std::cout << "'Meow-meow!' -- *meowing*\n";
}