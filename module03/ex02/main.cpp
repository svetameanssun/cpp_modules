/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:21:32 by stitovsk          #+#    #+#             */
/*   Updated: 2025/06/22 21:21:33 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap claptrap("Clapy");
    ScavTrap scavtrap("Scavy");
    FragTrap fragtrap("Fragy");

    claptrap.attack("Scavy");
    scavtrap.takeDamage(10);
    scavtrap.guardGate();
    scavtrap.attack("Fragy");
    fragtrap.takeDamage(20);
    fragtrap.beRepaired(15);
    fragtrap.attack("Scavy");
    scavtrap.takeDamage(30);
    fragtrap.highFivesGuys();
    return (0);
}
