#include <iostream>
#include <string>

int main()
{
    std::string variable = "HI THIS IS BRAIN";
    std::string * stringPTR = &variable;
    std::string &stringREF = variable;

    std::cout << "The memory address of the string variable: " << &variable << std::endl;
    std::cout << "The memory address held by stringPTR: " << stringPTR << std::endl;
    //  A reference is an alias (another name) for an existing variable.
    //    It must be initialized at declaration and cannot be reseated.
    std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;
    std::cout << std::endl;
    std::cout << "The value of the string variable: " << variable << std::endl;
    std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF: "<< stringREF << std::endl;

    return (0);
}