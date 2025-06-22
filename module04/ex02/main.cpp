/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:22:34 by stitovsk          #+#    #+#             */
/*   Updated: 2025/06/22 23:37:20 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {

    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " says: ";
    j->makeSound();

    std::cout << i->getType() << " says: ";
    i->makeSound();

    delete j; // destructor Dog + Animal is called
    delete i; // destructor Dog + Animal is called
    
    std::cout << "-------------------\n";

    // Проверка WrongAnimal и WrongCat (без виртуальных функций)
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongAnimal->getType() << " says: ";
    wrongAnimal->makeSound();

    std::cout << wrongCat->getType() << " says: ";
    wrongCat->makeSound();  // Здесь вызовется WrongAnimal::makeSound, а не WrongCat::makeSound

    delete wrongAnimal;
    delete wrongCat;

    return 0;
}


