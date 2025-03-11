#include <iostream>
#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

// DEBUG: Обычно самый подробный и "легковесный" уровень жалоб.
void Harl::debug(void) {
    std::cout << "[ DEBUG ]\n"
              << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. "
              << "I really do!\n"
              << std::endl;
}

// INFO: Следующий по приоритету уровень. Может содержать более важные замечания.
void Harl::info(void) {
    std::cout << "[ INFO ]\n"
              << "I cannot believe adding extra bacon costs more money. "
              << "You didn’t put enough bacon in my burger! "
              << "If you did, I wouldn’t be asking for more!\n"
              << std::endl;
}

// WARNING: Уровень предупреждения; жалоба становится серьёзнее.
void Harl::warning(void) {
    std::cout << "[ WARNING ]\n"
              << "I think I deserve to have some extra bacon for free. "
              << "I’ve been coming for years whereas you started working here since last month.\n"
              << std::endl;
}

// ERROR: Критическое сообщение – "невозможно терпеть".
void Harl::error(void) {
    std::cout << "[ ERROR ]\n"
              << "This is unacceptable, I want to speak to the manager now.\n"
              << std::endl;
}