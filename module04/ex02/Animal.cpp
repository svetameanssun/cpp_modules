/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:22:23 by stitovsk          #+#    #+#             */
/*   Updated: 2025/06/22 23:35:33 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
    std::cout << "I am just an animal.\n";
}

Animal::Animal(const Animal& other): type(other.type) {
    std::cout << "Animal " << type << " copied\n";
};

Animal& Animal::operator=(const Animal& other) {
    if(this != &other) {
        type = other.type;
    }
    std::cout << "Animal " << type << " assigned\n";
    return (*this);
}

Animal::~Animal(void) {
    std::cout << "Animal " << type << " destroyed\n";
}


const std::string Animal::getType(void) const {
    return (type);
}