#include "Zombie.hpp"

int main()
{
    Zombie *pntrZombie = newZombie("newZmb");
    pntrZombie->announce();
    delete(pntrZombie);
    
    std::cout << std::endl;
    randomChump("chumpZombie");
}