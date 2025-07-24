#include "Common.hpp"

int main(){
    try{
        Bureaucrat a("Alice", 1);
        Bureaucrat b("Bob", 150);
        Bureaucrat c("Caro", 2);
        Bureaucrat d("Danila", 151);
        std::cout << a;
        std::cout << b;
        std::cout << c;
        std::cout << d;
    }
    catch (const std::exception& e) {
        std:: cerr << "Exception caught: " << e.what() << std::endl;
    }
    return (0);
}
