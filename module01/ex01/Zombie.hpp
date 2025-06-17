#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie{
    private:
        std::string name;
    public:
        Zombie();
        Zombie(std::string name);
        void announce( void );
        void setName(std::string newName);
        ~Zombie();
};

Zombie* zombieHorde( int N, std::string name );
std::string itoa(int num);



#endif