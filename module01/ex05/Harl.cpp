#include "Harl.hpp"
#include <iostream>

void Harl::debug( void ){
    std::cout << "\033[1m\033[1;36m[ DEBUG ]:\033[0m\n";
}

void Harl::info( void ){
    std::cout << "\033[1m\033[1;35m[ INFO ]:\033[0m\n";
}

void Harl::warning( void ){
    std::cout << "\033[1m\033[1;34m[ WARNING ]:\033[0m\n";
}

void Harl::error( void ){
    std::cout << "\033[1m\033[1;31m[ ERROR ]:\033[0m\n";
}

Harl::Harl() {
    levelFunctions["DEBUG"] = &Harl::debug;
    levelFunctions["INFO"] = &Harl::info;
    levelFunctions["WARNING"] = &Harl::warning;
    levelFunctions["ERROR"] = &Harl::error;
}

// Реализация публичной функции complain
void Harl::complain(std::string level) {

    std::map<std::string, void (Harl::*)(void)>::iterator it = levelFunctions.find(level);

    if (it != levelFunctions.end()) {
        (this->*(it->second))();
    } else {
        std::cout << "[ UNKNOWN LEVEL ]" << std::endl;
        std::cout << "Извините, я не знаю, как жаловаться на уровень '" << level << "'." << std::endl;
        std::cout << std::endl;
    }
}

