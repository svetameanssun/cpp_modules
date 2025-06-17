#include "Zombie.hpp"

Zombie::Zombie() :name("Unnamed Zombie"){
    std::cout << "Zombie " << this->name << " created (by default)" << std::endl;
}

Zombie::Zombie(std::string name) : name(name){
    std::cout << "Zombie " << this->name << " created!" << std::endl;
}

Zombie::~Zombie(){
    std::cout << this->name << ": Arrrgh... *dying*" << std::endl;
}

void Zombie::announce()
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
void Zombie::setName(std::string newName)
{
    this->name = newName;

}