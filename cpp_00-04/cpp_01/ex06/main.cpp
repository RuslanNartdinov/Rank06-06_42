#include <iostream>
#include <string>
#include "Harl.hpp"

// В ex06 требуется программа, которая берёт один аргумент командной строки (уровень) 
// и выводит все сообщения от данного уровня и выше. 
// При этом используется switch и "проваливание" (fall-through).

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <level>\n";
        return 1;
    }

    std::string level = argv[1];
    Harl harl;

    // Переводим строку уровня в числовой код для switch
    // (DEBUG -> 0, INFO -> 1, WARNING -> 2, ERROR -> 3)
    int lvl = -1;
    if (level == "DEBUG")
        lvl = 0;
    else if (level == "INFO")
        lvl = 1;
    else if (level == "WARNING")
        lvl = 2;
    else if (level == "ERROR")
        lvl = 3;

    switch (lvl) {
        case 0: // DEBUG
            harl.debug();
            // fall through
        case 1: // INFO
            harl.info();
            // fall through
        case 2: // WARNING
            harl.warning();
            // fall through
        case 3: // ERROR
            harl.error();
            break;
        default:
            // Если уровень не узнан, выводим дефолтное сообщение
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }

    return 0;
}