#include "phonebook.hpp"


void Contact::createContact(int i) {
    std::string answer;
    std::cout << "Introduce name:\n";
    getline(std::cin, first_name);
    if(first_name.empty()) {
        throw EmptyInputException();
    }
    std::cout << "Introduce last name:\n";
    getline(std::cin, last_name);
    if(last_name.empty()) {
        throw EmptyInputException();
    }
    std::cout << "Introduce nickname:\n";
    getline(std::cin, nickname);
    if(nickname.empty()) {
        throw EmptyInputException();
    }
    std::cout << "Introduce phone number:\n";
    getline(std::cin, phone_number);
    if(phone_number.empty()) {
        throw EmptyInputException();
    }
    std::cout << "Introduce your darkest secret:\n";
    getline(std::cin, secret);
    if(secret.empty()) {
        throw EmptyInputException();
    }
    std::cout << "The contact saved\n";
    index = i;
    
}

std::string Contact::formatField(const std::string& field) {
    if (field.length() > 10)
        return field.substr(0, 9) + "."; // truncate and add dot
    else
        return std::string(10 - field.length(), ' ') + field;
}


void Contact::showLongContact() {
	std::cout << first_name <<"\n";
	std::cout << last_name <<"\n";
	std::cout << nickname <<"\n";
	std::cout << phone_number <<"\n";
	std::cout << secret <<"\n";

}


void Contact::showShortContact() {
    std::cout << "|"
         << std::setw(10) << index << "|"
         << std::setw(10) << formatField(first_name) << "|"
         << std::setw(10) << formatField(last_name) << "|"
         << std::setw(10) << formatField(nickname) << "|"
         << std::endl;
}

Contact::~Contact() {
    std::cout << "deleted contact\n";
}

