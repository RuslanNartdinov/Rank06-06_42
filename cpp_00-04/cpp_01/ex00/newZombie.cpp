#include "Zombie.hpp"

// Создаём зомби в куче и возвращаем указатель
Zombie* newZombie(std::string name) {
    Zombie* z = new Zombie(name);
    return z;
}