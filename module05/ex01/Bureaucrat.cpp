#include "Common.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name){
    if (grade < 1){
        throw GradeTooHighException();
    }
    if (grade > 150){
        throw GradeTooLowException();
    }
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name){
    _grade = other._grade;
    std::cout << "Bureaucrat copy contructor called!\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other){
    if (this != &other){
        //_name = other._name; //cannot redefine a const parameter
        _grade = other._grade; //trying this, instead of getName();
    }
    std::cout << "Bureacrat " << getName() << " assigned\n";
    return (*this);
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat " << getName() << " deleted\n";
}

const std::string& Bureaucrat::getName(void) const{
    return (_name);
}

int Bureaucrat::getGrade(void) const{
    return (_grade);
}

void Bureaucrat::incrGrade(void){
    int grade;
    grade = getGrade();
    if (grade - 1 == 0){
        throw GradeTooHighException();
    }
    grade--;
    _grade = grade;
}

void Bureaucrat::decrGrade(void){
    int grade;
    grade = getGrade();
    if (grade + 1 == 151){
        throw GradeTooLowException();
    }
    grade++;
    _grade = grade;
}

void Bureaucrat::signForm(Form& form){
    try{
        form.beSigned(*this);
        std::cout << "bureaucrat " << getName() <<" signed form " << form.getName();
    } catch (const std::exception &e){
        std:: cerr << "bureaucrat " << getName() <<" couldn’t sign form " << form.getName() << ", because " << e.what();
    }
}
/*Then, modify the signForm() member function in the Bureaucrat class. This function must call Form::beSigned() to attempt to sign the form. If the form is signed
successfully, it will print something like:
<bureaucrat> signed <form>
Otherwise, it will print something like:
<bureaucrat> couldn’t sign <form> because <reason>.
Implement and submit some tests to ensure everything works as expected.
*/
std::ostream& operator<<(std::ostream &os, const Bureaucrat&burocrat){
    os << burocrat.getName() << ", bureaucrat grade " << burocrat.getGrade() << "." << "\n";
    return (os);
}


