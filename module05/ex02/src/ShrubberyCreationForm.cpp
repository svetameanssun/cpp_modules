#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(cosnt std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target){
    std::cout << "ShrubberyCreationForm constructed\n";
}

/*Creates a file <target>_shrubbery in the working directory and writes ASCII trees
inside it.*/

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm::_signature(other._signature){
    std::cout << "ShrubberyCreationForm copy contructor called!\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
    if (this != &other){
        _signature = other._signature;
    }
    return (*this);
    std::cout << "ShrubberyCreationForm " << getName() << " assigned\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "ShrubberyCreationForm "<< getName() << " deleted\n";
}


const std::string& ShrubberyCreationForm::getName(void) const{
    return (_target);
}

void ShrubberyCreationForm::beSigned(const Bureaucrat &buro){
    if (this->_gradeSign < buro._grade){
        throw PermissionDenied();
    }
    this->_signature = true;
    std::cout << "bureaucrat " << buro.getName() <<" signed form " << this->getName() << "\n";
}

void ShrubberyCreationForm::execute(const Bureaucrat & executor) const {
    if (this->_gradeExec < buro._grade){
        throw PermissionDenied();
    }
    std::string fileName = this->getTarget() + "_shrubbery";
    std:ofstream openedFile(fileName.c_str(), std::ofstream::out);
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
    std::cout << getName() << " executed " << form.getName() << "\n";
    std::cout << "bureaucrat " << buro.getName() <<" executed form " << this->getName() << "\n";
}
