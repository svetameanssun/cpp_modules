#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"

Bureaucrat::Bureaucrat(): _name("Name"), _grade(150) {
    std::cout << "Bureaucrat " << getName() << " constructed by default\n";
}
#ifdef USE_CONSTRUCTOR_TRY_BLOCK
void logError(const std::string & message){
    std::ofstream log("log.txt", std::ios::app); // WHY THIS???
    log << message << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
try: _name(name), _grade(grade){
    if (grade < 1){
        throw GradeTooHighException();
    }
    if (grade > 150){
        throw GradeTooLowException();
    }
    std::cout << "Bureaucrat " << getName() << " constructed\n";
}
catch (const std::exception &e) {
    logError("Error in Bureaucrat: " + std::string(e.what()));
    throw;
}

#else
Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name){
    if (grade < 1){
        throw GradeTooHighException();
    }
    if (grade > 150){
        throw GradeTooLowException();
    }
    _grade = grade;
    std::cout << "Bureaucrat " << getName() << " constructed\n";
}
#endif

Bureaucrat::Bureaucrat(const Bureaucrat & other){
    _grade = other._grade;
    std::cout << "Bureaucrat copy contructor called!\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
    if (this != &other){
        _grade = other._grade;
        std::cout << "Bureaucrat " << getName() << " constructed\n";
    }
    return (*this);
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat " << getName() << " deleted\n";
}

const std::string& Bureaucrat::getName(void) const{
    return(_name);
}

int Bureaucrat::getGrade(void) const{
    return(_grade);
}

void Bureaucrat::incrGrade(void){
    if (_grade - 1 == 0)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrGrade(void){
    if (_grade + 1 == 151)
        throw GradeTooLowException();
    _grade++;
}

void Bureaucrat::signForm(AForm& form) const{
   try{
       form.beSigned(*this);
       std::cout << "bureaucrat " << this->getName() <<" signed form " << form.getName() << "\n";
    }
    catch (const std::exception & e){
        std:: cerr << "bureaucrat " << this->getName() <<" couldn’t sign form " << form.getName() << ", because " << e.what();
    }
}

void Bureaucrat::executeForm(AForm & form)const{
    try{
       form.execute(*this);
    }
    catch (const std::exception & e){
        std:: cerr << "bureaucrat " << this->getName() <<" couldn’t execute form " << form.getName() << ", because " << e.what();
    }
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat&burocrat){
    os << burocrat.getName() << ", bureaucrat grade " << burocrat.getGrade() << "." << "\n";
    return (os);
}
