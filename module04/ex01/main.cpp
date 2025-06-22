/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:22:34 by stitovsk          #+#    #+#             */
/*   Updated: 2025/06/22 23:38:11 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "=== Creating Animals Array ===\n";
    Animal* animalArr[10];

    for(int i = 0; i < 5; ++i)
        animalArr[i] = new Dog();
    for(int i = 5; i < 10; ++i)
        animalArr[i] = new Cat();

    std::cout << "=== Deleting Animals Array ===\n";
    for(int i = 0; i < 10; ++i)
        delete animalArr[i];

    std::cout << "\n=== Deep Copy Test ===\n";
    Dog original;
    original.setIdea(0, "Chase the cat");
    Dog copy(original); // Copy constructor
    Dog assigned;
    assigned = original; // Assignment operator

    std::cout << "\nOriginal's idea: " << original.getIdea(0) << "\n";
    std::cout << "Copy's idea:     " << copy.getIdea(0) << "\n";
    std::cout << "Assigned's idea: " << assigned.getIdea(0) << "\n";

    // Modify the original to test independence
    original.setIdea(0, "Eat food");

    std::cout << "\nAfter modifying the original:\n";
    std::cout << "Original's idea: " << original.getIdea(0) << "\n";
    std::cout << "Copy's idea:     " << copy.getIdea(0) << "\n";        // Should remain unchanged
    std::cout << "Assigned's idea: " << assigned.getIdea(0) << "\n";    // Should remain unchanged

    return 0;
}

