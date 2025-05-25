#include "phonebook.hpp"

void PhoneBook::setPhoneBook(int i, int c){
	ind = i;
	count_n = c;
}

void PhoneBook::addContact() {

    if((count_n) >= maxCont) {
        if(ind == maxCont) {
            std::cout << "You reached the maximum number of contacts!\n";
            ind = 0;
            try {
                contacts[ind].createContact(ind);
                
            } catch(const EmptyInputException& err) {
                std::cerr << "Error: " << err.what() << std::endl;
                ind--;
            }   
        } else {
            std::cout << "The oldest contact will be rewritten\n";
            try {
                contacts[ind].createContact(ind);
                
            } catch(const EmptyInputException& err) {
                std::cerr << "Error: " << err.what() << std::endl;
                ind--;
            }
        }
    } else {
        try {
            contacts[ind].createContact(ind);
            
        } catch(const EmptyInputException& err) {
            std::cerr << "Error: " << err.what() << std::endl;
            count_n--;
            ind--;
        }
    }
    count_n++;
    ind++;
}

int PhoneBook::check_index(std::string input_str){
    const char * input_c_str;
    input_c_str = input_str.c_str();
    int i = 0;
    long int input_long;
    while(input_c_str[i])
    {
        if (!isdigit(input_c_str[i])){
            return (-1);
        }
        i++;
    }
	input_long = atol(input_c_str);
    if (input_long < 0 || input_long >= maxCont)
    {
        return (-1);
    }
    return ((int)input_long);
}

void PhoneBook::displayPhoneBook() {
    
    int i = 0;
    std::string input_str;
    std::cout << "|"
         << std::setw(10) << "Index" << "|"
         << std::setw(10) << "First Name" << "|"
         << std::setw(10) << "Last Name" << "|"
         << std::setw(10) << "Nickname" << "|"
         << std::endl;
    std::cout << std::string(45, '-') << std::endl;
    int res = (count_n < maxCont) ? count_n : maxCont;
	while(i < res) {
        contacts[i].showShortContact();
        i++;
    }
	std::cout << "Choose the index to see the contact\n";
	getline(std::cin, input_str);
    res = check_index(input_str);
	if (res == -1)
    {
        std::cout << "The wrong input! Introduce a digit that matches the indexes\n";
        displayPhoneBook();
        return;   
    }
	contacts[res].showLongContact();
}
//"\033[1;31mRed text\033[0m"
void PhoneBook::phoneBookIntro(){
    std::cout <<"\033[1;35m\n\tWelcome!\n"
    << "\tYou are going to use the best phonebook in the world\n"
    << "\tby Svetlana Titovskaia\n\033[0m";
}

void PhoneBook::run() {
    std::string choice;
    std::cout << "\n\tChoose what you want to do:\n\tADD    SEARCH    EXIT\n";
    getline(std::cin, choice);
    if(choice == "EXIT") {
        exit(0);
    } else if(choice == "SEARCH") {
        displayPhoneBook();
    } else if(choice == "ADD") {
        addContact();
    } else
        choice = "KEEP";
}
