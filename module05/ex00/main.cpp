#include "Bureaucrat.hpp"

int main(){
    //Bureaucrat buroNoName = new Bureaucrat();
    Bureaucrat buroNoName;
    Bureaucrat buroBrad("Brad", 155);
    std::cout << buroNoName;
    std::cout << buroBrad;
    buroBrad.incrGrade();
    std::cout << buroBrad;
    buroNoName.decrGrade();
    std::cout << buroNoName;
    //buroBrad.setGrade(-1);
    //std::cout << buroBrad;
}


