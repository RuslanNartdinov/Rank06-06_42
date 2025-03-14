#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    {
        std::cout << "=== Simple test with array of Animals ===" << std::endl;
        Animal* animals[4];
        
        // Создаём 2 Dogs и 2 Cats
        for (int i = 0; i < 4; i++) {
            if (i < 2)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
        }

        std::cout << "\nSetting ideas in the first Dog and first Cat..." << std::endl;
        Dog* dogPtr = dynamic_cast<Dog*>(animals[0]);
        Cat* catPtr = dynamic_cast<Cat*>(animals[2]);
        if (dogPtr) dogPtr->setIdea(0, "I want a bone");
        if (catPtr) catPtr->setIdea(0, "I want a fish");

        std::cout << "\nCheck ideas before deleting objects..." << std::endl;
        std::cout << "Dog's idea: " << dogPtr->getIdea(0) << std::endl;
        std::cout << "Cat's idea: " << catPtr->getIdea(0) << std::endl;

        // Удаляем
        for (int i = 0; i < 4; i++) {
            delete animals[i];
        }
    }

    std::cout << "\n=== Deep copy test ===" << std::endl;
    {
        Dog dog1;
        dog1.setIdea(0, "Chase the mailman");

        Dog dog2 = dog1; // Запускаем конструктор копирования
        std::cout << "dog1 idea: " << dog1.getIdea(0) << std::endl;
        std::cout << "dog2 idea: " << dog2.getIdea(0) << std::endl;

        dog2.setIdea(0, "Sleep all day");
        // Проверим, что dog1 не изменился
        std::cout << "dog1 idea after dog2 changed: " << dog1.getIdea(0) << std::endl;
        std::cout << "dog2 idea after dog2 changed: " << dog2.getIdea(0) << std::endl;
    }

    return 0;
}