#include "Zombie.hpp"

std::string itoa(int num){
    int n;
    int nSize;
    if (num > 2147483647){
        std::cerr << "error: number too big\n";
        return(NULL);
    }
    if (num == 0)
    {
        return ("0");
    }
    n = num;
    nSize = 1;
    while(n > 0){
        nSize++;
        n = n/10; 
    }
    n = 0;
    char cStr[nSize];
    
    cStr[--nSize] = '\0';
    nSize--;
    while(nSize >= 0)
    {
        cStr[nSize] = (num % 10) + 48;
        num /=10;
        nSize--;
    }
    std::string str = cStr;
    return (str);

} 

Zombie* zombieHorde( int N, std::string name ){
    if (N <= 0){
        std::cerr << "error: wrong number\n";
        return NULL;
    }
    Zombie *horde = new Zombie[N];

    for (int i = 0; i < N; ++i){
        horde[i].setName(name + itoa(i));
    }

    return horde;


}