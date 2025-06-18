/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:30:41 by stitovsk          #+#    #+#             */
/*   Updated: 2025/06/18 20:30:42 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    Zombie *pntrZombie = newZombie("newZmb");
    pntrZombie->announce();
    delete(pntrZombie);

    std::cout << std::endl;
    randomChump("chumpZombie");
}