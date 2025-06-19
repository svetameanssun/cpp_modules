/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 20:11:37 by stitovsk          #+#    #+#             */
/*   Updated: 2025/06/19 22:59:24 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
    Harl myHarl;

    std::cout << "--- Harl is complaining about DEBUG ---" << std::endl;
    myHarl.complain("DEBUG");

    std::cout << "--- Harl is complaining about INFO ---" << std::endl;
    myHarl.complain("INFO");

    std::cout << "--- Harl is complaining about WARNING ---" << std::endl;
    myHarl.complain("WARNING");

    std::cout << "--- Harl is complaining about ERROR ---" << std::endl;
    myHarl.complain("ERROR");

    std::cout << "--- Harl is complaining about UNKNOWN ---" << std::endl;
    myHarl.complain("UNKNOWN");

    std::cout << "--- Harl is complaining about 'INVALID' ---" << std::endl;
    myHarl.complain("INVALID");

    return 0;
}