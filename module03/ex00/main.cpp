/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:20:51 by stitovsk          #+#    #+#             */
/*   Updated: 2025/06/22 21:20:52 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    ClapTrap robot("Bender");

    robot.attack("a box");
    robot.takeDamage(5);
    robot.beRepaired(3);
    robot.takeDamage(10); // should "die"
    robot.attack("a crate"); // should not work
    robot.beRepaired(5);     // should not work

    return 0;
}
