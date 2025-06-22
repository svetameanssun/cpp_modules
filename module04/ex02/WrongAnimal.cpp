/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:22:48 by stitovsk          #+#    #+#             */
/*   Updated: 2025/06/22 23:37:30 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal constructed.\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
    std::cout << "WrongAnimal copied.\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if(this != &other)
        type = other.type;
    std::cout << "WrongAnimal assigned.\n";
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destroyed.\n";
}

void WrongAnimal::makeSound() const {
    std::cout << "Some wrong animal sound.\n";
}

const std::string WrongAnimal::getType() const {
    return type;
}
