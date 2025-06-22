/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:21:02 by stitovsk          #+#    #+#             */
/*   Updated: 2025/06/22 21:21:03 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
    std::cout << "=== Creating ScavTrap ===\n";
    ScavTrap s1("Serena");

    std::cout << "\n=== Performing actions ===\n";
    s1.attack("Bandit");
    s1.takeDamage(30);
    s1.beRepaired(20);
    s1.guardGate();

    std::cout << "\n=== Copy test ===\n";
    ScavTrap s2 = s1;

    std::cout << "\n=== End of main ===\n";
    return 0;
}
