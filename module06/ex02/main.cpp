#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <typeinfo>
#include <ctime>
#include <cstdlib>
#include <iostream>

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

// dynamic_cast <new_type> (exp);
// example:
//  Dog* dogPtr = dynamic_cast<Dog*>(animalPtr);
Base * generate(void){
    int i;
    i = (rand()%3)+1;
    switch(i){
        case 1 : 
            return (new A());
        case 2 :
            return (new B());
        case 3 :
            return (new C());
    }
    return (NULL);
}
//It randomly instantiates A, B, or C and returns the instance as a Base pointer. Feel free
//to use anything you like for the random choice implementation.
void identify(Base* p){
    std::cout << "---------------------------------------------\n";
    std:: cout << "POINTER IDENTIFICATION\n";
    std::cout << "---------------------------------------------\n";
    A* aPtr = dynamic_cast<A*>(p);
    B* bPtr = dynamic_cast<B*>(p);
    C* cPtr = dynamic_cast<C*>(p);
    if (aPtr != NULL){
        std::cout << "It is A class!\n";
    }
    else if (bPtr != NULL){
        std::cout << "It is B class!\n";
    }
    else if (cPtr != NULL){
        std::cout << "It is C class!\n";
    }
    else{
        std::cout << "Something went wrong!\n";
    }
}
//It prints the actual type of the object pointed to by p: "A", "B", or "C".

void identify(Base& p){
    std::cout << "---------------------------------------------\n";
    std::cout << "REFERENCE IDENTIFICATION\n";
    std::cout << "---------------------------------------------\n";

    try{
        A &aRef = dynamic_cast<A&>(p);
        std::cout << "It is A class!\n";
        (void)aRef;
        return;
    } catch (std::bad_cast&){}

    try{
        B &bRef = dynamic_cast<B&>(p);
        std::cout << "It is B class!\n";
        (void)bRef;
        return;
    } catch(std::bad_cast&){}
    
    try{
        C &cRef = dynamic_cast<C&>(p);
        std::cout << "It is C class!\n";
        (void)cRef;
        return;
    } catch (std::bad_cast&){}
}
//t prints the actual type of the object referenced by p: "A", "B", or "C". Using a pointer
//inside this function is forbidden.

int main(){
    srand(time(NULL));
    Base * basePtr = generate();
    identify(basePtr);
    identify(*basePtr);
    delete(basePtr);
}