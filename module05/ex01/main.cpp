#include "Common.hpp"

int main() {
    try {
        Bureaucrat a("Alice", 5);
        Bureaucrat b("Bob", 5);

        Form formA("formA", 4, 20);
        Form formB("formB", 120, 130);

        std::cout << "\n--- INITIAL STATE ---\n";
        std::cout << a;
        std::cout << b;
        std::cout << formA;
        std::cout << formB;

        std::cout << "\n--- SIGNING FORMS ---\n";
        a.signForm(formA);
        a.incrGrade();
        a.signForm(formA);
        b.signForm(formA);
        b.incrGrade();
        b.signForm(formA);
        b.signForm(formB);

        std::cout << "\n--- FINAL STATE ---\n";
        std::cout << formA;
        std::cout << formB;

        std::cout << "\n--- EXCEPTION TESTS ---\n";
        Form badForm1("TooHighForm", 0, 50);
        Form badForm2("TooLowForm", 151, 50);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << "\n";
    }

    return 0;
}

