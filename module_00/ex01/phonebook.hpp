#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <exception>
#include <iomanip>

class Contact {
  private:
    int index;
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string secret;
  public:
    ~Contact();
    void createContact(int i);
    void showShortContact();
    void showLongContact();
    std::string formatField(const std::string& field);
};


class PhoneBook {
  private:
    int ind;
    int count_n;
    static const int maxCont = 4;
    Contact contacts[maxCont];
  public:
    void setPhoneBook(int i, int c);
    void addContact();
    int check_index(std::string input);
    void displayPhoneBook();
    void phoneBookIntro();
    void run();
};

class EmptyInputException: public std::exception {
  public:
    const char* what() const throw() {
        return "The wrong input!\n";
    }
};

/*class WrongInputException: public std::exception {
  public:
    const char* what() const throw() {
        return "The wrong input! Introduce a digit that matches the indexes\n";
    }
};*/

#endif