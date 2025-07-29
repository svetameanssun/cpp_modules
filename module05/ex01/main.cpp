#include "Common.hpp"

int main(){
    try{
        Bureaucrat b("Bob", 2);
        Bureaucrat defaultBuro;
        //Bureaucrat errorBuro("Danila", 151); // will not be created
        //std::cout << a;
        std::cout << b;
        std::cout << defaultBuro;
        //std::cout << errorBuro;
    }
    catch (const std::exception& e) {
        std:: cerr << "Bureaucrat exception caught: " << e.what() << std::endl;
    }
    try{
        Form formB("formB", 2, 150);
        Form defaultForm;
        /*Form errorForm1("errorForm1", 0, 150);
        Form errorForm2("errorForm2", 1, 151);
        Form errorForm3("errorForm3", 1, 151);
        Form errorForm4("errorForm4", -1, -151);*/
    }
    catch (const std::exception &e){
        std::cerr << "Form exception caught: " << e.what() << "\n";
    }
    try {
    Bureaucrat a("Alice", 2);
    Form formA("formA", 1, 2);
    a.signForm(formA);
    }
    catch (const std::exception &e){
        std::cerr << "Form exception caught: " << e.what() << "\n";
    }

    
    return (0);
}
