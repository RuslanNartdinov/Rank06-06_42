#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain(); // создаём новый объект Brain
}

Dog::Dog(const Dog &other) {
    std::cout << "Dog copy constructor called" << std::endl;
    this->brain = nullptr;
    *this = other; // воспользуемся оператором=
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other) {
        // Скопируем тип
        this->type = other.type;

        // Если у нас уже была память под brain, удаляем её
        if (this->brain)
            delete this->brain;

        // Создаём новый Brain и копируем содержимое
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain; // чистим динамическую память
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}

void Dog::setIdea(int index, const std::string &idea) {
    if (brain)
        brain->setIdea(index, idea);
}

const std::string &Dog::getIdea(int index) const {
    if (brain)
        return brain->getIdea(index);
    static std::string empty = "";
    return empty;
}