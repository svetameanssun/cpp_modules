#include "phonebook.hpp"


void Contact::createContact(int i, Color theme) {
    std::string answer;
    std::cout << theme.getCalm() << "Introduce name:\n" << theme.getReset();
    getline(std::cin, first_name);
    if(first_name.empty()) {
        throw EmptyInputException();
    }
    std::cout << theme.getCalm() << "Introduce last name:\n" << theme.getReset();
    getline(std::cin, last_name);
    if(last_name.empty()) {
        throw EmptyInputException();
    }
    std::cout << theme.getCalm() << "Introduce nickname:\n" << theme.getReset();
    getline(std::cin, nickname);
    if(nickname.empty()) {
        throw EmptyInputException();
    }
    std::cout << theme.getCalm() << "Introduce phone number:\n" << theme.getReset();
    getline(std::cin, phone_number);
    if(phone_number.empty()) {
        throw EmptyInputException();
    }
    std::cout << theme.getCalm() << "Introduce your darkest secret:\n" << theme.getReset();
    getline(std::cin, secret);
    if(secret.empty()) {
        throw EmptyInputException();
    }
    std::cout << theme.getBold() << theme.getVibr() << "The contact saved\n" << theme.getReset();
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
    std::cout << thm.getWarm() << "First name: " << first_name << thm.getReset() << "\n";
    std::cout << thm.getWarm() << "Last name:  "  << last_name << thm.getReset() << "\n";
    std::cout << thm.getWarm() << "Nickname:   "  << nickname << thm.getReset() << "\n";
    std::cout << thm.getWarm() << "Phone:      "  << phone_number << thm.getReset() << "\n";
    std::cout << thm.getWarm() << "Secret:     "  << secret << thm.getReset() << "\n";
}

void Contact::showShortContact() {

    std::cout << thm.getWarm() << "|"
         << std::setw(10) << index << "|"
         << std::setw(10) << formatField(first_name) << "|"
         << std::setw(10) << formatField(last_name) << "|"
         << std::setw(10) << formatField(nickname) << "|"
         << thm.getReset() <<std::endl;
}

Contact::~Contact() {
    std::cout << "deleted contact\n";
}

