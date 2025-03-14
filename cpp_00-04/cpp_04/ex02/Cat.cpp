#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat default constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(const Cat &other) {
    std::cout << "Cat copy constructor called" << std::endl;
    this->brain = nullptr;
    *this = other;
}

Cat &Cat::operator=(const Cat &other) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
        if (this->brain)
            delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
}

void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}

void Cat::setIdea(int index, const std::string &idea) {
    if (brain)
        brain->setIdea(index, idea);
}

const std::string &Cat::getIdea(int index) const {
    if (brain)
        return brain->getIdea(index);
    static std::string empty = "";
    return empty;
}