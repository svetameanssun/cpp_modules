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
    void setTheme(std::string thm);
    std::string getWarm() const; // made all of them const 
    std::string getCalm() const;
    std::string getPale() const;
    std::string getVibr() const;
    std::string getRed() const;
    std::string getBold() const;
    std::string getReset() const;
};

class Contact {
  private:
    int index;
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
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
    int introTimes;
    Color theme;
    int ind; 
    int count;
    static const int maxNum = 8;
    Contact contacts[maxNum];
  public:
    PhoneBook(int a, int b, int c);
    void initTheme(Color thm);
    void resetIntroTimes();
    void addContact();
    int checkIndex(std::string input);
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