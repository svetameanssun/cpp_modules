#include "Bureaucrat.hpp"
#include "AForm.hpp"

#ifdef USE_CONSTRUCTOR_TRY_BLOCK

int main(void){
    Bureaucrat buroA("Alice", 1);
    Bureaucrat buroB("Bob", 150);
    ShrubberyCreationForm formHome("home");
    RobotomyRequestForm formLelo("Lelo");
    PresidentialPardonForm formHarold("Harold");

    std::cout << "<------------------------------------------------------------------------------------------------------------>" << std::endl;

    std::cout << CYAN << "\t" << buroA << RESET;
    std::cout << CYAN << "\t" << buroB << RESET;
    std::cout << CYAN << "\t" << formHome << RESET;
    std::cout << CYAN << "\t" << formLelo << RESET;
    std::cout << CYAN << "\t" << formHarold << RESET;
    
    std::cout << "<------------------------------------------------------------------------------------------------------------>" << std::endl;

    buroA.signForm(formHome);
    buroB.signForm(formLelo);
    buroA.signForm(formLelo);
    buroA.signForm(formHarold);
    
    std::cout << "<------------------------------------------------------------------------------------------------------------>" << std::endl;

    b1.executeForm(formHome);
    b1.executeForm(formLelo);
    b1.executeForm(formLelo);
    b2.executeForm(formHarold);
    b1.executeForm(formHarold);
    
    std::cout << "<------------------------------------------------------------------------------------------------------------>" << std::endl;
  return (0);
}

#else
int main(void){
  try {
    Bureaucrat buroA("Alice", 1);
    Bureaucrat buroB("Bob", 150);
    ShrubberyCreationForm formHome("home");
    RobotomyRequestForm formLelo("Lelo");
    PresidentialPardonForm formHarold("Harold");

    std::cout << "<------------------------------------------------------------------------------------------------------------>" << std::endl;

    std::cout << CYAN << "\t" << buroA << RESET;
    std::cout << CYAN << "\t" << buroB << RESET;
    std::cout << CYAN << "\t" << formHome << RESET;
    std::cout << CYAN << "\t" << formLelo << RESET;
    std::cout << CYAN << "\t" << formHarold << RESET;
    
    std::cout << "<------------------------------------------------------------------------------------------------------------>" << std::endl;

    buroA.signForm(formHome);
    buroB.signForm(formLelo);
    buroA.signForm(formLelo);
    buroA.signForm(formHarold);
    
    std::cout << "<------------------------------------------------------------------------------------------------------------>" << std::endl;

    b1.executeForm(formHome);
    b1.executeForm(formLelo);
    b1.executeForm(formLelo);
    b2.executeForm(formHarold);
    b1.executeForm(formHarold);
    
    std::cout << "<------------------------------------------------------------------------------------------------------------>" << std::endl;
  }
  catch (const std::exception & e){
    std::cerr << "Exception caught: " << e.what() << "\n";
  }
  return (0);
}
#endif
