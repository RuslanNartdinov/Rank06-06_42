#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main() {
    FragTrap f1("Hero");
    f1.attack("Enemy");
    f1.highFivesGuys();
    f1.takeDamage(50);
    f1.beRepaired(40);
    f1.takeDamage(100);
    f1.beRepaired(10);

    return 0;
}