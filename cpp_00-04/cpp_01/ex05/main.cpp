#include <iostream>
#include "Harl.hpp"

int main() {
    // Создаём объект Harl.
    Harl harl;

    // Вызываем метод complain с разными уровнями, чтобы увидеть, как объект "жалуется".
    std::cout << "Calling complain with \"DEBUG\":" << std::endl;
    harl.complain("DEBUG");

    std::cout << std::endl << "Calling complain with \"INFO\":" << std::endl;
    harl.complain("INFO");

    std::cout << std::endl << "Calling complain with \"WARNING\":" << std::endl;
    harl.complain("WARNING");

    std::cout << std::endl << "Calling complain with \"ERROR\":" << std::endl;
    harl.complain("ERROR");

    std::cout << std::endl << "Calling complain with an unknown level:" << std::endl;
    harl.complain("SOMETHING");

    return 0;
}