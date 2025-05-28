#include "phonebook.hpp"

int main(int argc, char **argv) {

    Color thm;
    if (argc == 1)
    {
        thm.set_theme("default");
    }
    else if (argc == 2)
    {
        try {
            thm.set_theme((std::string)argv[1]);
        } catch(const WrongArgException &err){
            std::cerr << "\033[1;31m" << "Error: " << err.what() << "\033[0m" << std::endl;
            return (1);
        }
    }
    else if (argc > 2)
    {
        std::cerr << "\033[1;31m" << "Too many arguments!\n" << "\033[0m" << std::endl;
    }

    PhoneBook phonebookObj;
    phonebookObj.initialize(thm);
    phonebookObj.phoneBookIntro();
    while(1) {
        phonebookObj.run();
    }
    return (0);
}