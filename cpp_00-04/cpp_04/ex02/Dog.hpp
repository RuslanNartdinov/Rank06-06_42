#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
    Brain* brain; // динамический объект Brain

public:
    Dog();
    Dog(const Dog &other);
    Dog &operator=(const Dog &other);
    virtual ~Dog();

    virtual void makeSound() const;

    // Методы для работы с brain
    void setIdea(int index, const std::string &idea);
    const std::string &getIdea(int index) const;
};

#endif