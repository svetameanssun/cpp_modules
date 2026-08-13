#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Dark Blue */
#define MAGENTA "\033[35m"      /* Purple */
#define CYAN    "\033[36m"      /* Light Blue */
#define WHITE   "\033[37m"      /* White */

#define BOLD    "\033[1m"
#define UNDERLINE "\033[4m"

#define BG_RED     "\033[41m"
#define BG_GREEN   "\033[42m"
#define BG_YELLOW  "\033[43m"
#define BG_BLUE    "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN    "\033[46m"
#define BG_WHITE   "\033[47m"

class AForm;

class Bureaucrat {
  public:
    // -- CANONICAL FORM --
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat&operator=(const Bureaucrat &other);
    ~Bureaucrat();

    // -- GETTERS --
    const std::string & getName(void) const;
    int getGrade(void) const;

    // -- GRADE UP/DOWN --
    void incrGrade(void);
    void decrGrade(void);

    // -- SIGN FORM --
    void signForm(AForm &form) const;
    void executeForm(AForm & form) const;

    // -- EXCEPTIONS --
    class GradeTooHighException : public std::exception {
      public:
        const char *what() const throw();

    };
    class GradeTooLowException : public std::exception {
      public:
        const char *what() const throw();
    };

    /*void logError(const std::string & message);*/

  private:
    const std::string _name;
    int _grade;
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat& buro);


#endif
