#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <exception>
#include <iomanip>



class Color{
  private:
    std::string colorWarm;
    std::string colorCalm;
    std::string colorPale;
    std::string colorVibr;
    std::string errorRed;
    std::string bold;
    std::string reset;
  public:
    void set_theme(std::string thm);
    std::string getWarm();
    std::string getCalm();
    std::string getPale();
    std::string getVibr();
    std::string getRed();
    std::string getBold();
    std::string getReset();
};

class Contact {
  private:
    int index;
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string secret;
    Color thm;
  public:
    ~Contact();
    void createContact(int i, Color theme);
    void showShortContact();
    void showLongContact();
    std::string formatField(const std::string& field);
};


class PhoneBook {
  private:
    Color theme;
    int ind;
    int count_n;
    static const int maxCont = 4;
    Contact contacts[maxCont];
  public:
    void initialize(Color thm);
    void addContact();
    int check_index(std::string input);
    void displayPhoneBook();
    void phoneBookIntro();
    void run();
};

class EmptyInputException: public std::exception {
  public:
    const char* what() const throw() {
        return ("\nThe wrong phonebook input!");
    }
};

class WrongArgException: public std::exception {
  public:
    const char* what() const throw() {
        return ("\nThe wrong input!");
    }
};

#endif