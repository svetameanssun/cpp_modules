/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 00:45:52 by stitovsk          #+#    #+#             */
/*   Updated: 2025/06/19 00:45:53 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    if(N <= 0) {
        std::cerr << "error: wrong number\n";
        return NULL;
    }
    Zombie *horde = new Zombie[N];

    for(int i = 0; i < N; ++i) {
        std::ostringstream oss;
        oss << i;
        std::string str = oss.str();
        horde[i].setName(name + str);
    }

    return horde;
}