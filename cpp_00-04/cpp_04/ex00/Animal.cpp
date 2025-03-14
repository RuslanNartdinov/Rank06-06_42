#include "Animal.hpp"

// Конструктор по умолчанию
Animal::Animal() : type("Animal") {
    std::cout << "Animal default constructor called" << std::endl;
}

// Конструктор копирования
Animal::Animal(const Animal &other) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = other; 
}

// Оператор присваивания
Animal &Animal::operator=(const Animal &other) {
    std::cout << "Animal assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

// Виртуальный деструктор
Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

// Геттер
std::string Animal::getType() const {
    return this->type;
}

// Метод makeSound (общий, "неопределённый" звук)
void Animal::makeSound() const {
    std::cout << "Some generic animal sound..." << std::endl;
}