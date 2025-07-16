#include "Bureaucrat.hpp"
// this is a custom exception, I will not use it this time.
/*class CustomExcept {
  public:
    CustomExcept(const std::string& msg) : message(msg) {}

    // Handle custom exception using what() method.
    const char* what() const {
        return message.c_str();
    }

  private:
    std::string message;
};*/

const char * Bureaucrat::GradeTooHighException:: what() const throw(){
  return ("Grade is too high!");
}

const char *Bureaucrat::GeadeTooLowException:: what() const throw(){
  return ("Grade is too low!");
}
