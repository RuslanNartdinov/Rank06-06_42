#include "ClapTrap.hpp"
#include <iostream>

int main() {
    ClapTrap c1("Alpha");
    ClapTrap c2("Bravo");

    c1.attack("Bravo");
    c2.takeDamage(0);
    c2.beRepaired(5);

    c1.takeDamage(11);
    c1.beRepaired(5);
    return 0;
}