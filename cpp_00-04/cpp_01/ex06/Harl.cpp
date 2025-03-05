#include "Harl.hpp"
#include <iostream>

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug(void) {
    std::cout << "[ DEBUG ]\nI love extra bacon..." << std::endl;
}

void Harl::info(void) {
    std::cout << "[ INFO ]\nAdding extra bacon cost more..." << std::endl;
}

void Harl::warning(void) {
    std::cout << "[ WARNING ]\nI deserve extra bacon for free..." << std::endl;
}

void Harl::error(void) {
    std::cout << "[ ERROR ]\nThis is unacceptable..." << std::endl;
}

static int getLevelIndex(std::string level) {
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level)
            return i;
    }
    return -1;
}

void Harl::complainFilter(std::string level) {
    int index = getLevelIndex(level);

    switch (index) {
        case 0: // DEBUG
            this->debug();
            std::cout << std::endl;
            // fall through
        case 1: // INFO
            this->info();
            std::cout << std::endl;
            // fall through
        case 2: // WARNING
            this->warning();
            std::cout << std::endl;
            // fall through
        case 3: // ERROR
            this->error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}