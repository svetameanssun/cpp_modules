#include "phonebook.hpp"

int main() {
    
    PhoneBook phonebookObj;
    phonebookObj.setPhoneBook(0,0);
    phonebookObj.phoneBookIntro();
    while(1) {
        phonebookObj.run();
    }
    return (0);
}