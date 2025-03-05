#include "Zombie.hpp"

// Создаём зомби на стеке, вызываем announce, 
// после выхода из функции он будет уничтожен
void randomChump(std::string name) {
    Zombie z(name);
    z.announce();
}