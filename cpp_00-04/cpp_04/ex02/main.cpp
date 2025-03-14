#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    // Animal* a = new Animal(); // Ошибка: нельзя создать экземпляр абстрактного класса!
    
    Animal* dog = new Dog();
    Animal* cat = new Cat();

    dog->makeSound(); // "Woof!"
    cat->makeSound(); // "Meow!"

    delete dog;
    delete cat;

    // Всё, что делали в ex01 для deep copy, тоже можно проверить
    // (с Cat, Dog и их brains).
    return 0;
}