#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/color.hpp"

int main(void){
  try {
    Bureaucrat buroA("Alice", 1);
    Bureaucrat buroB("Bob", 150);
    Bureaucrat buroС("Carl", 151);
    Bureaucrat buroD("Daile", 0);
    
    ShrubberyCreationForm formHome("home");
    RobotomyRequestForm formLelo("Lelo");
    PresidentialPardonForm formHarold("Harold");

    std::cout << "<------------------------------------------------------------------------------------------------------------>" << std::endl;

    std::cout << YELLOW << "\t" << buroA << RESET;
    std::cout << YELLOW << "\t" << buroB << RESET;
    std::cout << CYAN << "\t" << formHome << RESET;
    std::cout << CYAN << "\t" << formLelo << RESET;
    std::cout << CYAN << "\t" << formHarold << RESET;
    
    std::cout << "<------------------------------------------------------------------------------------------------------------>" << std::endl;

    buroA.signForm(formHome);
    buroB.signForm(formLelo);
    buroA.signForm(formLelo);
    buroA.signForm(formHarold);
    
    std::cout << "<------------------------------------------------------------------------------------------------------------>" << std::endl;

    buroA.executeForm(formHome);
    buroA.executeForm(formLelo);
    buroA.executeForm(formLelo);
    buroB.executeForm(formHarold);
    buroA.executeForm(formHarold);
    
    std::cout << "<------------------------------------------------------------------------------------------------------------>" << std::endl;
  }
  catch (const std::exception & e){
    std::cerr << "Exception caught: " << e.what() << "\n";
  }

  try {
    ShrubberyCreationForm formGarden("garden");
    std::cout << formGarden.getName() << "\n";
    std::cout << formGarden.getTarget() << "\n";

    PresidentialPardonForm * formArni = new PresidentialPardonForm("Arni");
    //formArni = new ShrubberyCreationForm("park");
    std::cout << *formArni << "\n";
   

    ShrubberyCreationForm *greenhouse = new ShrubberyCreationForm("greenhouse");
    std::cout << *greenhouse << "\n";
    std::cout << GREEN << greenhouse->getTarget() << RESET << "\n";
    delete (greenhouse); //gtk;
    greenhouse = new ShrubberyCreationForm("park");
    std::cout << *greenhouse << "\n";
    std::cout << GREEN << greenhouse->getTarget() << RESET<< "\n";
    delete(formArni);
    delete(greenhouse);    
  }
  catch (const std::exception & e){
    std::cerr << "Exception caught: " << e.what() << "\n";
  }

  return (0);
}
