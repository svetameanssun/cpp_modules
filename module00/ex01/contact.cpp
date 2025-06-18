#include "phonebook.hpp"


void Contact::createContact(int i, Color theme) {
    std::string answer;
    std::cout << theme.getWarm() << "Introduce name:\n";
    std::cout << theme.getPale();
    getline(std::cin, firstName);
    std::cout << theme.getReset();
    if(firstName.empty()) {
        throw EmptyInputException();
    }
    std::cout << theme.getWarm() << "Introduce last name:\n";
    std::cout << theme.getPale();
    getline(std::cin, lastName);
    std::cout << theme.getReset();
    if(lastName.empty()) {
        throw EmptyInputException();
    }
    std::cout << theme.getWarm() << "Introduce nickname:\n";
    std::cout << theme.getPale();
    getline(std::cin, nickname);
    std::cout << theme.getReset();
    if(nickname.empty()) {
        throw EmptyInputException();
    }
    std::cout << theme.getWarm() << "Introduce phone number:\n";
    std::cout << theme.getPale();
    getline(std::cin, phoneNumber);
    std::cout << theme.getReset();
    if(phoneNumber.empty()) {
        throw EmptyInputException();
    }
    std::cout << theme.getWarm() << "Introduce your darkest secret:\n";
    std::cout << theme.getPale();
    getline(std::cin, secret);
    std::cout << theme.getReset();
    if(secret.empty()) {
        throw EmptyInputException();
    }
    std::cout << theme.getBold() << theme.getVibr() << "The contact saved!\n";
    index = i;
    thm = theme;
}

std::string Contact::formatField(const std::string& field) {
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    else
        return std::string(10 - field.length(), ' ') + field;
}


void Contact::showLongContact() {
    std::cout << "\n";
    std::cout << thm.getCalm() << "First name: " << thm.getPale() << firstName << thm.getReset() << "\n";
    std::cout << thm.getCalm() << "Last name:  " << thm.getPale() << lastName << thm.getReset() << "\n";
    std::cout << thm.getCalm() << "Nickname:   " << thm.getPale() << nickname << thm.getReset() << "\n";
    std::cout << thm.getCalm() << "Phone:      " << thm.getPale() << phoneNumber << thm.getReset() << "\n";
    std::cout << thm.getCalm() << "Secret:     " << thm.getPale()  << secret << thm.getReset() << "\n";
}

void Contact::showShortContact() {

    std::cout << thm.getPale() << "|"
         << std::setw(10) << index << "|"
         << std::setw(10) << formatField(firstName) << "|"
         << std::setw(10) << formatField(lastName) << "|"
         << std::setw(10) << formatField(nickname) << "|"
         << thm.getReset() <<std::endl;
}

Contact::~Contact() {
    std::cout << "deleted contact\n";
}

