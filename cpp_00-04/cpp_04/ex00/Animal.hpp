#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
protected:
    std::string type;  // защищённое, чтобы наследники могли менять

public:
    // Канонические методы
    Animal();
    Animal(const Animal &other);
    Animal &operator=(const Animal &other);
    virtual ~Animal(); // виртуальный деструктор

    // Геттер
    std::string getType() const;

    // Виртуальный метод (но не чисто виртуальный)
    virtual void makeSound() const;
};

#endif