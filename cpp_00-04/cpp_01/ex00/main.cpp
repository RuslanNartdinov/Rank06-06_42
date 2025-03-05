#include "Zombie.hpp"
#include <iostream>

// Объявление функций, если нужны (можно подключить hpp).
Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() {
    // 1) Создаём зомби на куче
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();

    // 2) Создаём зомби на стеке (через randomChump)
    randomChump("StackZombie");

    // 3) Удаляем зомби, созданного на куче
    delete heapZombie;

    return 0;
}