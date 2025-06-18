/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:31:25 by stitovsk          #+#    #+#             */
/*   Updated: 2025/06/18 20:47:16 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//uses direct initialization, slightly safer
void randomChump(std::string name) {
    Zombie chumpZmb(name);
    chumpZmb.announce();
}

//copies initialization
/*void randomChump( std::string name )
{
	Zombie zombie = Zombie(name);
	zombie.announce();
}*/
