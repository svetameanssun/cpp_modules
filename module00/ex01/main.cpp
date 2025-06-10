#include "phonebook.hpp"

int main(int argc, char **argv) {

    Color thm;
    if (argc == 1)
    {
        thm.setTheme("default");
    }
    else if (argc == 2)
    {
        try {
            thm.setTheme((std::string)argv[1]);
        } catch(const WrongArgException &err){
            std::cerr << "\033[1;31m" << "Error: " << err.what() << "\033[0m" << std::endl;
            return (1);
        }
    }
    else if (argc > 2)
    {
        std::cerr << "\033[1;31m" << "Too many arguments!\n" << "\033[0m" << std::endl;
    }

    PhoneBook phonebookObj(0, 0, 0);
    phonebookObj.initTheme(thm);
    phonebookObj.phoneBookIntro();
    while(1) {
        phonebookObj.run();
    }
    return (0);
}