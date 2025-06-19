/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 20:11:31 by stitovsk          #+#    #+#             */
/*   Updated: 2025/06/19 22:59:55 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void) {
    std::cout << "\033[1m\033[1;36m[ DEBUG ]:\033[0m\n";
}

void Harl::info(void) {
    std::cout << "\033[1m\033[1;32m[ INFO ]:\033[0m\n";
}

void Harl::warning(void) {
    std::cout << "\033[1m\033[1;93m[ WARNING ]:\033[0m\n";
}

void Harl::error(void) {
    std::cout << "\033[1m\033[1;31m[ ERROR ]:\033[0m\n";
}

Harl::Harl() {
    levelFunctions["DEBUG"] = &Harl::debug;
    levelFunctions["INFO"] = &Harl::info;
    levelFunctions["WARNING"] = &Harl::warning;
    levelFunctions["ERROR"] = &Harl::error;
}

void Harl::complain(std::string level) {

    std::map<std::string, void (Harl::*)(void)>::iterator it = levelFunctions.find(level);

    if(it != levelFunctions.end()) {
        (this->*(it->second))();
    } else {

        std::cout << "\033[1;35m[ UNKNOWN LEVEL ]\033[0m" << std::endl;
        std::cout << "\033[1;35mSorry, I do not know how to complain about '" << level << "'." << "\033[0m" << std::endl;
        std::cout << std::endl;
    }
}

