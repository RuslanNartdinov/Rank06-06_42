#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
    ScavTrap s1("Guardian");
    s1.attack("some target");
    s1.guardGate();
    s1.takeDamage(60);
    s1.beRepaired(30);
    s1.takeDamage(70);
    s1.beRepaired(10);

    return 0;
}