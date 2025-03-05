#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <LEVEL>" << std::endl;
        return 1;
    }
    std::string level = argv[1];

    Harl harl;
    harl.complainFilter(level);

    return 0;
}