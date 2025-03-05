#include "Harl.hpp"
#include <iostream>

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug(void) {
    std::cout << "[ DEBUG ] I love extra bacon..." << std::endl;
}

void Harl::info(void) {
    std::cout << "[ INFO ] Adding extra bacon cost more money..." << std::endl;
}

void Harl::warning(void) {
    std::cout << "[ WARNING ] I think I deserve extra bacon for free..." << std::endl;
}

void Harl::error(void) {
    std::cout << "[ ERROR ] This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
    // Используем массив указателей на функции-члены
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*funcs[4])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            (this->*funcs[i])();
            return;
        }
    }
    // Если уровень не найден
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}