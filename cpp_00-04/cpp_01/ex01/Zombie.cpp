#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {
    // Конструктор по умолчанию, пока без логики
}

Zombie::~Zombie() {
    std::cout << "Zombie " << _name << " destroyed" << std::endl;
}

void Zombie::setName(std::string name) {
    _name = name;
}

void Zombie::announce() const {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}