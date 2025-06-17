#include "Zombie.hpp"

Zombie *newZombie(std:: string name){
    Zombie *newZmb = new Zombie(name);
    //newZmb->announce();
    return (newZmb);
}