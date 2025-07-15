#include "Bureaucrat.hpp"

class CustomExcept {
  public:
    CustomExcept(const std::string& msg) : message(msg) {}

    // Handle custom exception using what() method.
    const char* what() const {
        return message.c_str();
    }

  private:
    std::string message;
};