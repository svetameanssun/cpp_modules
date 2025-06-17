#include "Harl.hpp" // Включаем заголовочный файл класса Harl

int main() {
    Harl myHarl; // Создаем объект класса Harl

    std::cout << "--- Harl жалуется на DEBUG ---" << std::endl;
    myHarl.complain("DEBUG");

    std::cout << "--- Harl жалуется на INFO ---" << std::endl;
    myHarl.complain("INFO");

    std::cout << "--- Harl жалуется на WARNING ---" << std::endl;
    myHarl.complain("WARNING");

    std::cout << "--- Harl жалуется на ERROR ---" << std::endl;
    myHarl.complain("ERROR");

    std::cout << "--- Harl жалуется на неизвестный уровень ---" << std::endl;
    myHarl.complain("UNKNOWN");

    // Также можно протестировать уровни, которые не существуют
    std::cout << "--- Harl жалуется на 'INVALID' ---" << std::endl;
    myHarl.complain("INVALID");

    return 0;
}