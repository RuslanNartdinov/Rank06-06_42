#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain default constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        ideas[i] = "Default idea";
    }
}

Brain::Brain(const Brain &other) {
    std::cout << "Brain copy constructor called" << std::endl;
    *this = other; // используем оператор=
}

Brain &Brain::operator=(const Brain &other) {
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int index, const std::string &idea) {
    if (index >= 0 && index < 100) {
        ideas[index] = idea;
    }
}

const std::string &Brain::getIdea(int index) const {
    static std::string empty = "";
    if (index >= 0 && index < 100)
        return ideas[index];
    return empty;
}