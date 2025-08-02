#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target){
    std::cout << "ShrubberyCreationForm constructed\n";
}

/*Creates a file <target>_shrubbery in the working directory and writes ASCII trees
inside it.*/

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target){
    std::cout << "ShrubberyCreationForm copy contructor called!\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
    if (this != &other){
        setSignature(other.getSignature());
    }
    std::cout << "ShrubberyCreationForm " << getName() << " assigned\n";
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "ShrubberyCreationForm "<< getName() << " deleted\n";
}

const std::string& ShrubberyCreationForm::getTarget(void) const{
    return (_target);
}

void ShrubberyCreationForm::beSigned(const Bureaucrat &buro){
    if (this->getGradeSign() < buro.getGrade()){
        throw PermissionDenied();
    }
    setSignature(true);
}

void ShrubberyCreationForm::execute(const Bureaucrat & executor) const {
    if (this->getGradeExec() < executor.getGrade()){
        throw PermissionDenied();
    }
    if (!this->isSigned()){
        throw PermissionDenied();
    }
    std::string fileName = this->getTarget() + "_shrubbery";
    std::ofstream openedFile(fileName.c_str(), std::ofstream::out);
    if (!openedFile.is_open()){
        throw std::runtime_error("Error: could not open file");
    }
    std::string pineTree = "          .     .  .      +     .      .          .\n"
        "     .       .      .     #       .           .\n"
        "        .      .         ###            .      .      .\n"
        "      .      .   \"#:. .:##\"##:. .:#\"  .      .\n"
        "          .      . \"####\"###\"####\"  .\n"
        "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n"
        "  .             \"#########\"#########\"        .        .\n"
        "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .\n"
        "     .     .  \"#######\"\"##\"##\"\"#######\"                  .\n"
        "                .\"##\"#####\"#####\"##\"           .      .\n"
        "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n"
        "      .     \"#######\"##\"#####\"##\"#######\"      .     .\n"
        "    .    .     \"#####\"\"#######\"\"#####\"    .      .\n"
        "            .     \"      000      \"    .     .\n"
        "       .         .   .   000     .        .       .\n"
        ".. .. ..................O000O........................ ........\n";
    openedFile << pineTree;
    std::cout << "bureaucrat " << executor.getName() <<" executed form " << this->getName() << "\n";
}
