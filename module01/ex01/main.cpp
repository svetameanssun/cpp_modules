#include "Zombie.hpp"

int main(){
    int numZombies = 5;
    std::string hordeName = "hordMember";
    Zombie* myHorde = zombieHorde(numZombies, hordeName);

    if (myHorde != NULL){
        for (int i = 0; i <numZombies; ++i){
            myHorde[i].announce();
        }
        std::cout << std::endl;
        delete[] myHorde;
    }
    std::cout << "\n--- Testing 0 ---" << std::endl;
    Zombie* emptyHorde = zombieHorde(0, "Empty");
    if (emptyHorde == NULL) {
        std::cout << "Number of zombies = 0" << std::endl;
    }

    std::cout << "\n--- Testing negative ---" << std::endl;
    Zombie* negativeHorde = zombieHorde(-3, "Отрицательный");
    if (negativeHorde == NULL) {
        std::cout << "Number of zombies is negative" << std::endl;
    }

    return 0;
}